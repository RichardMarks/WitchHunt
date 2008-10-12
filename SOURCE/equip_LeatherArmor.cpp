
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

DEFEQUIP(LeatherArmor)
{
 string strResults = ""; 
 char sResults [255]; 

 target.givePhysicalAtk (item.m_iPhysicalAtk);
 target.givePhysicalDef (item.m_iPhysicalDef);
 target.giveMagickalAtk (item.m_iMagickalAtk);
 target.giveMagickalDef (item.m_iMagickalDef);
 
 if (&target == user) 
 {
  sprintf (sResults, "%s equips the %s.\n\tP.Atk + %d\n\tP.Def + %d\n\tM.Atk + %d\n\tM.Def + %d", 
  user->m_strAlias.c_str (), 
  item.m_strAlias.c_str (), 
  item.m_iPhysicalAtk,
  item.m_iPhysicalDef,
  item.m_iMagickalAtk,
  item.m_iMagickalDef);
 }
 else
 {
  sprintf (sResults, "%s equips the %s on %s.\n\tP.Atk + %d\n\tP.Def + %d\n\tM.Atk + %d\n\tM.Def + %d", 
  user->m_strAlias.c_str (), 
  item.m_strAlias.c_str (), 
  target.m_strAlias.c_str (),
  item.m_iPhysicalAtk,
  item.m_iPhysicalDef,
  item.m_iMagickalAtk,
  item.m_iMagickalDef);
 }
 strResults += sResults; return strResults;
}

DEFUNEQUIP(LeatherArmor)
{
 string strResults = ""; char sResults [255]; 

 target.takePhysicalAtk (item.m_iPhysicalAtk);
 target.takePhysicalDef (item.m_iPhysicalDef);
 target.takeMagickalAtk (item.m_iMagickalAtk);
 target.takeMagickalDef (item.m_iMagickalDef);


 if (&target == user) 
 {
  sprintf (sResults, "%s removes the %s.\n\tP.Atk - %d\n\tP.Def - %d\n\tM.Atk - %d\n\tM.Def - %d", 
  user->m_strAlias.c_str (), 
  item.m_strAlias.c_str (), 
  item.m_iPhysicalAtk,
  item.m_iPhysicalDef,
  item.m_iMagickalAtk,
  item.m_iMagickalDef);
 }
 else
 {
  sprintf (sResults, "%s removes the %s from %s.\n\tP.Atk - %d\n\tP.Def - %d\n\tM.Atk - %d\n\tM.Def - %d", 
  user->m_strAlias.c_str (), 
  item.m_strAlias.c_str (), 
  target.m_strAlias.c_str (),
  item.m_iPhysicalAtk,
  item.m_iPhysicalDef,
  item.m_iMagickalAtk,
  item.m_iMagickalDef);
 }
 strResults += sResults; return strResults;
}

