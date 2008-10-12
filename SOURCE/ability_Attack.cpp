
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

DEFABILITY(poa_Attack)
{
 string strResults = "";
 char sResults [255];
 
 int iDamage;
 
 int iRandAtkMod = Common :: random (1, 15); //rand () % 15;
 int iRandMod    = Common :: random (1, 20); //1 + rand () % (20 - 1);
 int iRandStrMod = Common :: random (1, iRandMod); //rand () % iRandMod;
 
 //check for a hit .. 
 if ((user->m_iPhysicalAtk + iRandAtkMod) >= target.m_iPhysicalDef)
 {
  
  
  // OFFENDING CODE:
  // Rafael, You are dividing by zero, causing the crash!
  // RM 2:56 PM 03-09-07
  iDamage = ( (user->m_iStrength + iRandStrMod) - target.m_iPhysicalDef);
  
  
  
  
  // check for negative dmg
  if (iDamage < 0)
  {
   iDamage = 0;
  }
  // assign damage
  target.takeDamage (iDamage);
  
  // roll a random for a result
  int x = rand() % 3;
  switch (x)
  {
   case 0:
          {
           sprintf (sResults, "%s attacks %s violently and inflicts %d damage.", user->m_strAlias.c_str(), target.m_strAlias.c_str(), iDamage);
          }break;
   case 1:
          {
           sprintf (sResults, "%s attacks %s and inflicts %d damage.", user->m_strAlias.c_str(), target.m_strAlias.c_str(), iDamage);
          }break;
   case 2:
          {
           sprintf (sResults, "%s attacks %s and grazes his arm causing %d damage.", user->m_strAlias.c_str(), target.m_strAlias.c_str(), iDamage);
          }break;
  } // end switch case
  
 }
 else  //  we missed
 {
  sprintf (sResults, "%s attacks %s and misses.", user->m_strAlias.c_str(), target.m_strAlias.c_str());
 }
 
 // prepare results and return
 strResults += sResults;
 
 return strResults;
}

/*
DEFABILITY(poa_Attack)
{
 string strResults = "";
 char sResults [255];
 
 int iDamage;
 
 //check for a hit .. 
 if ((user->m_iPhysicalAtk + rand() % 15) >= target.m_iPhysicalDef)
 {
  
  // OFFENDING CODE:
  // Rafael, You are dividing by zero, causing the crash!
  // RM 2:56 PM 03-09-07
  iDamage = ((user->m_iStrength + rand() % (rand() % 20)) - target.m_iPhysicalDef);
  
  
  
  
  // check for negative dmg
  if (iDamage < 0)
  {
   iDamage = 0;
  }
  // assign damage
  target.takeDamage (iDamage);
  
  // roll a random for a result
  int x = rand() % 3;
  switch (x)
  {
   case 0:
          {
           sprintf (sResults, "%s attacks %s violently and inflicts %d damage.", user->m_strAlias.c_str(), target.m_strAlias.c_str(), iDamage);
          }break;
   case 1:
          {
           sprintf (sResults, "%s attacks %s and inflicts %d damage.", user->m_strAlias.c_str(), target.m_strAlias.c_str(), iDamage);
          }break;
   case 2:
          {
           sprintf (sResults, "%s attacks %s and grazes his arm causing %d damage.", user->m_strAlias.c_str(), target.m_strAlias.c_str(), iDamage);
          }break;
  } // end switch case
  
 }
 else  //  we missed
 {
  sprintf (sResults, "%s attacks %s and misses.", user->m_strAlias.c_str(), target.m_strAlias.c_str());
 }
 
 // prepare results and return
 strResults += sResults;
 
 return strResults;
}
*/
