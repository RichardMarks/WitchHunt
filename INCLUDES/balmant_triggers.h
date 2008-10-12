
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

// Balmant North
addTrigger (createTrigger (trigger_rock_slide, 11, 57, NORTH_BALMANT));
addTrigger (createTrigger (trigger_rock_slide, 58, 55, NORTH_BALMANT));
addTrigger (createTrigger (trigger_rock_slide, 31, 17, NORTH_BALMANT));

addWarp (NORTH_BALMANT, 33, 9, WORLD_MAP, 12, 25 );
addWarp (NORTH_BALMANT, 9, 32, NORTHWEST_BALMANT, 58, 32);
addWarp (NORTH_BALMANT, 61, 37, NORTHEAST_BALMANT, 12, 37);
addWarp (NORTH_BALMANT, 33, 61, RADNINE_CRAG, 35, 12);

// Balmant Northwest
addTrigger (createTrigger (trigger_rock_slide, 40 , 60, NORTHWEST_BALMANT));
addTrigger (createTrigger (trigger_rock_slide, 28, 15, NORTHWEST_BALMANT));

addWarp (NORTHWEST_BALMANT, 60 , 32, NORTH_BALMANT, 12, 32);
addWarp (NORTHWEST_BALMANT, 11 , 60, SOUTHWEST_BALMANT, 33, 12 );


// Balmant Northeast
addTrigger (createTrigger (trigger_rock_slide, 13, 32, NORTHEAST_BALMANT));
addTrigger (createTrigger (trigger_rock_slide, 21, 59, NORTHEAST_BALMANT));
addTrigger (createTrigger (trigger_rock_slide, 57, 42, NORTHEAST_BALMANT));

addWarp (NORTHEAST_BALMANT, 9, 37, NORTH_BALMANT, 59, 37);
addWarp (NORTHEAST_BALMANT, 33, 61, SOUTHEAST_BALMANT, 33, 12);

// Balmant Southwest
addTrigger (createTrigger (trigger_rock_slide, 47, 13, SOUTHWEST_BALMANT));
addTrigger (createTrigger (trigger_rock_slide, 56, 43, SOUTHWEST_BALMANT));
addTrigger (createTrigger (trigger_rock_slide, 17, 27, SOUTHWEST_BALMANT));

addWarp (SOUTHWEST_BALMANT, 33, 9, NORTHWEST_BALMANT, 14, 59);
addWarp (SOUTHWEST_BALMANT, 61, 26, SOUTH_BALMANT, 12, 35);

// Balmant South
addTrigger (createTrigger (trigger_rock_slide, 53, 46, SOUTH_BALMANT));
addTrigger (createTrigger (trigger_rock_slide, 46, 35, SOUTH_BALMANT));

addWarp (SOUTH_BALMANT, 32, 9, RADNINE_CRAG, 35, 59);
addWarp (SOUTH_BALMANT, 9, 35, SOUTHWEST_BALMANT, 59, 26);
addWarp (SOUTH_BALMANT, 61, 29, SOUTHEAST_BALMANT, 12, 15);
addWarp (SOUTH_BALMANT, 35, 61, WORLD_MAP, 14, 48);

// Southeast Balmant
addWarp (SOUTHEAST_BALMANT, 33, 9, NORTHEAST_BALMANT, 33, 59);
addWarp (SOUTHEAST_BALMANT, 9, 15, SOUTH_BALMANT, 59, 29);


