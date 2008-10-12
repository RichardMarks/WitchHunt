
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

void trigger_story_7 (ENTITY &e, int index)
{
 if (iStoryProgress [6] != 1) return;
 
 // PAGE 1
/////////////////////////////////////////////////////////////////
Common :: clearscreen (PRINT_VERTICAL_OFFSET);
{
 string strStory =
 PRINT_OFFSET +
 "As you reach the entrance, you are attacked!\n\n" + OFFSET_ENDL;
 Common :: present (strStory);
}
Common :: pause (center_press_return);

 // FORCED BATTLE WITH 4 Undead
 startBattle (4, "Undead", "Undead", "Undead", "Undead");

 // if we won the battle, continue otherwise..exit
 if (kHero.m_eState == eDead) return;

// PAGE 2
/////////////////////////////////////////////////////////////////
Common :: clearscreen (PRINT_VERTICAL_OFFSET);
{
 string strStory =
 PRINT_OFFSET +
 "You fight your way through the hordes of undead that block" + OFFSET_ENDL +
 "your path to the exit...\n\n" + OFFSET_ENDL;
 Common :: present (strStory);
}
Common :: pause (center_press_return);

 // FORCED BATTLE WITH 4 Undead
 startBattle (4, "Undead", "Undead", "Undead", "Undead");
 
 // if we won the battle, continue otherwise..exit
 if (kHero.m_eState == eDead) return;

// PAGE 3
/////////////////////////////////////////////////////////////////
Common :: clearscreen (PRINT_VERTICAL_OFFSET);
{
 string strStory =
 PRINT_OFFSET +
 "You take the risk to rush through the undead denizens and" + OFFSET_ENDL +
 "quickly increase the distance between you and the tomb.\n\n" + OFFSET_ENDL;
 Common :: present (strStory);
}
Common :: pause (center_press_return);

{// START DIALOGUE
 std :: string strText = "*pant* *pant* I... must ... return *gasp* to [Brother Friel]!";
 Common :: dialogue (kHero.m_strAlias, strText, true);
}// END DIALOGUE


 kHero.giveItem ("Ancient Scroll", 1, false);
 
 iStoryProgress [7] = 1;
 kHero.setPosition (40, 36);             // move hero
 iCurrent_map = EAST_JINDAR_FOREST_S;    // change map
 updateCurrentLocation ();               // update map
 updateCurrentMapTriggers ();            // update triggers
 disableTrigger (index);      // turn this trigger off
}





