
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
// usable items
//
// MAP_ITEM (alias, index);
////////////////////////////////////////////////////////////////////////////////

 #ifdef DEBUG_BUILD
  cerr << "DEBUG: Building Master Item List" << endl;
 #endif

 #ifdef DEBUG_BUILD
  cerr << "DEBUG: Mapping items" << endl;
 #endif
 
 MAP_ITEM (Bandage,                     0);
 MAP_ITEM (Tea,                         1);
 MAP_ITEM (Brimstone,                   2);
 MAP_ITEM (Birthwart,                   3);

////////////////////////////////////////////////////////////////////////////////
// equipment items; note that they use 2 numbers, so 20 is really 20 & 21
//
// MAP_EQUIPMENT (alias, index);
////////////////////////////////////////////////////////////////////////////////

 #ifdef DEBUG_BUILD
  cerr << "DEBUG: Mapping equipment" << endl;
 #endif 
 
 MAP_EQUIPMENT (Leather Armor,          20); 
 MAP_EQUIPMENT (Black Robe,             22);
 MAP_EQUIPMENT (Blue Robe,              24); 
 MAP_EQUIPMENT (Dusk Amulet,            26); 
 MAP_EQUIPMENT (Dawn Amulet,            28); 
 MAP_EQUIPMENT (Hell Amulet,            30); 

////////////////////////////////////////////////////////////////////////////////
// add items to the master item list
// 
// ADD_ITEM (alias, method_name, category); 
// category can be eStory or eUsable
//////////////////////////////////////////////////////////////////////////////// 

 #ifdef DEBUG_BUILD
  cerr << "DEBUG: Adding items" << endl;
 #endif
 
 ADD_ITEM (Bandage,                     Bandage, eUsable);
 ADD_ITEM (Tea,                         Tea, eUsable);
 ADD_ITEM (Brimstone,                   Brimstone, eStory);
 ADD_ITEM (Birthwart,                   Birthwart, eStory);
////////////////////////////////////////////////////////////////////////////////
// add equipment to the master item list
//
// ADD_EQUIPMENT (alias, method_name, pha, phd, maa, mad, type);
// type can be eWeapon, eArmor or eAccessory
////////////////////////////////////////////////////////////////////////////////

 #ifdef DEBUG_BUILD
  cerr << "DEBUG: Adding equipment" << endl;
 #endif
  
 ADD_EQUIPMENT (Leather Armor,          LeatherArmor, 0,10, 0, 0, eArmor);
 ADD_EQUIPMENT (Blue Robe,              BlueRobe,     0, 0, 0,10, eArmor);
 ADD_EQUIPMENT (Black Robe,             BlackRobe,    0, 0,10, 0, eArmor);
 ADD_EQUIPMENT (Dusk Amulet,            DuskAmulet,   0,10, 0,10, eAccessory);
 ADD_EQUIPMENT (Dawn Amulet,            DawnAmulet,   5, 5, 5, 5, eAccessory);
 ADD_EQUIPMENT (Hell Amulet,            HellAmulet,  10, 0,10, 0, eAccessory);
  
 
 
 
 
 
 
 
 
 
 
 
 
 
