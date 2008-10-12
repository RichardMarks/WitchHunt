
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

//#include "entity_libraryheader.h"

void ENTITY :: giveHp          (int iAmount) {INC_AND_LIMIT(m_iHp, iAmount, m_iMaxHp);}
void ENTITY :: giveMp          (int iAmount) {INC_AND_LIMIT(m_iMp, iAmount, m_iMaxMp);}
void ENTITY :: giveMaxHp       (int iAmount) {INC_AND_LIMIT(m_iMaxHp, iAmount, 9999);}
void ENTITY :: giveMaxMp       (int iAmount) {INC_AND_LIMIT(m_iMaxMp, iAmount, 9999);}
void ENTITY :: giveStrength    (int iAmount) {INC_AND_LIMIT(m_iStrength, iAmount, 255);}
void ENTITY :: giveVitality    (int iAmount) {INC_AND_LIMIT(m_iVitality, iAmount, 255);}
void ENTITY :: givePhysicalAtk (int iAmount) {INC_AND_LIMIT(m_iPhysicalAtk, iAmount, 255);}
void ENTITY :: givePhysicalDef (int iAmount) {INC_AND_LIMIT(m_iPhysicalDef, iAmount, 255);}
void ENTITY :: giveMagickalAtk (int iAmount) {INC_AND_LIMIT(m_iMagickalAtk, iAmount, 255);}
void ENTITY :: giveMagickalDef (int iAmount) {INC_AND_LIMIT(m_iMagickalDef, iAmount, 255);}
void ENTITY :: giveMoney       (unsigned int iAmount) {INC_AND_LIMIT(m_iMoney, iAmount, static_cast <unsigned int> (65535));}
void ENTITY :: giveLevel       (int iAmount) {INC_AND_LIMIT(m_iLevel, iAmount, 100);}
void ENTITY :: giveExperience  (unsigned int iAmount) {INC_AND_LIMIT(m_iExperience, iAmount, static_cast <unsigned int> (65535));}

void ENTITY :: takeHp          (int iAmount) {DEC_AND_LIMIT(m_iHp, iAmount, 0);}
void ENTITY :: takeMp          (int iAmount) {DEC_AND_LIMIT(m_iMp, iAmount, 0);}
void ENTITY :: takeMaxHp       (int iAmount) {DEC_AND_LIMIT(m_iMaxHp, iAmount, 0);}
void ENTITY :: takeMaxMp       (int iAmount) {DEC_AND_LIMIT(m_iMaxMp, iAmount, 0);}
void ENTITY :: takeStrength    (int iAmount) {DEC_AND_LIMIT(m_iStrength, iAmount, 0);}
void ENTITY :: takeVitality    (int iAmount) {DEC_AND_LIMIT(m_iVitality, iAmount, 0);}
void ENTITY :: takePhysicalAtk (int iAmount) {DEC_AND_LIMIT(m_iPhysicalAtk, iAmount, 0);}
void ENTITY :: takePhysicalDef (int iAmount) {DEC_AND_LIMIT(m_iPhysicalDef, iAmount, 0);}
void ENTITY :: takeMagickalAtk (int iAmount) {DEC_AND_LIMIT(m_iMagickalAtk, iAmount, 0);}
void ENTITY :: takeMagickalDef (int iAmount) {DEC_AND_LIMIT(m_iMagickalDef, iAmount, 0);}
void ENTITY :: takeMoney       (unsigned int iAmount) {DEC_AND_LIMIT(m_iMoney, iAmount, static_cast<unsigned int>(0));}

