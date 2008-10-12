
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

DEFABILITY(poa_VampBite)
{
 string strResults = "";
 char sResults [255];
 
 int iDamage;
 int iHealth;
 
 int iRandAtkMod = Common :: random (1, 5); //rand () % 15;
 int iRandMod    = Common :: random (1, 50); //1 + rand () % (20 - 1);
 int iRandStrMod = Common :: random (15, iRandMod); //rand () % iRandMod;
 
 // check for MP
 if (user->m_iMp >= 65)
 {
  //check for a hit .. 
  if ((user->m_iPhysicalAtk + iRandAtkMod) >= target.m_iPhysicalDef)
  {
   iDamage = ((user->m_iStrength + iRandStrMod) - target.m_iPhysicalDef);
   // check for negative dmg
   if (iDamage < 0)
   {
    iDamage = 0;
   }
   // assign damage
   target.takeDamage (iDamage);
   user->takeMp (65);
   
   // check for hp gain
   if ((iDamage % 2) == 0)
   {
    iHealth = iDamage / 2;
   }
   else 
   {
    int x = iDamage % 2;
    int y = iDamage;
    y = y - x;
    iHealth = y / 2;
   }
   
   user->giveHp (iHealth);
   
   // roll a random for a result
   int x = rand() % 3;
   switch (x)
   {
    case 0:
           {
            sprintf (sResults, "%s uses Vamp Bite on %s draining %d damage and gaining %d health.", user->m_strAlias.c_str(), target.m_strAlias.c_str(), iDamage, iHealth);
           }break;
    case 1:
           {
            sprintf (sResults, "%s attacks %s with Vamp Bite causing %d damage and gaining %d health.", user->m_strAlias.c_str(), target.m_strAlias.c_str(), iDamage, iHealth);
           }break;
    case 2:
           {
            sprintf (sResults, "%s sinks his teeth into %s with Vamp Bite and causes %d damage and gains %d health.", user->m_strAlias.c_str(), target.m_strAlias.c_str(), iDamage, iHealth);
           }break;
   } // end switch case
   
  }
  else  //  we missed
  {
   sprintf (sResults, "%s attacks %s with Vamp Bite and misses.", user->m_strAlias.c_str(), target.m_strAlias.c_str());
  }
 }
 else // not enough MP
 {
  sprintf (sResults, "%s attempts to use Vamp Bite but doesnt have enough MP", user->m_strAlias.c_str());
 }
  
  
 strResults += sResults;
 
 return strResults;
}

