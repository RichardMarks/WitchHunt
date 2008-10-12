
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


// TOK northwest
addWarp (NORTHWEST_TOK, 62, 21, NORTH_TOK, 11, 19);
addWarp (NORTHWEST_TOK, 62, 23, NORTH_TOK, 11, 19);
addWarp (NORTHWEST_TOK, 62, 25, NORTH_TOK, 11, 19);

addWarp (NORTHWEST_TOK, 62, 47, NORTH_TOK, 11, 52);
addWarp (NORTHWEST_TOK, 62, 49, NORTH_TOK, 11, 52);


addWarp (NORTHWEST_TOK, 52, 62, WEST_TOK, 57, 11);
addWarp (NORTHWEST_TOK, 54, 62, WEST_TOK, 57, 11);
addWarp (NORTHWEST_TOK, 56, 62, WEST_TOK, 57, 11);

addWarp (NORTHWEST_TOK, 30, 62, WEST_TOK, 29, 11);
addWarp (NORTHWEST_TOK, 32, 62, WEST_TOK, 29, 11);


// TOK north

addWarp (NORTH_TOK, 9, 19, NORTHWEST_TOK, 60, 23);
addWarp (NORTH_TOK, 9, 21, NORTHWEST_TOK, 60, 23);

addWarp (NORTH_TOK, 9, 50, NORTHWEST_TOK, 60, 48);
addWarp (NORTH_TOK, 9, 52, NORTHWEST_TOK, 60, 48);

addWarp (NORTH_TOK, 26, 63, CENTRAL_TOK, 35, 11);
addWarp (NORTH_TOK, 28, 63, CENTRAL_TOK, 35, 11);
addWarp (NORTH_TOK, 30, 63, CENTRAL_TOK, 35, 11);

addWarp (NORTH_TOK, 48, 62, CENTRAL_TOK, 43, 11);
addWarp (NORTH_TOK, 50, 62, CENTRAL_TOK, 43, 11);
addWarp (NORTH_TOK, 52, 62, CENTRAL_TOK, 43, 11);
addWarp (NORTH_TOK, 54, 62, CENTRAL_TOK, 43, 11);

addWarp (NORTH_TOK, 62, 17, NORTHEAST_TOK, 11, 21);
addWarp (NORTH_TOK, 62, 19, NORTHEAST_TOK, 11, 21);
addWarp (NORTH_TOK, 62, 21, NORTHEAST_TOK, 11, 21);

addWarp (NORTH_TOK, 62, 54, NORTHEAST_TOK, 11, 53);
addWarp (NORTH_TOK, 62, 56, NORTHEAST_TOK, 11, 53);
addWarp (NORTH_TOK, 62, 58, NORTHEAST_TOK, 11, 53);


addTrigger (createTrigger (trigger_altar, 37, 43, NORTH_TOK));

// TOK northeast
addWarp (NORTHEAST_TOK, 9, 19, NORTH_TOK, 60, 18);
addWarp (NORTHEAST_TOK, 9, 21, NORTH_TOK, 60 ,18);

addWarp (NORTHEAST_TOK, 9, 52, NORTH_TOK, 60, 56);
addWarp (NORTHEAST_TOK, 9, 54, NORTH_TOK, 60, 56);

addWarp (NORTHEAST_TOK, 19, 62, EAST_TOK, 17, 11);
addWarp (NORTHEAST_TOK, 19, 64, EAST_TOK, 17, 11);

addWarp (NORTHEAST_TOK, 42, 62, EAST_TOK, 44, 11);
addWarp (NORTHEAST_TOK, 42, 64, EAST_TOK, 44, 11);

// TOK west
addWarp (WEST_TOK, 28, 9, NORTHWEST_TOK, 32, 60);
addWarp (WEST_TOK, 30, 9, NORTHWEST_TOK, 32, 60);
addWarp (WEST_TOK, 32, 9, NORTHWEST_TOK, 32, 60);

addWarp (WEST_TOK, 55, 9, NORTHWEST_TOK, 53, 60);
addWarp (WEST_TOK, 57, 9, NORTHWEST_TOK, 53, 60);

