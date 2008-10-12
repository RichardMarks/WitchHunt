
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

//#include "entity_libraryheader.h"

void ENTITY :: navigate (eMotionDirection eDir)
{
 string feedback = "";
 
 if (m_strClass != "Monster")
 {
  feedback = m_strAlias + " is too tired to move...\n";
 }
  
 if (m_iVitality > 0)
 {
  switch (eDir)
  {
   case eNorth:    {m_iYpos--;}break;
   case eSouth:    {m_iYpos++;}break;
   case eEast:     {m_iXpos++;}break;
   case eWest:     {m_iXpos--;}break;
   case eNorthWest:{m_iYpos--; m_iXpos--;}break;
   case eNorthEast:{m_iYpos--; m_iXpos++;}break;
   case eSouthWest:{m_iYpos++; m_iXpos--;}break;
   case eSouthEast:{m_iYpos++; m_iXpos++;}break;
  }

  if (m_iYpos < 0) m_iYpos = C_GAMEWORLD_SIZE;
  if (m_iXpos < 0) m_iXpos = C_GAMEWORLD_SIZE;
  if (m_iXpos > C_GAMEWORLD_SIZE) m_iXpos = 0;
  if (m_iYpos > C_GAMEWORLD_SIZE) m_iYpos = 0;
 }
 else
 {
  cout << feedback;
  Common :: pause (center_press_return);
 }  
}

