
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

void trigger_story_6 (ENTITY &e, int index)
{
 if (iStoryProgress [5] != 1) return;
 
// PAGE 1
/////////////////////////////////////////////////////////////////
Common :: clearscreen (PRINT_VERTICAL_OFFSET);
{
 string strStory =
 PRINT_OFFSET +
 "You see an altar on the far side of the antechamber, you" + OFFSET_ENDL +
 "carefully make your way across the room filled with the" + OFFSET_ENDL +
 "decayed bodies of this forgotten cult." + OFFSET_ENDL +
 "As you reach the altar, you are attacked...\n\n" + OFFSET_ENDL;
 Common :: present (strStory);
}
Common :: pause (center_press_return);
 
 startBattle (3, "Lupinus", "Hell Hound", "Hell Hound");

 
 // if we won the battle, continue otherwise..exit
 if (kHero.m_eState == eDead) return;

// PAGE 2
/////////////////////////////////////////////////////////////////
Common :: clearscreen (PRINT_VERTICAL_OFFSET);
{
 string strStory =
 PRINT_OFFSET +
 "After slaying the beast, you approach the altar once more," + OFFSET_ENDL +
 "and find the [Scroll] bearing a seal matching your ring." + OFFSET_ENDL +
 "You take the [Scroll] and turn to leave the tomb...\n\n" + OFFSET_ENDL;
 Common :: present (strStory);
}
Common :: pause (center_press_return);

// PAGE 3
/////////////////////////////////////////////////////////////////
Common :: clearscreen (PRINT_VERTICAL_OFFSET);
{
 string strStory =
 PRINT_OFFSET +
 "You drop to your knees as all the bodies that filled the" + OFFSET_ENDL +
 "antechamber are ...... gone!?\n\n" + OFFSET_ENDL;
 Common :: present (strStory);
}
Common :: pause (center_press_return);

// PAGE 4
/////////////////////////////////////////////////////////////////
Common :: clearscreen (PRINT_VERTICAL_OFFSET);
{
 string strStory =
 PRINT_OFFSET +
 "You hurry across the room, and run down the halls towards" + OFFSET_ENDL +
 "the entrance. You can hear hundreds of footsteps behind you," + OFFSET_ENDL +
 "and the errie dark chanting continues to grow louder...\n\n" + OFFSET_ENDL;
 Common :: present (strStory);
}
Common :: pause (center_press_return);

 kHero.setPosition (23, 40);  // move hero
 iCurrent_map = WEST_TOK;     // change map
 updateCurrentLocation ();    // update map
 updateCurrentMapTriggers (); // update triggers

 iStoryProgress [6] = 1;      // story trigger 6 has fired 
 disableTrigger (index);      // turn this trigger off
}


