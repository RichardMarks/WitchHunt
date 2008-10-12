
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


// special trigger that warps from one map to another map
//

void generic__warp__trigger (ENTITY &e, int index)
{
 TRIGGER* tTrigger = vptMasterTriggerList.at (index);
 
 #ifdef DEBUG_BUILD
 /*
 cerr << "DEBUG: generic warp trigger" << endl;
 cerr << "DEBUG: Map [" << tTrigger->iMap << "] to Map [" 
                        << tTrigger->iTargetMap << "]" << endl;
 cerr << "DEBUG: (" << tTrigger->iXpos << ", " << tTrigger->iYpos 
      << ") - ("    << tTrigger->iTargetXpos << ", " 
      << tTrigger->iTargetYpos << ")" << endl; 
 Common :: pause (center_press_return);
 */
 #endif
 
 
 
 // change map
 iCurrent_map = tTrigger->iTargetMap;
 
 // move hero
 kHero.setPosition (tTrigger->iTargetXpos, tTrigger->iTargetYpos);
 
 // update triggerlists
 updateCurrentLocation ();
 updateCurrentMapTriggers ();
 
 // wham we should be warped...
 
 return;
}


