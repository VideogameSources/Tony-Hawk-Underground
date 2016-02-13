##
## SN Systems C/C++ Startup Module
##
#	.include "defs.s"			# equates
#
#	.section .data
#wdbmsg:
#	.string	"Waiting for SN Debugger...\n"
#	.byte	0
#	.align	4
#
#	.section .init
#	.global	__start				# the only thing we need to export
#	
#__start:
#    lis     %r1, _stack_addr@h        	# set r1, r2, r13 as required by PPC EABI
#    ori     %r1, %r1, _stack_addr@l
#
#    lis     %r2, _SDA2_BASE_@h			# __SDA2_BASE_ is generated by linker */
#    ori     %r2, %r2, _SDA2_BASE_@l
#
#    lis     %r13, _SDA_BASE_@h			# _SDA_BASE_ is generated by linker
#    ori     %r13, %r13, _SDA_BASE_@l
#
#    bl      __init_hardware				# why do we have to call this?
#
#    li      %r0, -1               		# leave stack space for main params and lr stash
#    stwu    %r1, -8(%r1)               
#    stw     0, 4(%r1)                
#    stw     0, 0(%r1)
#
## Init the BSS sections to 0
#
#	lis		%r3,_f_bss@ha
#	addi	%r3,%r3,_f_bss@l
#	li		%r4,0
#	lis		%r5,_e_bss@ha
#	addi	%r5,%r5,_e_bss@l
#	subf	%r5,%r3,%r5
#	bl		memset
#
#	lis		%r3,_f_sbss@ha
#	addi	%r3,%r3,_f_sbss@l
#	li		%r4, 0
#	lis		%r5,_e_sbss@ha
#	addi	%r5,%r5,_e_sbss@l
#	subf	%r5,%r3,%r5
#	bl		memset
#
#	li		%r4,0
#	lis		%r5,0x8000			# use cached address space
#	stw		%r4,0x44(%r5)		# write it to the DBException structure in low mem
#
## OK, now check to see if debugging is enabled
#	li		%r29,0				# r29 == 0  =>  debugging not enabled
#	lis		%r6,BOOTINFO2_ADDR@ha
#	addi	%r6,%r6,BOOTINFO2_ADDR@l
#	lwz		%r6,0(%r6)			# get r6 = ptr to BOOTINFO2
#	cmpi	%cr0,%r6,0
#	beq		_skipdbg			# skip if BOOTINFO2 does not exist
#
#	lwz		%r3,OS_BI2_DEBUGFLAG_OFFSET(%r6)	# this will be 2 if we are debugging
#	cmpli	%cr0,%r3,2
#	blt		_skipdbg			# 2=>DDH, 3=>GDEV
#
#	bl		SNDebugInit			# can we reach it with a bl? May need an "li32 + blrl"
#	li		%r29,1
#
#_skipdbg:
#	bl		_ParseCmdLine		# must do it here (before OSInit) because it may adjust ARENAHI
#	mr		%r30,%r3
#	mr		%r31,%r4
#
#	bl      DBInit
#	bl      OSInit				# this will make the callback to EnableMetroTRKInterrupts
#
##    bl      __init_user			# C++ constructors. No, now handled in call to _main() from main()
#
#	cmpi	%cr0,%r29,0
#	beq		_sktr
#
#	lis		%r3,wdbmsg@h
#	ori		%r3,%r3,wdbmsg@l
#	bl		OSReport
#
#	mfmsr	%r5
#	lis		%r4,(~MSR_EE)@h		# li32 r4,MSR_EE (=0xFFFF7FFF)
#	ori		%r4,%r4,(~MSR_EE)@l
#	and		%r4,%r5,%r4			# disable external ints (so SRR stays safe)
#	mtmsr	%r4
#	sync						# make sure ints are off before next bit of code
#	ori		%r5,%r5,MSR_BE		# and set BRANCH TRACE bit (will go of after bl main)
#	mtspr	spr_srr1,%r5
#
#	lis		%r4,_sktr@h
#	ori		%r4,%r4,_sktr@l		# li32	%r4,_sktr
#	mtspr	spr_srr0,%r4
#	rfi
#
#_sktr:
#	bl      pre_main
#
### Fill stack with 55.
##
##	lis		%r4,_stack_end@ha
##	addi	%r4,%r4,_stack_end@l
##	li		%r5,0x55
##	lis		%r6,_stack_addr@ha
##	addi	%r6,%r6,_stack_addr@l
##	subf	%r6,%r4,%r6
##	li		%r6,0x80
##	subf	%r6,%r6,%r4
##	bl		memset
#
#
#
#
#	mr		%r3,%r30			# restore argc
#	mr		%r4,%r31			# and argv
#	bl      main				# so we can call main()
#    bl      post_main
#    b       exit
#
#
## process command line
#_ParseCmdLine:
#	lis		%r6,BOOTINFO2_ADDR@ha
#	addi	%r6,%r6,BOOTINFO2_ADDR@l
#	lwz		%r5,0(%r6)			# get r6 = ptr to BOOTINFO2
#	cmpi	%cr0,%r5,0
#	bne		_gargs
#
#_noargs:
#    li      %r3,0
#    li      %r4,0
#	blr
#
#_gargs:
#	lwz		%r6,OS_BI2_ARGOFFSET_OFFSET(%r5)	#argument offset
#	cmpi	%cr0,%r6,0
#	beq		_noargs				# no arguments
#	add		%r6,%r5,%r6			# argument start
#
#	lwz		%r3,0(%r6)			# get argc
#	cmpi	%cr0,%r3,0
#	beq		_noargs				# shouldn't happen
#
#	addi	%r4,%r6,4			# argv
#	mtctr	%r3
#_lp:
#	addi	%r6,%r6,4
#	lwz		%r7,0(%r6)
#	add		%r7,%r7,%r5
#	stw		%r7,0(%r6)
#	bdnz	_lp
#
## set ARENAHI to be *below* the arguments
#	lis		%r5,ARENAHI_ADDR@ha
#	addi	%r5,%r5,ARENAHI_ADDR@l
#	clrrwi	%r7,%r4,5			# align it by 32bytes
#	stw		%r7,0(%r5)
#
#	blr
#
## Bill's hack Yuk Yuk
#
#	.section .data
#	.extern read
#	.extern pre_main
#	.extern main
#	.extern __mod2i
#LinkFiddle:
#	.long read
#	.long __mod2i

