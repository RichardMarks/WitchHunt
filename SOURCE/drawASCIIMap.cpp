
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


#include "project.h"
 
void drawASCIIMap (unsigned char* mapdata[], int iColumns, int iRows)
{
 // set corners
 mapdata [0][0]                    = 201;
 mapdata [0][iColumns - 1]         = 187;
 mapdata [iRows - 1][0]            = 200;
 mapdata [iRows - 1][iColumns - 1] = 188;
 
 // set columns
 { 
  for (int col = 1; col < iColumns - 1; col++)
  { 
   mapdata [[0][col]         = 205; 
   mapdata [[iRows - 1][col] = 205; 
  } 
 }
 
 // set rows
 { 
  for (int row = 1; row < iRows - 1; row++)
  { 
   mapdata [row][0]            = 186; 
   mapdata [row][iColumns - 1] = 186; 
  } 
 }
 
 // set hero smiley
 mapdata [int(iRows / 2)][int(iColumns / 2)] = 1;
 
 {
  cout << PRINT_OFFSET << PRINT_OFFSET;
  
  for (int rows = 0; rows < iRows; rows++)
  {
   for (int cols = 0; cols < iColumns; cols++)
   {
    cout << mapdata [rows][cols];
   }
   cout << OFFSET_ENDL;
  }
  
 }
 
}

