
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

addWarp (MURIAS, 28, 8, WORLD_MAP, 14, 52); // north exit
addWarp (MURIAS, 30, 8, WORLD_MAP, 14, 52);
addWarp (MURIAS, 32, 8, WORLD_MAP, 14, 52);
addWarp (MURIAS, 34, 8, WORLD_MAP, 14, 52);

addWarp (MURIAS, 62, 25, WORLD_MAP, 18, 56); // east exit
addWarp (MURIAS, 62, 27, WORLD_MAP, 18, 56);
addWarp (MURIAS, 62, 30, WORLD_MAP, 18, 56);

addTrigger (createTrigger (trigger_inn,     11, 13, MURIAS, DisableAutoOff));
addTrigger (createTrigger (trigger_shop,    24, 26, MURIAS, DisableAutoOff));
addTrigger (createTrigger (trigger_story_4, 34, 45, MURIAS, DisableAutoOff));
addTrigger (createTrigger (trigger_story_8, 30, 45, MURIAS, DisableAutoOff));

