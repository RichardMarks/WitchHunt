
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

#include "battle_libraryheader.h"

BATTLE :: BATTLE ()
{
 m_iExpGained   = 0;
 m_iMoneyGained = 0;
 m_MAL  = NULL;
 m_MIL  = NULL;
 m_CAAL = NULL;
 m_CAIL = NULL;
 #ifdef DEBUG_BUILD
  cerr << "DEBUG: instance of BATTLE class created" << endl;
 #endif
}

////

BATTLE :: BATTLE(XBATTLE_PARAMS)
{
 srand (static_cast<unsigned int>(time (0)));
 
 m_MAL          = _MAL;
 m_MIL          = _MIL;
 m_CAAL         = caAbilMap;
 m_CAIL         = caItemMap;
 m_iExpGained   = 0;
 m_iMoneyGained = 0;
 
 #ifdef DEBUG_BUILD
  cerr << "DEBUG: instance of BATTLE class created with params" << endl;
  cerr << "DEBUG: calling runBattle() from constructor..not a great idea" << endl;
  Common :: pause ("DEBUG: -PAUSED- (Press Return)");
 #endif
 
 runBattle (kHero, vpkEnemies);
 
 #ifdef DEBUG_BUILD
  cerr << "DEBUG: runBattle() finished. end of constructor" << endl;
  Common :: pause ("DEBUG: -PAUSED- (Press Return)");
 #endif
}

BATTLE :: ~BATTLE ()
{ 
 #ifdef DEBUG_BUILD
  cerr << "DEBUG: instance of BATTLE class destroyed" << endl;
  Common :: pause ("DEBUG: -PAUSED- (Press Return)");
 #endif
}

void BATTLE :: runBattle (ENTITY &kHero, vector <ENTITY*> &vpkEnemies)
{ 
 #include "battle_prebattlebegin.h"

 bool bDone = false;
 while(!bDone)
 {
  strOutput = "";
  #include "battle_obtaintarget.h"
  #include "battle_obtainaction.h"
  #include "battle_action_useitem.h"
  #include "battle_action_useability.h"
  #include "battle_action_run.h"
  #include "battle_enemy_turn.h"
  #include "battle_displayturn.h"
  #include "battle_checkfordeadenemies.h"
  #include "battle_checkfordeadparty.h"   
 }
 #include "battle_prebattleend.h"  
 #include "battle_battleend.h"
}

