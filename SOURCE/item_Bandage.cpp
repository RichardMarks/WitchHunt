
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

//#include "item_header.h"

DEFITEM(Bandage)
{
 string strResults = ""; char sResults [255]; 
 
  int iTargetMaxHp = target.m_iMaxHp;
  int iAmount;
  
  // 1 in 50 chance that you will regain .5 ( half)
  // 49 in 50 that you regain .125 (one 8th)
  int iPercentage = ((rand()%50)==1) ? 2 : 8;
  if (iTargetMaxHp % iPercentage)
  {
   iAmount = iTargetMaxHp - (iTargetMaxHp % iPercentage);
   iAmount /= iPercentage;
  }
  else
  {
   iAmount = iTargetMaxHp / iPercentage;
  }
  
  target.giveHp (iAmount);
  
  if (&target == user) 
  {
   // used on self
   sprintf (sResults, "%s uses a Bandage, and regains %d HP!", 
   user->m_strAlias.c_str (), 
   iAmount);
  }
  else
  {
   sprintf (sResults, "%s uses a Bandage on %s\n %s regains %d HP!", 
   user->m_strAlias.c_str (), 
   target.m_strAlias.c_str (), 
   target.m_strAlias.c_str (),
   iAmount);
  } 

 strResults += sResults; return strResults;
}


  /*
  int x
  if (mhp % 4) {
   x = mhp - (mhp % 4)
   x = x / 4
  } else
   x = mhp / 4;

Rafael is better at math than I. lol
  */
  
