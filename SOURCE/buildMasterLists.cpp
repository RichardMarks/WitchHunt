
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
// buildMasterLists.cpp
////////////////////////////////////////////////////////////////////////////////

void buildMasterLists ()
{
 // include the master item list
 #include "Mil.h"
 
 // include the master ability list
 #include "Mal.h"
 
 // fill the master enemy list
 buildMasterEnemyList ();
 
 #ifdef DEBUG_BUILD
  cerr << "DEBUG: Creating Game World" << endl;
 #endif 
 

 pushMaps (52, world_map,
w_zular, e_zular,
nw_balmant, n_balmant, ne_balmant,
sw_balmant, s_balmant, se_balmant,
radnine_crag,
murias,
far_nw_jindar_s, nw_jindar_s, ne_jindar_s, far_ne_jindar_s,
far_w_jindar_s, w_jindar_s, e_jindar_s, far_e_jindar_s,
far_sw_jindar_s, sw_jindar_s, se_jindar_s, far_se_jindar_s,
nw_tok, n_tok, ne_tok,
w_tok, c_tok, e_tok,
sw_tok, s_tok, se_tok,
nw_jindar_se, n_jindar_se, ne_jindar_se,
sw_jindar_se, s_jindar_se, se_jindar_se,
far_nw_jindar_n, far_n_jindar_n, far_ne_jindar_n,
nw_jindar_n, n_jindar_n, ne_jindar_n,
sw_jindar_n, s_jindar_n, se_jindar_n,
far_sw_jindar_n, far_s_jindar_n, far_se_jindar_n,
hollis,
ginath_bridge);
 
 
 // define the map terrain data types 
 addMapData (createMapData (SPACE_WALL,    "WALL",    "WALL",    eMapIsSafe,    eMapIsNotPassable));
 addMapData (createMapData (SPACE_SWAMP,   "Swamp",   "Swamp",   eMapIsNotSafe, eMapIsPassable));
 addMapData (createMapData (SPACE_INDOORS, "Indoors", "Indoors", eMapIsSafe,    eMapIsPassable));
 addMapData (createMapData (SPACE_SAND,    "Sand",    "Sand",    eMapIsNotSafe, eMapIsPassable));
 addMapData (createMapData (SPACE_GRASS,   "Grass",   "Grass",   eMapIsNotSafe, eMapIsPassable));
 addMapData (createMapData (SPACE_DIRT,    "Dirt",    "Dirt",    eMapIsNotSafe, eMapIsPassable));
 addMapData (createMapData (SPACE_ROCK,    "Rock",    "Rock",    eMapIsNotSafe, eMapIsPassable));
 addMapData (createMapData (SPACE_WATER,   "Water",   "Water",   eMapIsSafe,    eMapIsNotPassable));
 addMapData (createMapData (SPACE_BRIDGE,  "Bridge",  "Bridge",  eMapIsSafe,    eMapIsPassable));
 addMapData (createMapData (SPACE_TRIGGER, "Trigger", "Event",       eMapIsSafe,    eMapIsPassable));
 
 
 
 iCurrent_map      = WEST_ZULAR;

 iCurrent_location = SPACE_INDOORS;

}




