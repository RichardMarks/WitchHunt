
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

DEFABILITY(poa_FerociousStrike)
{ 
 string strResults = "";
 char sResults [255];
 int iDamage;
 // check for MP
 
 
 int iRandAtkMod = Common :: random (1, 10); //rand () % 15;
 int iRandMod    = Common :: random (1, 20); //1 + rand () % (20 - 1);
 int iRandStrMod = Common :: random (5, iRandMod); //rand () % iRandMod;
   
  
 
 if (user->m_iMp >= 20)
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
   user->takeMp (20);
   
   // roll a random for a result
   int x = rand() % 3;
   switch (x)
   {
    case 0:
           {
            sprintf (sResults, "%s attacks %s with Ferocious Strike\n\tand inflicts %d damage.", user->m_strAlias.c_str(), target.m_strAlias.c_str(), iDamage);
           }break;
    case 1:
           {
            sprintf (sResults, "%s attacks %s with a flurry from Ferocious Strike\n\tand inflicts %d damage.", user->m_strAlias.c_str(), target.m_strAlias.c_str(), iDamage);
           }break;
    case 2:
           {
            sprintf (sResults, "%s swings at %s with Ferocious Strike\n\tand causes %d damage.", user->m_strAlias.c_str(), target.m_strAlias.c_str(), iDamage);
           }break;
   } // end switch case
   
  }
  else  //  we missed
  {
   sprintf (sResults, "%s attacks %s with Ferocious Strike and misses.", user->m_strAlias.c_str(), target.m_strAlias.c_str());
  }
 }
 else // not enough MP
 {
  sprintf (sResults, "%s attempts to use Ferocious Strike but doesnt have enough MP", user->m_strAlias.c_str());
 }
  
  strResults += sResults;
 
  return strResults;
}

