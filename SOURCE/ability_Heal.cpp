
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

//#include "ability_header.h"

DEFABILITY(poa_Heal)
{
 string strResults = "";
 char sResults [255];
 
 int iHealth;
 
 // check for mana
 if (user->m_iMp >= 20)
 {
  iHealth = user->m_iMagickalAtk + (Common :: random (1, 10 * user->m_iLevel));
  user->takeMp(20);
  user->giveHp(iHealth);
  
  // roll for result
  int x = rand() % 3;
  switch (x)
  {
   case 0:
          { 
           sprintf (sResults, "%s casts Heal and gains %d health.", user->m_strAlias.c_str(), iHealth);
          }break;
   case 1:
          {
           sprintf (sResults, "A blue light shines over %s as %s regains %d health.", user->m_strAlias.c_str(), user->m_strAlias.c_str(), iHealth);
          }break;
   case 2:
          {
           sprintf (sResults, "%s is filled with the divine spirit and gains %d health", user->m_strAlias.c_str(), iHealth);
          }break;
  } // end switch case
 }
 else // not enough mana
 {
  sprintf (sResults, "%s attempts to cast Heal but doesnt have enough MP", user->m_strAlias.c_str());
 }
  
 strResults += sResults;
 
 return strResults;
}

