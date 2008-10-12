
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

DEFABILITY(noa_Slash)
{
 string strResults = "";
 char sResults [255];
 
 int iDamage;
 
 // check for MP
 if (user->m_iMp >= 42)
 {
  //check for a hit .. 
  if ((user->m_iPhysicalAtk + Common :: random (1, 10) ) >= target.m_iPhysicalDef)
  {
   iDamage = user->m_iStrength + Common :: random (1, 20);
   // check for negative dmg
   if (iDamage < 0)
   {
    iDamage = 0;
   }
   // assign damage
   target.takeDamage (iDamage);
   user->takeMp (42);
   
   // roll a random for a result
   int x = rand() % 3;
   switch (x)
   {
    case 0:
           {
            sprintf (sResults, "%s attacks %s with a Slash and inflicts %d damage.", user->m_strAlias.c_str(), target.m_strAlias.c_str(), iDamage);
           }break;
    case 1:
           {
            sprintf (sResults, "%s uses Slash on %s and inflicts %d damage.", user->m_strAlias.c_str(), target.m_strAlias.c_str(), iDamage);
           }break;
    case 2:
           {
            sprintf (sResults, "%s swings at %s with a powerful Slash and causes %d damage.", user->m_strAlias.c_str(), target.m_strAlias.c_str(), iDamage);
           }break;
   } // end switch case
   
  }
  else  //  we missed
  {
   sprintf (sResults, "%s attacks %s with Slash and misses.", user->m_strAlias.c_str(), target.m_strAlias.c_str());
  }
 }
 else // not enough MP
 {
  sprintf (sResults, "%s attempts to use Slash but doesnt have enough MP", user->m_strAlias.c_str());
 }
  
  
 strResults += sResults;
 
 return strResults;
}

