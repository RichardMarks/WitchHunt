
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

// HACK_TheENTITYCode.cpp

// this "little" file contains ALL the .cpp files for the
// ENTITY library module
// 
// this is to decrease the compile times considerably

// if you add a new cpp file to the project, add it here
// and use Project->options to make sure the new file
// IS NOT SET TO BE COMPILED BY THE COMPILER!
//
// RM - 3:20 AM 03-02-07
//

// the headers that we need
#include "entity_libraryheader.h"

#include "ENTITY.cpp"
#include "entity_abilityIndex.cpp"
#include "entity_canLevel.cpp"
#include "entity_dropItem.cpp"
#include "entity_equipItem.cpp"
#include "entity_getVitalString.cpp"
#include "entity_giveItem.cpp"
#include "entity_hasItem.cpp"
#include "entity_hasItemEquipped.cpp"
#include "entity_learnAbility.cpp"
#include "entity_learnedAbility.cpp"
#include "entity_levelUp.cpp"
#include "entity_loadTemplate.cpp"
#include "entity_navigate.cpp"
#include "entity_outputStat.cpp"
#include "entity_rest.cpp"
#include "entity_setPosition.cpp"
#include "entity_showAbilities.cpp"
#include "entity_showEquipped.cpp"
#include "entity_showInventory.cpp"
#include "entity_showStats.cpp"
#include "entity_statmodifiers.cpp"
#include "entity_takeDamage.cpp"
#include "entity_unequipItem.cpp"
#include "entity_useAbility.cpp"
#include "entity_useItem.cpp"



