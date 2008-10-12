
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

void trigger_story_9             (ENTITY &e, int index)
{
 // this trigger needs to be persistent
 // as it serves as a warp to hiram
  
 if (iStoryProgress [8] != 1)
 {
  // attempting to enter hiram before the storyline has told you to
  // results in a guard telling you that you are not permitted entry
  // to the city.
  
{// START DIALOGUE
 std :: string strText = "You are not permitted to enter the Grand City of Hiram.";
 Common :: dialogue ("Hiram Guard", strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText = "Aww man...";
 Common :: dialogue (kHero.m_strAlias, strText);
}// END DIALOGUE

  Common :: pause (center_press_return);
  return;
 }
 
 // if the storyline has told you to go to hiram, end the demo 
 // hahahaha so much work and your journey is over! mwahahahaha!
 
// PAGE 1
/////////////////////////////////////////////////////////////////
Common :: clearscreen (PRINT_VERTICAL_OFFSET);
{
 string strStory =
 PRINT_OFFSET +
 "Walking up to the gates of the Grand City of Hiram, you" + OFFSET_ENDL +
 "are approached by a man dressed in black.\n\n" + OFFSET_ENDL;
 Common :: present (strStory);
}
Common :: pause (center_press_return);

{// START DIALOGUE
 std :: string strText =
 "You have traveled far my friend, but I'm afraid this is where" + OFFSET_ENDL +
 "your journey comes to an end.";
 Common :: dialogue ("Unknown Man", strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText = "Who the hell are you?";
 Common :: dialogue (kHero.m_strAlias, strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText =
 "I am Uber Vestigium." + OFFSET_ENDL +
 "Thank you for playing.";
 Common :: dialogue ("Unknown Man", strText, true);
}// END DIALOGUE

// PAGE 2
/////////////////////////////////////////////////////////////////
Common :: clearscreen (PRINT_VERTICAL_OFFSET);
{
 string strStory =
 PRINT_OFFSET +
 "Team CCPS would like to thank everyone involved in the" + OFFSET_ENDL +
 "development of this demo for their talents, time and efforts.\n\n" + OFFSET_ENDL;
 Common :: present (strStory);
}
Common :: pause (center_press_return);

// CREDITS

{// START DIALOGUE
 std :: string strText =
 "Richard Marks" + OFFSET_ENDL +
 "Rafael Hermosillo";
 Common :: dialogue ("Project Management", strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText =
 "Richard Marks" + OFFSET_ENDL +
 "Rafael Hermosillo" + OFFSET_ENDL +
 "Jeff Stagg" + OFFSET_ENDL +
 "Melissa Montalbano" + OFFSET_ENDL +
 "Thomas W. Byrne III";
 Common :: dialogue ("Designers", strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText =
 "Richard Marks" + OFFSET_ENDL +
 "Rafael Hermosillo";
 Common :: dialogue ("Programmers", strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText =
 "Richard Marks" + OFFSET_ENDL +
 "Rafael Hermosillo";
 Common :: dialogue ("Artists", strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText =
 "Richard Marks" + OFFSET_ENDL +
 "Rafael Hermosillo" + OFFSET_ENDL +
 "Jeff Stagg" + OFFSET_ENDL +
 "Melissa Montalbano" + OFFSET_ENDL +
 "Thomas W. Byrne III";
 Common :: dialogue ("Testers", strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText =
 "In no particular order," + OFFSET_ENDL +
 "DarkStarBane, Unknown, DarkBllade, Scorpio9, Echo, Bjorn" + OFFSET_ENDL +
 "Mom, Dad, God" + OFFSET_ENDL +
 "Anyone else that I have forgotten to mention.";
 Common :: dialogue ("Thanks", strText);
}// END DIALOGUE
 
 // SAVE
 Common :: pause (center_press_return);
 
 // GAME OVER
 iStoryProgress [0] = 255;
}

