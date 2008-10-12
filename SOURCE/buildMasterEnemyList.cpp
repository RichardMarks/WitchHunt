
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

////////////////////////////////////////////////////////////////////////////////
// buildMasterEnemyList.cpp
////////////////////////////////////////////////////////////////////////////////

// include the project header
//#include "project.h"

void buildMasterEnemyList ()
{
 #ifdef DEBUG_BUILD
  cerr << "DEBUG: Building Master Enemy List" << endl;
 #endif 
 
 /*

 "World Map",
 "West Zular",
 "East Zular",
 "Northwestern Balmant Desert",
 "Northern Balmant Desert",
 "Northeastern Balmant Desert",
 "Southwestern Balmant Desert",
 "Southern Balmant Desert",
 "Southeastern Balmant Desert",
 "Radnine Crag",
 "Murias",
 "Southern Jindar Forest",
 "Northwestern Tomb of Knowledge",
 "Northern Tomb of Knowledge",
 "Northeastern Tomb of Knowledge",
 "Western Tomb of Knowledge",
 "Central Tomb of Knowledge",
 "Eastern Tomb of Knowledge",
 "Southwestern Tomb of Knowledge",
 "Southern Tomb of Knowledge",
 "Southeastern Tomb of Knowledge",
 "Southeastern Jindar Forest",
 "Northern Jindar Forest",
 "Hollis Plains",
 "Ginath Bridge"  
  
 */
 
 #include "enemyList_WorldMap.h"
 #include "enemyList_WestZular.h"
 #include "enemyList_EastZular.h"
 #include "enemyList_NorthwesternBalmantDesert.h"
 #include "enemyList_NorthernBalmantDesert.h"
 #include "enemyList_NortheasternBalmantDesert.h"
 #include "enemyList_SouthwesternBalmantDesert.h"
 #include "enemyList_SouthernBalmantDesert.h"
 #include "enemyList_SoutheasternBalmantDesert.h"
 #include "enemyList_RadnineCrag.h"
 #include "enemyList_Murias.h"
 #include "enemyList_SouthernJindarForest.h"
 #include "enemyList_NorthwesternTombofKnowledge.h"
 #include "enemyList_NorthernTombofKnowledge.h"
 #include "enemyList_NortheasternTombofKnowledge.h"
 #include "enemyList_WesternTombofKnowledge.h"
 #include "enemyList_CentralTombofKnowledge.h"
 #include "enemyList_EasternTombofKnowledge.h"
 #include "enemyList_SouthwesternTombofKnowledge.h"
 #include "enemyList_SouthernTombofKnowledge.h"
 #include "enemyList_SoutheasternTombofKnowledge.h"
 #include "enemyList_SoutheasternJindarForest.h"
 #include "enemyList_NorthernJindarForest.h"
 #include "enemyList_HollisPlains.h"
 #include "enemyList_GinathBridge.h"
 
//Angry Cactus
//Angry Peasant
//Avian Hunter
//Avian Matriarch
//Avian Patriarch
//Azrael
//Bandit
//Banshee
//Black Scorpion child
//Black Scorpion
//Cliff Spider
//Common thief
//Crazed Otter
//Cultist
//Demon
//Dust Demon
//Dwarven Marksman
//Dwarven Miner
//Elf tracker
//Fairy
//Fire Ant
//Flying Fish
//Forest Spider
//Forest Wolf
//Ghoul
//Giant field_mouse
//Giant Worm
//Gnoll Mage
//Gnoll Warrior
//Hell Hound
//Hyena
//Killer Bee
//Lion
//Lost Soul
//Lupinus
//Lycan
//Merfolk Guard
//Monster Crab
//Osprey
//Plains Hawk
//Rabid Beaver
//Razortusk Boar
//Renegade
//River Bear
//River Troll
//Rock turtle
//Rogue Mage
//Rogue Soldier
//Sand Moth
//Sand Viper female
//Sand Viper male
//Skeleton
//Sprite
//Starving lion
//Stone Golem
//Stone Troll
//Tortured Widow
//Undead Fiend
//Venom Snake
//Wall Shade
//Water phantom
//Water Snake
//Wild dog
//Wood Elf

}

