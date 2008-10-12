
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

#include "includes.h"
#include "mapDefines.h"



const bool EnableAutoOff = true;
const bool DisableAutoOff = false;
const bool ArmedTrigger = true;
const bool DisarmedTrigger = false;

#define C_NUM_STORY_EVENTS  50

struct TRIGGER 
{ 
 int iXpos;               // position of trigger
 int iYpos;               // ..
 
 void (*func)(ENTITY &e, int index); // function to execute on activation
 bool bArmed;             // is the trigger armed?
 bool bAutoOff;           // does the trigger automatically disarm when activated?
 int iMap;                // what map is the trigger on?
 
 int iTargetXpos;         // position of a warp trigger destination
 int iTargetYpos;         // used only by warp triggers
 int iTargetMap;          // map for warp destination
 
 std :: string strExtra;  // used by item-spawn triggers and anything else I think of
};

struct EnemyIndex { string strEnemy; string strLocation; };



// terrain engine RM 3:36 PM
static int S_iTerrainType [] = {219,170,32,178,193,250,127,240,247,220};
static int S_iTerrainID [] = 
{
 SPACE_WALL,   SPACE_SWAMP,  SPACE_INDOORS, SPACE_SAND,  SPACE_GRASS,
 SPACE_DIRT,   SPACE_ROCK,   SPACE_TRIGGER, SPACE_WATER, SPACE_BRIDGE
};

static char* szMapNames [] = 
{
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
 "Southern Jindar Forest",
 "Southern Jindar Forest",
 "Southern Jindar Forest",
 "Southern Jindar Forest",
 "Southern Jindar Forest",
 "Southern Jindar Forest",
 "Southern Jindar Forest",
 "Southern Jindar Forest",
 "Southern Jindar Forest",
 "Southern Jindar Forest",
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
 "Southeastern Jindar Forest",
 "Southeastern Jindar Forest",
 "Southeastern Jindar Forest",
 "Southeastern Jindar Forest",
 "Southeastern Jindar Forest",
 "Northern Jindar Forest",
 "Northern Jindar Forest",
 "Northern Jindar Forest",
 "Northern Jindar Forest",
 "Northern Jindar Forest",
 "Northern Jindar Forest",
 "Northern Jindar Forest",
 "Northern Jindar Forest",
 "Northern Jindar Forest",
 "Northern Jindar Forest",
 "Northern Jindar Forest",
 "Northern Jindar Forest",
 "Hollis Plains",
 "Ginath Bridge"
 };



// map 
extern int                 iCurrent_map;
extern int                 iCurrent_location;

extern int                 iStoryProgress [];    // array of story elements 
extern vector <int*>       vpiMaps;
extern vector <int>        viCurrentMapTriggers; // 
extern vector <TRIGGER*>   vptMasterTriggerList; // Master trigger list
extern vector <MAPDATA*>   vptMasterMapList;
extern vector <EnemyIndex> vtMasterEnemyList;    // master enemy list
//extern WORLDMAP            kWorld;               // the MAP
extern ENTITY              kHero;                // our hero
extern ENTITY&             rkHero;               // a reference of the hero

// item system
extern common_association  GLOBAL_ITEM_MAP;
extern ITEMLIST            GLOBAL_MASTER_ITEM_LIST [];

// ability system
extern common_association  GLOBAL_ABILITY_MAP;
extern ABILITYLIST         GLOBAL_MASTER_ABILITY_LIST [];

// the many functions that have puttled us

// doRootMenu.h
extern void doGameMenu                 ();
extern void doItemsMenu                ();
extern void doAbilitiesMenu            ();
extern void doCheatMenu                (); // "uber vestigium 1984"

// doGameMenu.h
extern void doGameMenu_Rest            ();
extern void doGameMenu_Status          ();
extern void doGameMenu_Save            ();
extern void doGameMenu_Load            ();

// doItemsMenu.h
extern void doItemsMenu_UseItem        ();
extern void doItemsMenu_DropItem       ();
extern void doItemsMenu_EquipItem      ();
extern void doItemsMenu_UnequipItem    ();

