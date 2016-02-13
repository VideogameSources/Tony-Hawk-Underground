///////////////////////////////////////////////////////////////////////////////////////
// nxflags.h - flag definitions that used to be in nxplugin
//

#ifndef	__GFX_NXFLAGS_H
#define	__GFX_NXFLAGS_H


// Face flags
enum
{
	mFD_SKATABLE			= 0x00000001,
	mFD_NOT_SKATABLE		= 0x00000002,
	mFD_WALL_RIDABLE		= 0x00000004,
	mFD_VERT				= 0x00000008,
	mFD_NON_COLLIDABLE		= 0x00000010,
	mFD_DECAL				= 0x00000020,
	mFD_TRIGGER				= 0x00000040,
	mFD_CAMERA_COLLIDABLE	= 0x00000080,
	mFD_NO_SKATER_SHADOW	= 0x00000100,
	mFD_SKATER_SHADOW		= 0x00000200,
	mFD_NO_SKATER_SHADOW_WALL=0x00000400,
	mFD_UNDER_OK			= 0x00000800,
    mFD_INVISIBLE			= 0x00001000,
	mFD_CASFACEFLAGSEXIST   = 0x00002000,
	mFD_PASS_1_DISABLED     = 0x00004000,
	mFD_PASS_2_ENABLED      = 0x00008000,
	mFD_PASS_3_ENABLED      = 0x00010000,
	mFD_PASS_4_ENABLED      = 0x00020000,
	mFD_RENDER_SEPARATE		= 0x00040000,
	mFD_LIGHTMAPPED			= 0x00080000,
   	mFD_NON_WALL_RIDABLE	= 0x00100000,
	mFD_NON_CAMERA_COLLIDABLE = 0x00200000,
	mFD_EXPORT_COLLISION	= 0x00400000,
};

// Object flags
enum
{
	mSD_INVISIBLE			= 0x0001,	// Invisible in primary viewport
	mSD_NON_COLLIDABLE		= 0x0002,
	mSD_KILLED				= 0x0004,
	mSD_DONT_FOG			= 0x0008,
	mSD_ALWAYS_FACE			= 0x0010,
	mSD_NO_SKATER_SHADOW	= 0x0020,	// This is set at runtime for sectors with every face flagged mFD_SKATER_SHADOW.
	mSD_INVISIBLE2			= 0x0040,	// Invisible in secondary viewport (Mick)
	mSD_OCCLUDER			= 0x0080,	// Occluder (it's a single plane that hides stuff)
	mSD_CLONE				= 0x8000,	// Cloned collision object (Garrett)
};


// Material flags
enum ETerrainType
{
	// If you change any of these,
	// don't forget to change terrain.q
	// to match!
	vTERRAIN_DEFAULT, 	
	vTERRAIN_CONCSMOOTH,	
	vTERRAIN_CONCROUGH,	
	vTERRAIN_METALSMOOTH,
	vTERRAIN_METALROUGH,	
	vTERRAIN_METALCORRUGATED,	
	vTERRAIN_METALGRATING,
	vTERRAIN_METALTIN,	
	vTERRAIN_WOOD,		
	vTERRAIN_WOODMASONITE,
	vTERRAIN_WOODPLYWOOD,
	vTERRAIN_WOODFLIMSY,	
	vTERRAIN_WOODSHINGLE,
	vTERRAIN_WOODPIER,	
	vTERRAIN_BRICK,		
	vTERRAIN_TILE,		
	vTERRAIN_ASPHALT,	
	vTERRAIN_ROCK,		
	vTERRAIN_GRAVEL,		
	vTERRAIN_SIDEWALK,	
	vTERRAIN_GRASS,		
	vTERRAIN_GRASSDRIED,	
	vTERRAIN_DIRT,		
	vTERRAIN_DIRTPACKED,	
	vTERRAIN_WATER,		
	vTERRAIN_ICE,		
	vTERRAIN_SNOW,		
	vTERRAIN_SAND,		
	vTERRAIN_PLEXIGLASS,	
	vTERRAIN_FIBERGLASS,	
	vTERRAIN_CARPET,		
	vTERRAIN_CONVEYOR,	
	vTERRAIN_CHAINLINK,
	vTERRAIN_METALFUTURE,
	vTERRAIN_GENERIC1,	
	vTERRAIN_GENERIC2,
	vTERRAIN_WHEELS, // K: Used only by the skateboard wheels, as a means of identifying them so their color can be changed.	
	vTERRAIN_WETCONC,
	vTERRAIN_METALFENCE,
	vTERRAIN_GRINDTRAIN,
	vTERRAIN_GRINDROPE,
	vTERRAIN_GRINDWIRE,
	vTERRAIN_GRINDCONC,			// New as of 7/29/03
	vTERRAIN_GRINDROUNDMETALPOLE,
	vTERRAIN_GRINDCHAINLINK,
	vTERRAIN_GRINDMETAL,
	vTERRAIN_GRINDWOODRAILING,
	vTERRAIN_GRINDWOODLOG,
	vTERRAIN_GRINDWOOD,
	vTERRAIN_GRINDPLASTIC,
	vTERRAIN_GRINDELECTRICWIRE,
	vTERRAIN_GRINDCABLE,
	vTERRAIN_GRINDCHAIN,
	vTERRAIN_GRINDPLASTICBARRIER,
	vTERRAIN_GRINDNEONLIGHT,
	vTERRAIN_GRINDGLASSMONSTER,
	vTERRAIN_GRINDBANYONTREE,
	vTERRAIN_GRINDBRASSRAIL,
	vTERRAIN_GRINDCATWALK,
	vTERRAIN_GRINDTANKTURRET,

	// If anyone adds a new terrain so that vNUM_TERRAIN_TYPES > 64, let Steve G know
	vNUM_TERRAIN_TYPES
};


#endif