addWarp (WEST_TOK, 62, 47, CENTRAL_TOK, 11, 48);
addWarp (WEST_TOK, 62, 49, CENTRAL_TOK, 11, 48);

addWarp (WEST_TOK, 20, 62, SOUTHWEST_TOK, 21, 11);
addWarp (WEST_TOK, 22, 62, SOUTHWEST_TOK, 21, 11);

addWarp (WEST_TOK, 40, 62, SOUTHWEST_TOK, 46, 11);
addWarp (WEST_TOK, 42, 62, SOUTHWEST_TOK, 46, 11);

// TOK central
addWarp (CENTRAL_TOK, 9, 47, WEST_TOK, 60, 48);
addWarp (CENTRAL_TOK, 9, 49, WEST_TOK, 60, 48);

addWarp (CENTRAL_TOK, 21, 62, SOUTH_TOK, 24, 10);
addWarp (CENTRAL_TOK, 23, 62, SOUTH_TOK, 24, 10);

addWarp (CENTRAL_TOK, 55, 62, SOUTH_TOK, 56, 11);
addWarp (CENTRAL_TOK, 57, 62, SOUTH_TOK, 56, 11);
addWarp (CENTRAL_TOK, 59, 62, SOUTH_TOK, 56, 11);

addWarp (CENTRAL_TOK, 62, 24, EAST_TOK, 11, 27);
addWarp (CENTRAL_TOK, 62, 26, EAST_TOK, 11, 27);
addWarp (CENTRAL_TOK, 62, 28, EAST_TOK, 11, 27);
addWarp (CENTRAL_TOK, 62, 30, EAST_TOK, 11, 27);

addWarp (CENTRAL_TOK, 62, 47, EAST_TOK, 11, 48);
addWarp (CENTRAL_TOK, 62, 49, EAST_TOK, 11, 48);

addWarp (CENTRAL_TOK, 62, 58, EAST_TOK, 11, 59);
addWarp (CENTRAL_TOK, 62, 60, EAST_TOK, 11, 59);

addWarp (CENTRAL_TOK, 30, 9, NORTH_TOK, 27, 61);
addWarp (CENTRAL_TOK, 32, 9, NORTH_TOK, 27, 61);
addWarp (CENTRAL_TOK, 34, 9, NORTH_TOK, 27, 61);
addWarp (CENTRAL_TOK, 36, 9, NORTH_TOK, 27, 61);

addWarp (CENTRAL_TOK, 43, 9, NORTH_TOK, 54, 60);
addWarp (CENTRAL_TOK, 45, 9, NORTH_TOK, 54, 60);
addWarp (CENTRAL_TOK, 47, 9, NORTH_TOK, 54, 60);

addTrigger (createTrigger (trigger_story_6, 35, 29, CENTRAL_TOK));
addTrigger (createTrigger (trigger_restoration, 38, 46, CENTRAL_TOK));

// TOK east
addWarp (EAST_TOK, 17, 9, NORTHEAST_TOK, 21, 60);
addWarp (EAST_TOK, 19, 9, NORTHEAST_TOK, 21, 60);

addWarp (EAST_TOK, 43, 9, NORTHEAST_TOK, 43, 60);
addWarp (EAST_TOK, 45, 9, NORTHEAST_TOK, 43, 60);

addWarp (EAST_TOK, 9, 25, CENTRAL_TOK, 60, 27);
addWarp (EAST_TOK, 9, 27, CENTRAL_TOK, 60, 27);
addWarp (EAST_TOK, 9, 29, CENTRAL_TOK, 60, 27);

addWarp (EAST_TOK, 9, 47, CENTRAL_TOK, 60, 48);
addWarp (EAST_TOK, 9, 49, CENTRAL_TOK, 60, 48);

addWarp (EAST_TOK, 9, 58, CENTRAL_TOK, 60, 59);
addWarp (EAST_TOK, 9, 60, CENTRAL_TOK, 60, 59);

addWarp (EAST_TOK, 31, 62, SOUTHEAST_TOK, 28, 11);
addWarp (EAST_TOK, 33, 62, SOUTHEAST_TOK, 28, 11);
addWarp (EAST_TOK, 35, 62, SOUTHEAST_TOK, 28, 11);


