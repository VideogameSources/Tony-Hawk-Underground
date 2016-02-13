/*****************************************************************************
**																			**
**			              Neversoft Entertainment.			                **
**																		   	**
**				   Copyright (C) 2000 - All Rights Reserved				   	**
**																			**
******************************************************************************
**																			**
**	Project:		Skate5													**
**																			**
**	Module:			Gfx			 											**
**																			**
**	File name:		NxNewParticleMgr.h										**
**																			**
**	Created by:		3/24/03	-	SPG											**
**																			**
**	Description:	New parametric particle system manager					**
**																			**
*****************************************************************************/

#ifndef __GFX_NXNEWPARTICKEMGR_H__
#define __GFX_NXNEWPARTICKEMGR_H__

/*****************************************************************************
**							  	  Includes									**
*****************************************************************************/

#include <core/defines.h>
#include <core/hashtable.h>
#include <gfx/nxnewparticle.h>

/*****************************************************************************
**								   Defines									**
*****************************************************************************/


namespace Nx
{

/*****************************************************************************
**							Class Definitions								**
*****************************************************************************/

class CNewParticleManager
{
public:
	CNewParticleManager( void );
	virtual	~CNewParticleManager( void );

	CNewParticle*	CreateParticle( CParticleParams* params, bool generate_name = false );
	void			KillParticle( CNewParticle* p_particle );
	void			RenderParticles( void );
	void			UpdateParticles( void );
	void			Cleanup( void );

protected:

	Lst::HashTable< CNewParticle >	*mp_particle_table;

private:
	virtual	CNewParticle*	plat_create_particle( void );
};

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

/******************************************************************/
/*                                                                */
/*                                                                */
/******************************************************************/

} // namespace Nx

#endif	// __GFX_NXNEWPARTICKEMGR_H__


