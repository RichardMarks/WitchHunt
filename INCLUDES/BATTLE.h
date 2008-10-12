
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

#ifndef     __BATTLE_H__
#define     __BATTLE_H__

#include <vector>
#include "macros.h"
#include "COMMON.h"

struct ITEMLIST;
struct ABILITYLIST;
class ENTITY;

class BATTLE
{
 private:
  ABILITYLIST*        m_MAL; // master ability list
  ITEMLIST*           m_MIL; // master item list
  common_association* m_CAAL; // common association ability list
  common_association* m_CAIL; // common association item list
  
 public:
        BATTLE ();
        BATTLE(XBATTLE_PARAMS);
        virtual ~BATTLE ();
        int m_iExpGained;
        int m_iMoneyGained;
        void runBattle(ENTITY &kHero, std::vector <ENTITY*> &vkEnemies);
};

#endif
