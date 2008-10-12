
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

// add an instance of WORLDMAPAREA to the map
int WORLDMAP :: addLocation (WORLDMAPAREA* pkLocation)
{
 m_vpkLocations.push_back (pkLocation);
 return int(m_vpkLocations.size ());
}


 // add a location to the map; returns the index of the location
int WORLDMAP :: addLocation (int iLayer, int iLeft, int iTop, int iRight, int iBottom, 
							 std::string strName, std::string strPrimaryDescription, std::string strSecondaryDescription, eMapFlags eSafe, eMapFlags eSolid)
{
 #ifdef DEBUG_BUILD
  cerr << "DEBUG: addLocation() called" << endl;
 #endif

 WORLDMAPAREA* ptArea         = new WORLDMAPAREA ();
 
 ptArea->m_iLayer             = iLayer;

 if (m_vpkLocations.empty () == true)
 {
  ptArea->m_ID                 = 0;
 }
 else
 {
  ptArea->m_ID                 = static_cast<unsigned int>(m_vpkLocations.size ());
 }

 ptArea->m_strName            = strName;
 ptArea->m_strDescription [0] = strPrimaryDescription;
 ptArea->m_strDescription [1] = strSecondaryDescription;
 ptArea->m_iXpos [0]          = iLeft;
 ptArea->m_iYpos [0]          = iTop;
 ptArea->m_iXpos [1]          = iRight;
 ptArea->m_iYpos [1]          = iBottom;
 ptArea->m_eSafe              = eSafe;
 ptArea->m_eSolid             = eSolid;
 
 #ifdef DEBUG_BUILD
  cerr << "DEBUG: \t m_iLayer\t\t" << ptArea->m_iLayer << endl;
  cerr << "DEBUG: \t m_ID\t\t" << ptArea->m_ID << endl;
  cerr << "DEBUG: \t m_strName\t\t" << ptArea->m_strName << endl;
  cerr << "DEBUG: \t m_strDescription[0]\t\t" << ptArea->m_strDescription[0] << endl;
  cerr << "DEBUG: \t m_strDescription[1]\t\t" << ptArea->m_strDescription[1] << endl;
  cerr << "DEBUG: \t m_iXpos[0]\t\t" << ptArea->m_iXpos[0] << endl;
  cerr << "DEBUG: \t m_iYpos[0]\t\t" << ptArea->m_iYpos[0] << endl;
  cerr << "DEBUG: \t m_iXpos[1]\t\t" << ptArea->m_iXpos[1] << endl;
  cerr << "DEBUG: \t m_iYpos[1]\t\t" << ptArea->m_iYpos[1] << endl;
  cerr << "DEBUG: \tpush the WORLDMAPAREA instance onto WORLDMAP instance vector" << endl;
 #endif
 
 m_vpkLocations.push_back (ptArea);
 
 #ifdef DEBUG_BUILD
  cerr << "DEBUG: \tpushed WORLDMAPAREA instance into WORLDMAP instance" << endl;
 #endif
 
 return int(m_vpkLocations.size ());
}
 
