
/*
	Project WiTCHHUNT: A complete ASCII Mini RPG engine/game developed in 1.5 months!
	Copyright (C) 2007 - 2008 CCPS Solutions, Richard Marks, Rafael Hermosillo, Jeff Stagg

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License along
	with this program; if not, write to the Free Software Foundation, Inc.,
	51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

//#include "worldmap_libraryheader.h"

WORLDMAPAREA :: WORLDMAPAREA ()
{
 m_ID                 = 0;
 m_strName            = "";
 m_strDescription [0] = "";
 m_strDescription [1] = "";
 m_iXpos [0]          = 0;
 m_iYpos [0]          = 0;
 m_iXpos [1]          = 0;
 m_iYpos [1]          = 0;
 m_iLayer             = 0;
 m_eSafe              = eMapInvalid;
 m_eSolid             = eMapInvalid;
 
 #ifdef DEBUG_BUILD
  cerr << "DEBUG: instance of WORLDMAPAREA class created" << endl;
 #endif 
}

WORLDMAPAREA :: ~WORLDMAPAREA ()
{
 #ifdef DEBUG_BUILD
  cerr << "DEBUG: instance of WORLDMAPAREA class destroyed" << endl;
 #endif
}

// constructor
WORLDMAP :: WORLDMAP ()
{
 m_strExportDir = "";
 #ifdef DEBUG_BUILD
  cerr << "DEBUG: instance of WORLDMAP class created" << endl;
 #endif 
}

// destructor
WORLDMAP :: ~WORLDMAP ()
{
 vector<WORLDMAPAREA*>::iterator iter;
 for (iter = m_vpkLocations.begin (); iter < m_vpkLocations.end (); iter++)
 {
  if ( (*iter) )
   delete (*iter);
  (*iter) = NULL;
  
  //m_vpkLocations.erase (iter);
 }
 #ifdef DEBUG_BUILD
  cerr << "DEBUG: instance of WORLDMAP class destroyed" << endl;
 #endif
}

 // returns true if the x/y lies within the bounds of left,top,right,bottom
bool WORLDMAP :: x_pointWithin (int iXpos, int iYpos, int iLeft, int iTop, int iRight, int iBottom)
{
 if ( (iXpos >= iLeft) && (iXpos <= iRight) && (iYpos >= iTop) && (iYpos <= iBottom) )
  return true;
 return false; 
}








 // returns a location element
WORLDMAPAREA* WORLDMAP :: getElement (int index)
{
 return m_vpkLocations.at (index);
}
 
 // returns size of the maplist
int WORLDMAP :: getLocationCount ()
{
 return int(m_vpkLocations.size ());
}








 
