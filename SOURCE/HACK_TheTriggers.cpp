
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

// HACK_TheTriggers.cpp

// this "little" file contains ALL the .cpp files for the
// triggers
// 
// this is to decrease the compile times considerably

// if you add a new cpp file to the project, add it here
// and use Project->options to make sure the new file
// IS NOT SET TO BE COMPILED BY THE COMPILER!
//
// RM - 2:53 PM 03-05-07
//

// the headers that we need

#include "project.h"

#include "generic__warp__trigger.cpp"
#include "generic__itemspawn__trigger.cpp"

#include "trigger_inn.cpp"
#include "trigger_shop.cpp"
#include "trigger_locked_door.cpp"
#include "trigger_restoration.cpp"
#include "trigger_rock_slide.cpp"
#include "trigger_altar.cpp"

#include "trigger_story_1.cpp" // step outside hero's home
#include "trigger_story_2.cpp" // walking inside hero's home
#include "trigger_story_3.cpp" // entering shed
#include "trigger_story_4.cpp" // entering murias church
#include "trigger_story_5.cpp" // entrance to tok
#include "trigger_story_6.cpp" // central tok (BOSS fight with Lupinus)
#include "trigger_story_7.cpp" // escaping tok
#include "trigger_story_8.cpp" // murias church antechamber
#include "trigger_story_9.cpp" // hollis plains warp to hiram (end of demo)