// TOK southwest
addWarp (SOUTHWEST_TOK, 20, 9, WEST_TOK, 21, 60);
addWarp (SOUTHWEST_TOK, 22, 9, WEST_TOK, 21, 60);

addWarp (SOUTHWEST_TOK, 43, 9, WEST_TOK, 41, 60);
addWarp (SOUTHWEST_TOK, 45, 9, WEST_TOK, 41, 60);
addWarp (SOUTHWEST_TOK, 47, 9, WEST_TOK, 41, 60);

addWarp (SOUTHWEST_TOK, 62, 21, SOUTH_TOK, 11, 25);
addWarp (SOUTHWEST_TOK, 62, 23, SOUTH_TOK, 11, 25);
addWarp (SOUTHWEST_TOK, 62, 25, SOUTH_TOK, 11, 25);

addWarp (SOUTHWEST_TOK, 41, 47, SOUTH_TOK, 13, 44);
addWarp (SOUTHWEST_TOK, 43, 47, SOUTH_TOK, 13, 44);


// TOK south
addWarp (SOUTH_TOK, 9, 23, SOUTHWEST_TOK, 60, 22);
addWarp (SOUTH_TOK, 9, 25, SOUTHWEST_TOK, 60, 22);

addWarp (SOUTH_TOK, 11, 43, SOUTHWEST_TOK, 42, 49);
addWarp (SOUTH_TOK, 11, 45, SOUTHWEST_TOK, 42, 49);


addWarp (SOUTH_TOK, 23, 8, CENTRAL_TOK, 22, 60);
addWarp (SOUTH_TOK, 25, 8, CENTRAL_TOK, 22, 60);

addWarp (SOUTH_TOK, 55, 9, CENTRAL_TOK, 58, 60);
addWarp (SOUTH_TOK, 57, 9, CENTRAL_TOK, 58, 60);

addWarp (SOUTH_TOK, 62, 25, SOUTHEAST_TOK, 11, 24);
addWarp (SOUTH_TOK, 62, 27, SOUTHEAST_TOK, 11, 24);
addWarp (SOUTH_TOK, 62, 29, SOUTHEAST_TOK, 11, 24);

addWarp (SOUTH_TOK, 62, 57, SOUTHEAST_TOK, 11, 59);
addWarp (SOUTH_TOK, 62, 59, SOUTHEAST_TOK, 11, 59);
addWarp (SOUTH_TOK, 62, 61, SOUTHEAST_TOK, 11, 59);

addWarp (SOUTH_TOK, 10, 62, SOUTH_TOK, 26, 50);
addWarp (SOUTH_TOK, 12, 62, SOUTH_TOK, 26, 50);
addWarp (SOUTH_TOK, 14, 62, SOUTH_TOK, 26, 50);

addWarp (SOUTH_TOK, 29, 62, FAR_SOUTHWEST_JINDAR_FOREST_S, 35, 38);
addWarp (SOUTH_TOK, 31, 62, FAR_SOUTHWEST_JINDAR_FOREST_S, 35, 38);
addWarp (SOUTH_TOK, 33, 62, FAR_SOUTHWEST_JINDAR_FOREST_S, 35, 38);

addTrigger ( createTrigger (trigger_story_7, 29, 60, SOUTH_TOK));
addTrigger ( createTrigger (trigger_story_7, 30, 60, SOUTH_TOK));
addTrigger ( createTrigger (trigger_story_7, 31, 60, SOUTH_TOK));
addTrigger ( createTrigger (trigger_story_7, 32, 60, SOUTH_TOK));
addTrigger ( createTrigger (trigger_story_7, 33, 60, SOUTH_TOK));


// TOK southeast
addWarp (SOUTHEAST_TOK, 27, 9, EAST_TOK, 34, 60);
addWarp (SOUTHEAST_TOK, 29, 9, EAST_TOK, 34, 60);

addWarp (SOUTHEAST_TOK, 9, 23, SOUTH_TOK, 60, 27);
addWarp (SOUTHEAST_TOK, 9, 25, SOUTH_TOK, 60, 27);

addWarp (SOUTHEAST_TOK, 9, 58, SOUTH_TOK, 60, 59);
addWarp (SOUTHEAST_TOK, 9, 60, SOUTH_TOK, 60, 59);

