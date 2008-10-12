
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

DEFITEM(Tea)
{
 string strResults = ""; char sResults [255]; 

  int iTargetMaxMp = target.m_iMaxMp;
  int iAmount;
  
  // 1 in 50 chance that you will regain .5 ( half)
  // 49 in 50 that you regain .125 (one 8th)
  int iPercentage = ((rand()%50)==1) ? 2 : 8;
  if (iTargetMaxMp % iPercentage)
  {
   iAmount = iTargetMaxMp - (iTargetMaxMp % iPercentage);
   iAmount /= iPercentage;
  }
  else
  {
   iAmount = iTargetMaxMp / iPercentage;
  }
  
  target.giveMp (iAmount);
  
  if (&target == user) 
  {
   // used on self
   sprintf (sResults, "%s uses a Tea, and regains %d MP!", 
   user->m_strAlias.c_str (), 
   iAmount);
  }
  else
  {
   sprintf (sResults, "%s uses a Tea on %s\n %s regains %d MP!", 
   user->m_strAlias.c_str (), 
   target.m_strAlias.c_str (), 
   target.m_strAlias.c_str (),
   iAmount);
  } 

 strResults += sResults; return strResults;
}
