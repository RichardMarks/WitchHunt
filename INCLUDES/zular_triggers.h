
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

 // WEST ZULAR
 
 addTrigger (createTrigger (trigger_story_1, 36, 39, WEST_ZULAR, DisableAutoOff));
 addTrigger (createTrigger (trigger_story_2, 35, 39, WEST_ZULAR, DisableAutoOff));
 addTrigger (createTrigger (trigger_story_3, 11, 51, WEST_ZULAR, DisableAutoOff));

 addWarp (WEST_ZULAR, 62, 36, EAST_ZULAR, 11, 36); 
 addWarp (WEST_ZULAR, 62, 38, EAST_ZULAR, 11, 38); 
 addWarp (WEST_ZULAR, 62, 40, EAST_ZULAR, 11, 40); 



 // EAST ZULAR
 addTrigger (createTrigger (trigger_inn, 34, 34, EAST_ZULAR, DisableAutoOff));
 addTrigger (createTrigger (trigger_shop, 51, 50, EAST_ZULAR, DisableAutoOff));
 addTrigger (createTrigger (trigger_locked_door, 54, 60, EAST_ZULAR, DisableAutoOff));
 addTrigger (createTrigger (trigger_locked_door, 58, 32, EAST_ZULAR, DisableAutoOff));
 
 addWarp (EAST_ZULAR, 8, 36, WEST_ZULAR, 59, 36); 
 addWarp (EAST_ZULAR, 8, 38, WEST_ZULAR, 59, 38); 
 addWarp (EAST_ZULAR, 8, 40, WEST_ZULAR, 59, 40); 
 
 addWarp (EAST_ZULAR, 32, 62, WORLD_MAP, 15, 15); 
 addWarp (EAST_ZULAR, 34, 62, WORLD_MAP, 15, 15); 
 addWarp (EAST_ZULAR, 36, 62, WORLD_MAP, 15, 15); 

