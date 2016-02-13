///////////////////////////////////////////////////////////////////////////////
// p_NxViewport.cpp

#include 	"Gfx/NGC/p_NxViewport.h"

namespace Nx
{

////////////////////////////////////////////////////////////////////////////////////
// Here's a machine specific implementation of CViewport

/******************************************************************/
/*                                                                */
/*                                                                */
/******************************************************************/

CNgcViewport::CNgcViewport()
{
}

/******************************************************************/
/*                                                                */
/*                                                                */
/******************************************************************/

CNgcViewport::CNgcViewport( const Mth::Rect* rect, Gfx::Camera* cam) :
	CViewport(rect, cam)
{
}

/******************************************************************/
/*                                                                */
/*                                                                */
/******************************************************************/

CNgcViewport::~CNgcViewport()
{
}

/////////////////////////////////////////////////////////////////////////////////////
// Private classes
//

} // Namespace Nx  			
				
				

