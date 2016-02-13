/*****************************************************************************
**																			**
**			              Neversoft Entertainment	                        **
**																		   	**
**				   Copyright (C) 1999 - All Rights Reserved				   	**
**																			**
******************************************************************************
**																			**
**	Project:		Sys Library												**
**																			**
**	Module:			Memory Management (Mem)									**
**																			**
**	Created:		03/20/00	-	mjb										**
**																			**
**	File name:		sys/mem/memdbg.h										**
**																			**
*****************************************************************************/

#ifndef	__SYS_MEM_MEMDBG_H
#define	__SYS_MEM_MEMDBG_H

/*****************************************************************************
**							  	  Includes									**
*****************************************************************************/

namespace Mem
{

/*****************************************************************************
**								   Defines									**
*****************************************************************************/

#if defined( __PLAT_WN32__ ) || defined( __PLAT_XBOX__ )
static const uint64 vALLOCATED_BLOCK = 0x0101010101010101i64;
static const uint64 vFREE_BLOCK 	 = 0x0303030303030303i64;
#else
static const uint64 vALLOCATED_BLOCK = 0x0101010101010101LL;
static const uint64 vFREE_BLOCK 	 = 0x0303030303030303LL;
#endif	// __PLAT_WN32__

#ifdef __NOPT_MEM_DEBUG__
	
#define MemDbg_AllocateBlock(_header)	_header->DbgAllocateBlock()
#define MemDbg_FreeBlock(_header)		_header->DbgFreeBlock()

#else // !__NOPT_MEM_DEBUG__

#define MemDbg_AllocateBlock(_header)
#define MemDbg_FreeBlock(_header)

#endif

/*****************************************************************************
**							     Type Defines								**
*****************************************************************************/

/*****************************************************************************
**							 Private Declarations							**
*****************************************************************************/

/*****************************************************************************
**							  Private Prototypes							**
*****************************************************************************/

/*****************************************************************************
**							  Public Declarations							**
*****************************************************************************/

/*****************************************************************************
**							   Public Prototypes							**
*****************************************************************************/
   
/*****************************************************************************
**								Inline Functions							**
*****************************************************************************/

} // namespace Mem

#endif  // __SYS_MEM_MEMDBG_H								
