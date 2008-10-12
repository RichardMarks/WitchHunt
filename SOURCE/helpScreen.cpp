
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

////////////////////////////////////////////////////////////////////////////////
// helpScreen.cpp
////////////////////////////////////////////////////////////////////////////////

// include the project header
//#include "project.h"

void helpScreen ()
{
 Common :: clearscreen (PRINT_VERTICAL_OFFSET);
 
 cout << PRINT_OFFSET
      << "Valid Commands:" << OFFSET_ENDL << OFFSET_ENDL
      << "N, S, E, W, NW, NE, SW, SE" << OFFSET_ENDL 
      << "NORTH, SOUTH, EAST, WEST" << OFFSET_ENDL 
      << "NORTHWEST, NORTHEAST, SOUTHWEST, SOUTHEAST" << OFFSET_ENDL 
      << "MENU, QUIT, EXIT, BYE, HELP" << OFFSET_ENDL 
      << "LISTI, LISTE, LISTA" << OFFSET_ENDL << OFFSET_ENDL;
 {
  cout << OFFSET_ENDL;
  for (int n = 0; n < sizeof (S_iTerrainType) / sizeof (int); n++)
  {
   cout << char(34) << char(S_iTerrainType [n]) << char(34)
        << char(32) << vptMasterMapList.at ( S_iTerrainID [n] )->strDesc
        << OFFSET_ENDL;
  }
 } 
      
 cout << "Read Manual.txt for more details." << OFFSET_ENDL;
}

