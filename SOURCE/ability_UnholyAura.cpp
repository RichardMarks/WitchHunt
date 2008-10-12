
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

DEFABILITY(poa_UnholyAura)
{
 string strResults = "";
 char sResults [255];
 
 int iDamage;
 
 // check for MP
 if (user->m_iMp >= 47)
 {
  if (user->m_iMagickalAtk >= target.m_iMagickalDef)
  {
   int x = Common :: random (1, 10);
   int y = Common :: random (1, 10);
   
   // lower and raise the stats accordingly
   target.takeStrength(x);
   target.givePhysicalDef(y);
   sprintf (sResults, "%s inflicts %s with Unholy Aura lowering its Strength by %d and raising it Defense by %d.", user->m_strAlias.c_str(),target.m_strAlias.c_str(), x, y);
  }
  else // missed!
  {
   sprintf (sResults, "%s attempts to use Mind Blast but it is resisted.", user->m_strAlias.c_str());
  }
 }
 else // not enough MP
 {
  sprintf (sResults, "%s attempts to cast Mind Blast but doesnt have enough MP.", user->m_strAlias.c_str());
 }
 
 strResults += sResults;
 
 return strResults;
}

