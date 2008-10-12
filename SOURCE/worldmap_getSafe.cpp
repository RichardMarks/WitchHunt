
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
 
 // returns the 'safe' flag of the location that the x/y lies in
eMapFlags WORLDMAP :: getSafe (int iXpos, int iYpos)
{
 for (SEARCH_ITER_CONFIG)
 {
  int iLeft   = (*iter)->m_iXpos [0];
  int iTop    = (*iter)->m_iYpos [0];
  int iRight  = (*iter)->m_iXpos [1];
  int iBottom = (*iter)->m_iYpos [1];
  
  if (x_pointWithin (iXpos, iYpos, iLeft, iTop, iRight, iBottom) == true)
  {
   // there is a location here
   return (*iter)->m_eSafe;
  }
 }
 return eMapInvalid;
}

 // returns the 'safe' flag of the location
eMapFlags WORLDMAP :: getSafeFromIndex (int index)
{
 return m_vpkLocations.at (index)->m_eSafe;
}
 
