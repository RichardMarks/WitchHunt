
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

DEFABILITY(poa_Curse)
{
  string strResults = "";
 char sResults [255];
 
 int iDamage;
 
 // check for MP
 if (user->m_iMp >= 99)
 {
  int iCount = rand () % 4; // 0 - 3 times it can hit
  
  if (iCount == 0) // miss!
  {
   sprintf (sResults, "%s attempted to use Curse but it failed", user->m_strAlias.c_str());
  }
  else // loop for the number of times we hit for
  {
   user->takeMp (99);
   int x; 
   for (int index = 0; index < iCount; index++)
   {
    x = Common :: random (35, 50);
    sprintf (sResults, "%s is affected by a curse and takes %d damage. ", target.m_strAlias.c_str(), x);
    strResults += sResults;
    target.takeDamage(x);
   }
   // reutrn with our results
   return strResults;
  }
 }
 else // not enough MP
 { 
  sprintf (sResults, "%s attempts to cast Curse but doesnt have enough MP.", user->m_strAlias.c_str());
 }
 
 
 strResults += sResults;
 
 return strResults;
}

