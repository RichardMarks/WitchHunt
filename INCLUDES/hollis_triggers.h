
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

 addWarp (HOLLIS, 8, 14, GINATH_BRIDGE, 59, 36);
 addWarp (HOLLIS, 8, 16, GINATH_BRIDGE, 59, 36);
 addWarp (HOLLIS, 8, 18, GINATH_BRIDGE, 59, 36);
 addWarp (HOLLIS, 8, 20, GINATH_BRIDGE, 59, 36);
 addWarp (HOLLIS, 8, 22, GINATH_BRIDGE, 59, 36);
 addWarp (HOLLIS, 8, 24, GINATH_BRIDGE, 59, 36);
 addWarp (HOLLIS, 8, 26, GINATH_BRIDGE, 59, 36);
 addWarp (HOLLIS, 8, 28, GINATH_BRIDGE, 59, 36);
 addWarp (HOLLIS, 8, 30, GINATH_BRIDGE, 59, 36);
 addWarp (HOLLIS, 8, 32, GINATH_BRIDGE, 59, 36);
 addWarp (HOLLIS, 8, 34, GINATH_BRIDGE, 59, 36);
 addWarp (HOLLIS, 8, 36, GINATH_BRIDGE, 59, 36);
 addWarp (HOLLIS, 8, 38, GINATH_BRIDGE, 59, 36);
 addWarp (HOLLIS, 8, 40, GINATH_BRIDGE, 59, 36);
 addWarp (HOLLIS, 8, 42, GINATH_BRIDGE, 59, 36);
 addWarp (HOLLIS, 8, 44, GINATH_BRIDGE, 59, 36);
 addWarp (HOLLIS, 8, 46, GINATH_BRIDGE, 59, 36);
 addWarp (HOLLIS, 8, 48, GINATH_BRIDGE, 59, 36);
 addWarp (HOLLIS, 8, 50, GINATH_BRIDGE, 59, 36);
 addWarp (HOLLIS, 8, 52, GINATH_BRIDGE, 59, 36);
 addWarp (HOLLIS, 8, 54, GINATH_BRIDGE, 59, 36);
 
 
 addWarp (HOLLIS, 14, 62, FAR_NORTH_JINDAR_FOREST_N, 26, 12);
 addWarp (HOLLIS, 16, 62, FAR_NORTH_JINDAR_FOREST_N, 26, 12);
 addWarp (HOLLIS, 18, 62, FAR_NORTH_JINDAR_FOREST_N, 26, 12);
 addWarp (HOLLIS, 20, 62, FAR_NORTH_JINDAR_FOREST_N, 26, 12);
 addWarp (HOLLIS, 22, 62, FAR_NORTH_JINDAR_FOREST_N, 26, 12);
 addWarp (HOLLIS, 24, 62, FAR_NORTH_JINDAR_FOREST_N, 26, 12);
 addWarp (HOLLIS, 26, 62, FAR_NORTH_JINDAR_FOREST_N, 26, 12);
 addWarp (HOLLIS, 28, 62, FAR_NORTH_JINDAR_FOREST_N, 26, 12);
 addWarp (HOLLIS, 30, 62, FAR_NORTH_JINDAR_FOREST_N, 26, 12);
 addWarp (HOLLIS, 32, 62, FAR_NORTH_JINDAR_FOREST_N, 26, 12);
 addWarp (HOLLIS, 34, 62, FAR_NORTH_JINDAR_FOREST_N, 26, 12);
 addWarp (HOLLIS, 36, 62, FAR_NORTH_JINDAR_FOREST_N, 26, 12);
 addWarp (HOLLIS, 38, 62, FAR_NORTH_JINDAR_FOREST_N, 26, 12);
 addWarp (HOLLIS, 40, 62, FAR_NORTH_JINDAR_FOREST_N, 26, 12);
 addWarp (HOLLIS, 42, 62, FAR_NORTH_JINDAR_FOREST_N, 26, 12);
 addWarp (HOLLIS, 44, 62, FAR_NORTH_JINDAR_FOREST_N, 26, 12);
 addWarp (HOLLIS, 46, 62, FAR_NORTH_JINDAR_FOREST_N, 26, 12);
 addWarp (HOLLIS, 48, 62, FAR_NORTH_JINDAR_FOREST_N, 26, 12);
 addWarp (HOLLIS, 50, 62, FAR_NORTH_JINDAR_FOREST_N, 26, 12);
 addWarp (HOLLIS, 52, 62, FAR_NORTH_JINDAR_FOREST_N, 26, 12);
 addWarp (HOLLIS, 54, 62, FAR_NORTH_JINDAR_FOREST_N, 26, 12);
 
 
 {
  for (int n = 14; n < 52; n++)
   addTrigger (createTrigger (trigger_story_9, 62, n, HOLLIS, DisableAutoOff));
 }
 /*
 addTrigger (createTrigger (trigger_story_9, 62, 14, HOLLIS, DisableAutoOff));
 addTrigger (createTrigger (trigger_story_9, 62, 16, HOLLIS, DisableAutoOff));
 addTrigger (createTrigger (trigger_story_9, 62, 18, HOLLIS, DisableAutoOff));
 addTrigger (createTrigger (trigger_story_9, 62, 20, HOLLIS, DisableAutoOff));
 addTrigger (createTrigger (trigger_story_9, 62, 22, HOLLIS, DisableAutoOff));
 addTrigger (createTrigger (trigger_story_9, 62, 24, HOLLIS, DisableAutoOff));
 addTrigger (createTrigger (trigger_story_9, 62, 26, HOLLIS, DisableAutoOff));
 addTrigger (createTrigger (trigger_story_9, 62, 28, HOLLIS, DisableAutoOff));
 addTrigger (createTrigger (trigger_story_9, 62, 30, HOLLIS, DisableAutoOff));
 addTrigger (createTrigger (trigger_story_9, 62, 32, HOLLIS, DisableAutoOff));
 addTrigger (createTrigger (trigger_story_9, 62, 34, HOLLIS, DisableAutoOff));
 addTrigger (createTrigger (trigger_story_9, 62, 36, HOLLIS, DisableAutoOff));
 addTrigger (createTrigger (trigger_story_9, 62, 38, HOLLIS, DisableAutoOff));
 addTrigger (createTrigger (trigger_story_9, 62, 40, HOLLIS, DisableAutoOff));
 addTrigger (createTrigger (trigger_story_9, 62, 42, HOLLIS, DisableAutoOff));
 addTrigger (createTrigger (trigger_story_9, 62, 44, HOLLIS, DisableAutoOff));
 addTrigger (createTrigger (trigger_story_9, 62, 46, HOLLIS, DisableAutoOff));
 addTrigger (createTrigger (trigger_story_9, 62, 48, HOLLIS, DisableAutoOff));
 addTrigger (createTrigger (trigger_story_9, 62, 50, HOLLIS, DisableAutoOff));
 addTrigger (createTrigger (trigger_story_9, 62, 52, HOLLIS, DisableAutoOff));
 */



