
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
//#include "project.h"

void trigger_story_5 (ENTITY &e, int index)
{
 if (iStoryProgress [4] != 1) 
 {
  Common :: clearscreen (PRINT_VERTICAL_OFFSET);
  {
   string strStory =
   PRINT_OFFSET +
   "Approaching the archway, you feel pushed away...\n\n" + OFFSET_ENDL;
   Common :: present (strStory);
  }
  Common :: pause (center_press_return);
  kHero.setPosition (kHero.m_iXpos, kHero.m_iYpos + 2);
  return;
 } 
 
 // this trigger needs to be persistent
 
 // and only show the story segment if it has not been shown

 if (iStoryProgress [5] != 1)
 {
// PAGE 1
/////////////////////////////////////////////////////////////////
  Common :: clearscreen (PRINT_VERTICAL_OFFSET);
  {
   string strStory =
   PRINT_OFFSET +
   "You approach the hauntingly familiar archway of the" + OFFSET_ENDL +
   "[Tomb of Knowledge] and feel a chill down your spine as" + OFFSET_ENDL +
   "several hundred bats fly across the black sky overhead." + OFFSET_ENDL +
   "You can feel the presence of someone nearby. Ignoring" + OFFSET_ENDL +
   "your inner fears you walk inside the tomb.\n\n" + OFFSET_ENDL;
   Common :: present (strStory);
  }
  Common :: pause (center_press_return);

// PAGE 2
/////////////////////////////////////////////////////////////////
  Common :: clearscreen (PRINT_VERTICAL_OFFSET);
  {
   string strStory =
   PRINT_OFFSET +
   "You can hear an errie chanting in the distance...\n\n" + OFFSET_ENDL;
   Common :: present (strStory);
  }
  Common :: pause (center_press_return);
 
  iStoryProgress [5] = 1;      // story trigger 5 has fired
 }
 
 kHero.setPosition (31, 59);  // move hero
 iCurrent_map = SOUTH_TOK;    // change map
 updateCurrentLocation ();    // update map
 updateCurrentMapTriggers (); // update triggers
}


