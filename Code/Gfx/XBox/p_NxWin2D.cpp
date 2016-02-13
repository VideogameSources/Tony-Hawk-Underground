///////////////////////////////////////////////////////////////////////////////
// p_NxWin2D.cpp

#include 	"Gfx/Xbox/p_NxWin2D.h"

namespace Nx
{

/////////////////////////////////////////////////////////////////////////////////////
// Private classes
//

/******************************************************************/
/*                                                                */
/*                                                                */
/******************************************************************/
CXboxWindow2D::CXboxWindow2D( int x, int y, int width, int height) : CWindow2D( x, y, width, height )
{
	plat_update_engine();
}



/******************************************************************/
/*                                                                */
/*                                                                */
/******************************************************************/
CXboxWindow2D::~CXboxWindow2D()
{
}



/******************************************************************/
/*                                                                */
/*                                                                */
/******************************************************************/
void CXboxWindow2D::plat_update_engine()
{
}



/******************************************************************/
/*                                                                */
/*                                                                */
/******************************************************************/
void CWindow2DManager::s_plat_alloc_window2d_pool()
{
	for( int i = 0; i < vMAX_WINDOW_INSTANCES; i++ )
	{
	   	CXboxWindow2D *p_window = new CXboxWindow2D;
		p_window->mp_next	= sp_window_list;
		sp_window_list		= p_window;
	}
}

} // Namespace Nx  			
				
				
