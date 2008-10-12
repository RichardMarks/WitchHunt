
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

void trigger_story_3 (ENTITY &e, int index)
{
 if (iStoryProgress [2] != 1) return;
 
// PAGE 1
/////////////////////////////////////////////////////////////////
Common :: clearscreen (PRINT_VERTICAL_OFFSET);
{
 string strStory = 
 PRINT_OFFSET +
 "Stepping up to the wooden door of the small [Shed], you pull " + OFFSET_ENDL +
 "on the rusted handle with all your might. The door does not " + OFFSET_ENDL +
 "budge. You look around the area and notice an axe nearby. " + OFFSET_ENDL +
 "Taking the axe and destroying the door to the [Shed] you step " + OFFSET_ENDL +
 "inside.\n\n" + OFFSET_ENDL;
 Common :: present (strStory);
}
Common :: pause (center_press_return);

// PAGE 2
/////////////////////////////////////////////////////////////////
Common :: clearscreen (PRINT_VERTICAL_OFFSET);
{
 string strStory = 
 PRINT_OFFSET +
 "The inside of the [Shed] is very poorly lit and smells of many " + OFFSET_ENDL +
 "herbs. Ahh how you used to love drinking Herbal Tea with " + OFFSET_ENDL +
 "[Darla]. You see a small medical supply case on the bench. " + OFFSET_ENDL +
 "You decide that it would be a good idea to take it with you. " + OFFSET_ENDL +
 "There are a few old sealed bottles of Herbal Tea on a shelf " + OFFSET_ENDL +
 "above the bench. You place a few of them in a burlap sack that " + OFFSET_ENDL +
 "you found on the floor of the [Shed].\n\n" + OFFSET_ENDL;
 Common :: present (strStory);
}
Common :: pause (center_press_return);
  
// PAGE 3
/////////////////////////////////////////////////////////////////
Common :: clearscreen (PRINT_VERTICAL_OFFSET);
{
 string strStory = 
 PRINT_OFFSET +
 "You turn to leave the [Shed] and you spot a silver Amulet " + OFFSET_ENDL +
 "hanging near the entrance.  Taking the Amulet, you remember " + OFFSET_ENDL +
 "the man who gave you the relic...\n\n" + OFFSET_ENDL;
 Common :: present (strStory);
}
Common :: pause (center_press_return);


{// START DIALOGUE
 std :: string strText = "Brother Friel!";
 Common :: dialogue (kHero.m_strAlias, strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText = "If anyone would know of a way to help me, it would be him!";
 Common :: dialogue (kHero.m_strAlias, strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText = "Now if only I could remember where he would stay this time" + OFFSET_ENDL +
 "of year...";
 Common :: dialogue (kHero.m_strAlias, strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText = "Ohh yeah, [Brother Friel] should be at the [Church] in" + OFFSET_ENDL +
 "[Murias]!";
 Common :: dialogue (kHero.m_strAlias, strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText = "[Murias] is not too far [South] of [Zular].";
 Common :: dialogue (kHero.m_strAlias, strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText = "It is starting to get dark, I had better get moving.";
 Common :: dialogue (kHero.m_strAlias, strText);
}// END DIALOGUE


 iStoryProgress [3] = 1;              // story trigger 3 has fired
 kHero.giveItem ("Bandage", 5);       // give hero 5 bandages
 kHero.giveItem ("Tea", 3);           // give hero 3 teas
 kHero.giveItem ("Murias Amulet", 1); // give hero murias amulet
 Common :: pause (center_press_return);
 disableTrigger (index);      // turn this trigger off
}


