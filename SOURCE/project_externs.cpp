
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
// project_externs.cpp
////////////////////////////////////////////////////////////////////////////////

// include the project header
//#include "project.h"


CREATE_MASTER_ABILITY_LIST;               // self explanatory
CREATE_MASTER_ITEM_LIST;                  // self explanatory
CREATE_ITEM_MAP;                          // self explanatory
CREATE_ABILITY_MAP;                       // self explanatory

int                 iCurrent_map;
int                 iCurrent_location;
int iStoryProgress  [C_NUM_STORY_EVENTS]; // array of story elements 
vector <int*>       vpiMaps;              // vector of maps
vector <int>        viCurrentMapTriggers; // vector of triggers for current map
vector <TRIGGER*>   vptMasterTriggerList; // Master trigger list
vector <MAPDATA*>   vptMasterMapList;     // list of map terrain info
vector <EnemyIndex> vtMasterEnemyList;    // create master enemy list
//WORLDMAP            kWorld;               // create a MAP
ENTITY              kHero("Hero");        // create our hero
ENTITY&             rkHero = kHero;       // create a reference of the hero