// doAbilitiesMenu.h
extern void doAbilitiesMenu_UseAbility ();

// doCheatMenu.h
extern void doCheatMenu_LevelUp        ();
extern void doCheatMenu_LearnAbility   ();
extern void doCheatMenu_CreateItem     ();
extern void doCheatMenu_MaxStats       ();
extern void doCheatMenu_Warp           ();

// buildMasterLists.cpp
extern void buildMasterLists           ();

// buildMasterEnemyList.cpp
extern void buildMasterEnemyList       ();

// buildMasterTriggerList.cpp
extern void buildMasterTriggerList     ();

// newGame.cpp
extern void newGame                    ();

// saveGame.cpp
extern void saveGame                   ();

// loadGame.cpp
extern void loadGame                   ();

// displayMinimap.cpp
extern void displayMinimap             ();

// displayMainMenu.cpp
extern void displayMainMenu            ();

// displayTitleScreen.cpp
extern void displayTitleScreen         ();

// displayCredits.cpp
extern void displayCredits             ();

// displayGameover.cpp
extern void displayGameover            ();

// helpScreen.cpp
extern void helpScreen                 ();

// mainGame.cpp
extern void mainGame                   ();

// shortStats.cpp
extern void shortStats                 ();

// spawnEnemies.cpp
extern void spawnEnemies               ();

// mainMenu.cpp
extern void mainMenu                   ();

// adjustLevel.cpp
extern void adjustLevel                (std :: vector <ENTITY*> vpkEnemies);





// TRIGGERS

extern void generic__warp__trigger      (ENTITY &e, int index);
extern void generic__itemspawn__trigger (ENTITY &e, int index);
extern void trigger_inn                 (ENTITY &e, int index);
extern void trigger_shop                (ENTITY &e, int index);
extern void trigger_locked_door         (ENTITY &e, int index);
extern void trigger_restoration         (ENTITY &e, int index);
extern void trigger_rock_slide          (ENTITY &e, int index);
extern void trigger_altar               (ENTITY &e, int index);

extern void trigger_story_1             (ENTITY &e, int index);
extern void trigger_story_2             (ENTITY &e, int index);
extern void trigger_story_3             (ENTITY &e, int index);
extern void trigger_story_4             (ENTITY &e, int index);
extern void trigger_story_5             (ENTITY &e, int index);
extern void trigger_story_6             (ENTITY &e, int index);
extern void trigger_story_7             (ENTITY &e, int index);
extern void trigger_story_8             (ENTITY &e, int index);
extern void trigger_story_9             (ENTITY &e, int index);




extern void outputStat                 (int& st, const char* desc, int stat_digits);
extern void checkForEvent              (ENTITY &e);


extern void navigateHero               (eMotionDirection eOkDir, eMotionDirection eNotOkDir);



extern void addMapData                 (MAPDATA* tData);
extern MAPDATA* createMapData          (int iId, std :: string strName, std :: string strDesc, eMapFlags eSafe, eMapFlags eSolid);

extern void updateCurrentLocation      ();
extern void updateCurrentMapTriggers   ();

extern void pushMaps (int iMapCount, ...);


// Trigger Helper Functions
extern void addTrigger                 (TRIGGER* tTrigger);
extern TRIGGER* createTrigger          (void (*func)(ENTITY &e, int index), int iXpos = 0, int iYpos = 0, int Map = 0, bool bAutoOff = true, bool bArmed = true);
extern void enableTrigger              (int index);
extern void disableTrigger             (int index);
extern void clearMasterTriggerList     ();
extern void addWarp                    (int iMap, int iXpos, int iYpos, int iTargetMap, int iTargetXpos, int iTargetYpos, bool bAutoOff = false);
extern void addItemSpawn               (int iMap, int iXpos, int iYpos, std :: string strItemName, int iAmount = 1);                             


extern void startBattle                (int iEnemies, ...);

extern void addEnemy                   (std :: string strMap, std :: string strEnemyName);

extern vector<std :: string> getFileList (std :: string strExtension, bool bDisplayExtension);


