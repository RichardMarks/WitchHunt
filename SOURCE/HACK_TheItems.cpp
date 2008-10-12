
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

// HACK_TheItems.cpp

// this "little" file contains ALL the .cpp files for the
// items
// 
// this is to decrease the compile times considerably

// if you add a new cpp file to the project, add it here
// and use Project->options to make sure the new file
// IS NOT SET TO BE COMPILED BY THE COMPILER!
//
// RM - 2:50 PM 03-05-07
//

// the headers that we need

#include "items\\item_header.h"

#include "item_Bandage.cpp"
#include "item_Birthwart.cpp"
#include "item_Brimstone.cpp"
#include "item_ChapterOnePotion.cpp"
#include "item_Fenugreek.cpp"
#include "item_Tea.cpp"
#include "item_Wolfsblood.cpp"

#include "equip_BlackRobe.cpp"
#include "equip_BlueRobe.cpp"
#include "equip_DawnAmulet.cpp"
#include "equip_DuskAmulet.cpp"
#include "equip_HellAmulet.cpp"
#include "equip_LeatherArmor.cpp"


