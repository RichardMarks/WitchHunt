
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

void ENTITY :: showStats ()
{
 Common :: clearscreen (PRINT_VERTICAL_OFFSET);
 
 int iNextLevelExpReq = (m_iLevel<100)?m_iGrowthTable [m_iLevel + 1]:0;
 
 cout << PRINT_OFFSET 
      << "    Name: " << m_strAlias << OFFSET_ENDL
      << "   Level: " << m_iLevel << "\tNext Level in " 
      << iNextLevelExpReq << " Exp" << OFFSET_ENDL
      << "     Exp: " << m_iExperience << OFFSET_ENDL
      
      << "   Class: " << m_strClass << OFFSET_ENDL 
      << "  Vitals: " << getVitalString () << OFFSET_ENDL 
      << "  Health: " << m_iHp << " / " << m_iMaxHp << OFFSET_ENDL 
      << "    Mana: " << m_iMp << " / " << m_iMaxMp << OFFSET_ENDL 
      << "Physical: " << m_iPhysicalAtk << ":" << m_iPhysicalDef << OFFSET_ENDL 
      << "Magickal: " << m_iMagickalAtk << ":" << m_iMagickalDef << OFFSET_ENDL 
      << "Strength: " << m_iStrength << OFFSET_ENDL 
      << "Vitality: " << m_iVitality << OFFSET_ENDL 
      << "Currency: " << m_iMoney << OFFSET_ENDL
      << "   Steps: " << static_cast <int>(m_iSpacesMoved) << OFFSET_ENDL;
      
}


