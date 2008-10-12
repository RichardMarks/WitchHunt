
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

// HACK_TheGameCode.cpp

// this "little" file contains ALL the .cpp files for the
// game code of the project. (not the LIBRARY)
// 
// this is to decrease the compile times considerably

// if you add a new cpp file to the project, add it here
// and use Project->options to make sure the new file
// IS NOT SET TO BE COMPILED BY THE COMPILER!
//
// RM - 3:00 AM 03-02-07
//

// the headers that we need
#include "project.h"
#include "gameMaps.h"

#include "adjustLevel.cpp"
#include "buildMasterEnemyList.cpp"
#include "buildMasterLists.cpp"
#include "buildMasterTriggerList.cpp"
#include "displayCredits.cpp"
#include "displayGameover.cpp"
#include "displayMainMenu.cpp"
#include "displayMiniMap.cpp"
#include "displayTitleScreen.cpp"
#include "helpScreen.cpp"
#include "loadGame.cpp"
#include "mainGame.cpp"
#include "mainMenu.cpp"
#include "newGame.cpp"
#include "project_externs.cpp"
#include "project_main.cpp"
#include "saveGame.cpp"
#include "shortStats.cpp"
#include "spawnEnemies.cpp"
#include "TriggerHelpers.cpp"
#include "MapDataHelpers.cpp"
#include "updateCurrentLocation.cpp"
#include "updateCurrentMapTriggers.cpp"
#include "pushMaps.cpp"
#include "startBattle.cpp"
#include "addEnemy.cpp"
#include "getFileList.cpp"


