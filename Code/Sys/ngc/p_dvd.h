/*****************************************************************************
**																			**
**					   	  Neversoft Entertainment							**
**																		   	**
**				   Copyright (C) 1999 - All Rights Reserved				   	**
**																			**
******************************************************************************
**																			**
**	Project:		Skate3      											**
**																			**
**	Module:			SYS			  											**
**																			**
**	Created:		08/30/01	dc											**
**																			**
**	File name:		p_dvd.h		               								**
**																			**
**	Description:	Gamecube DVD file acceess routines         				**
**																			**
*****************************************************************************/

#ifndef __P_DVD_H
#define __P_DVD_H

/*****************************************************************************
**							  	  Includes									**
*****************************************************************************/

#include <dolphin.h>
#include "p_file.h"

/*****************************************************************************
**								   Defines									**
*****************************************************************************/

/*****************************************************************************
**							Class Definitions								**
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

int DVDFileAccess( NsFile* p_file, NsFileAccessType access_type, ... );
void DVDWaitAsync( void );
void DVDCheckAsync( void );
int	DVDError( void );

/*****************************************************************************
**								Inline Functions							**
*****************************************************************************/

#endif // __P_DVD_H

