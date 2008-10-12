
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
// buildMasterTriggerList.cpp
////////////////////////////////////////////////////////////////////////////////

void buildMasterTriggerList ()
{
 #ifdef DEBUG_BUILD
  cerr << "DEBUG: Building Master Trigger List" << endl;
 #endif
 // always clear the list first
 clearMasterTriggerList ();

// TRIGGER USAGE GUIDE:
// addTrigger (createTrigger (func,x,y,map)); // default autooff true default armed true
// addTrigger (createTrigger (func,x,y,map,DisableAutoOff)); // autoff false default armed true
// addTrigger (createTrigger (func,x,y,map,DisableAutoOff,DisarmedTrigger)); // autooff false armed false

 #include "zular_triggers.h"
 #include "world_map_triggers.h"
 #include "balmant_triggers.h"
 #include "radnine_triggers.h"
 #include "murias_triggers.h"
 #include "jindar_triggers.h"
 #include "tok_triggers.h"
 #include "hollis_triggers.h"
 #include "ginath_triggers.h"
 
 updateCurrentMapTriggers ();
 
}

