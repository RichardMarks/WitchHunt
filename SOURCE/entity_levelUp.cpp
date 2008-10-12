
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

void ENTITY :: levelUp (int x)
{
 #ifdef DEBUG_BUILD
  cerr << "DEBUG: levelUp() called by " << m_strAlias << endl;
 #endif 
 if( x == 0) // player is leveling up
 {
  giveHp           (9999);
  giveMp           (9999);
  giveMaxHp        (27);
  giveMaxMp        (21);
  giveStrength     (8);
  giveVitality     (5);
  givePhysicalAtk  (6);
  giveMagickalAtk  (6);
  givePhysicalDef  (4);
  giveMagickalDef  (4);
  giveLevel        (1);
 
  cout << PRINT_OFFSET 
      << m_strAlias 
      << " gains a level!" 
      << endl;
 }
 else // enemies are leveling up 
 {
  // these hardcoded numbers are changeable
  // they are BASE level up stats. 
  giveMaxHp         ((x - 1) * 19);
  giveMaxMp         ((x - 1) * 16);
  giveHp            (9999);
  giveMp            (9999);
  giveStrength      ((x - 1) * 6);
  giveVitality      ((x - 1) * 5);
  givePhysicalAtk   ((x - 1) * 6);
  giveMagickalAtk   ((x - 1) * 6);
  givePhysicalDef   ((x - 1) * 5);
  giveMagickalDef   ((x - 1) * 5);
  giveLevel         (x - 1);
 }
}

