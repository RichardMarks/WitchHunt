
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




// these two are defined to make it easier to change what
// we pass to the battle engine
// especially if we wanted to pass a whole party
// of players to the engine instead of a single entity
#ifndef XBATTLE_PARAM_PARTY
 //std::vector <ENTITY*> &vpkParty
 #define XBATTLE_PARAM_PARTY ENTITY& kHero
#endif

#ifndef XBATTLE_PARAM_ENEMIES
 #define XBATTLE_PARAM_ENEMIES std::vector <ENTITY*> &vpkEnemies
#endif


// used by the BATTLE class
#ifndef XBATTLE_PARAMS
 #define XBATTLE_PARAMS common_association* caItemMap, common_association* caAbilMap, \
 ABILITYLIST* _MAL, ITEMLIST* _MIL, XBATTLE_PARAM_PARTY, XBATTLE_PARAM_ENEMIES
#endif

// call this to initiate a battle
// enemies is a vector of entity pointers
#ifndef INITIATE_BATTLE
 #define INITIATE_BATTLE(party,enemies) \
 BATTLE kB (&GLOBAL_ITEM_MAP, &GLOBAL_ABILITY_MAP, \
 GLOBAL_MASTER_ABILITY_LIST, GLOBAL_MASTER_ITEM_LIST, party, enemies)
#endif

/*
#ifndef USE_ITEM_IN_BATTLE
 #define USE_ITEM_IN_BATTLE(user,str,target) \
 user.useItem (CMIL (getItemIndexFromString (*m_CAIL, str)), target)
#endif  
*/

/*
#ifndef USE_ABILITY_IN_BATTLE
 #define USE_ABILITY_IN_BATTLE(user, str, target) \
 user.useAbility (m_MAL [ getAbilityIndexFromString (*m_CAAL, str) ].m_fpkAbility, target)
#endif
*/

#ifndef USE_ITEM_IN_BATTLE
 #define USE_ITEM_IN_BATTLE(result,user,str,target) \
 { \
  int i = getItemIndexFromString (*m_CAIL, str); \
  if (i > -1) { \
   result += user.useItem (m_MIL [i], m_MIL [i].m_strAlias, \
   m_MIL [i].m_fpkItem, target); result += "\n\t"; \
  } \
 } 
#endif  


#ifndef USE_ABILITY_IN_BATTLE
 #define USE_ABILITY_IN_BATTLE(result,user,str,target) \
 { \
  int iIndex = getAbilityIndexFromString (*m_CAAL, str); \
  if (iIndex > -1) { \
   result += user.useAbility (m_MAL [ iIndex ].m_fpkAbility, target); \
   result += "\n\t"; \
  } \
 }
#endif





