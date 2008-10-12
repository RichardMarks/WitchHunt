
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

void trigger_story_1 (ENTITY &e, int index)
{
// PAGE 1
/////////////////////////////////////////////////////////////////
Common :: clearscreen (PRINT_VERTICAL_OFFSET);
{
 string strStory = 
 PRINT_OFFSET +
 "Stepping from the doorway, the rotted wooden boards creaking" + OFFSET_ENDL +
 "underneath your feet with every step, you make your way to the" + OFFSET_ENDL +
 "street and stand there frozen in place at the sight before you.\n\n" + OFFSET_ENDL;
 Common :: present (strStory);
} 
Common :: pause (center_press_return);

// PAGE 2
///////////////////////////////////////////////////////////////// 
Common :: clearscreen (PRINT_VERTICAL_OFFSET);
{
 string strStory = 
 PRINT_OFFSET +
 "A young woman's body falls limp as some figure steps away" + OFFSET_ENDL +
 "from her. A man races towards the figure from behind you," + OFFSET_ENDL +
 "nearly running into you as he passes.\n\n" + OFFSET_ENDL;
 Common :: present (strStory);
} 
Common :: pause (center_press_return);

// PAGE 3
/////////////////////////////////////////////////////////////////
Common :: clearscreen (PRINT_VERTICAL_OFFSET);
{
 string strStory = 
 PRINT_OFFSET +
 "Raising his hands to the heavens he speaks several words " + OFFSET_ENDL +
 "in a foreign tongue and a white light emanates from " + OFFSET_ENDL +
 "his palms and seem to pierce through the dark figure, " + OFFSET_ENDL +
 "temporarily stunning it. You feel the hairs on the back of " + OFFSET_ENDL +
 "your neck raise as the figure reaches out to the man quickly" + OFFSET_ENDL +
 "advancing on him, lets out a violent scream that shatters " + OFFSET_ENDL +
 "the unusally silent night and viciously attacks the man.\n\n" + OFFSET_ENDL;
 Common :: present (strStory);
} 
Common :: pause (center_press_return);
 
// PAGE 4
/////////////////////////////////////////////////////////////////
Common :: clearscreen (PRINT_VERTICAL_OFFSET);
{
 string strStory = 
 PRINT_OFFSET +
 "Your presence does not go unnoticed and the dark figure " + OFFSET_ENDL +
 "begins to move towards you. You feel as if in a trance;" + OFFSET_ENDL +
 "Unable to move, you feel the figure staring at you, his " + OFFSET_ENDL +
 "dark gaze seems to have power over you.\n\n" + OFFSET_ENDL;
 Common :: present (strStory);
} 
Common :: pause (center_press_return);
 
// PAGE 5
/////////////////////////////////////////////////////////////////
Common :: clearscreen (PRINT_VERTICAL_OFFSET);
{
 string strStory = 
 PRINT_OFFSET +
 "The figure has become more clear to you now, as he slowly" + OFFSET_ENDL +
 "makes his way over to you... Those black eyes; A Vampire!\n\n" + OFFSET_ENDL;
 Common :: present (strStory);
} 
Common :: pause (center_press_return);
 
// PAGE 6
/////////////////////////////////////////////////////////////////
Common :: clearscreen (PRINT_VERTICAL_OFFSET);
{
 string strStory = 
 PRINT_OFFSET +
 "You try to close your eyes, but feel as if you have no " + OFFSET_ENDL +
 "control over your own body. The man shouts another word," + OFFSET_ENDL +
 "and as the Vampire closes in on your helpless body, " + OFFSET_ENDL +
 "it screams once more and vanishes.\n\n" + OFFSET_ENDL;
 Common :: present (strStory);
} 
Common :: pause (center_press_return);

// PAGE 7
/////////////////////////////////////////////////////////////////
Common :: clearscreen (PRINT_VERTICAL_OFFSET);
{
 string strStory = 
 PRINT_OFFSET +
 "The man walks over to you, and introduces himself as Edgar" + OFFSET_ENDL +
 "and tells you of the dangers of being outside during" + OFFSET_ENDL +
 "the Dawn of the Blood. The young woman that lies there" + OFFSET_ENDL +
 "in the street, suddenly rises to her feet and attacks" + OFFSET_ENDL +
 "Edgar. He decapitates her and then falls to the ground," + OFFSET_ENDL +
 "lifeless, all of his life energy had been drained from him.\n\n" + OFFSET_ENDL;
 Common :: present (strStory);
} 
Common :: pause (center_press_return);

// PAGE 8
/////////////////////////////////////////////////////////////////
Common :: clearscreen (PRINT_VERTICAL_OFFSET);
{
 string strStory = 
 PRINT_OFFSET +
 "Horrified, you turn around to run from the gruesome scene" + OFFSET_ENDL +
 "and are caught by surprise as the Vampire stands before" + OFFSET_ENDL +
 "you. You are bitten and close your eyes as everything" + OFFSET_ENDL +
 "turns to darkness....\n\n" + OFFSET_ENDL;
 Common :: present (strStory);
} 
Common :: pause (center_press_return);
 
// PAGE 9
/////////////////////////////////////////////////////////////////
/*
 Innkeeper:
 "You're awake I see."
 
 HERO:
 "Huh? ... Where am I?"
 
 Innkeeper:
 "You are in the Zular Inn my friend."
 
 HERO:
 "... ... ugh ... what a horrible nightmare ..."
 
 Innkeeper:
 "My wife found you in the street unconcious about 4 days ago.
 She pleaded with me to let you stay here.
 Of course I agreed. She has been keeping a watchful eye on you."
 
 HERO:
 "Four days! I've been asleep for four days?"
 
 Innkeeper:
 "Arlia has been worried that you might not wake up.
 And has been tending to you day and night. I sent her home
 this morning, she was feeling ill. Probably from the lack of
 rest. How are you feeling?"
 
 HERO:
 "I feel alright, a little tired, but other than that, I'm fine."
 
 Innkeeper:
 "Please, don't take this the wrong way, but If you are feeling 
 well enough, I must ask that you head home. I need the space for
 paying customers."
 
 HERO:
 "Haha, Of course my good man. Thank you, for your hospitality."
*/
 
{// START DIALOGUE
 std :: string strText = "You're awake I see.";
 Common :: dialogue ("Innkeeper", strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText = "Huh? ... Where am I?";
 Common :: dialogue (kHero.m_strAlias, strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText = "You are in the Zular Inn my friend.";
 Common :: dialogue ("Innkeeper", strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText = "... ... ugh ... what a horrible nightmare ...";
 Common :: dialogue (kHero.m_strAlias, strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText = 
 "My wife found you in the street unconcious about 4 days ago." + OFFSET_ENDL +
 "She pleaded with me to let you stay here." + OFFSET_ENDL +
 "Of course I agreed. She has been keeping a watchful eye on you."; 
 Common :: dialogue ("Innkeeper", strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText = "Four days! I've been asleep for four days?";
 Common :: dialogue (kHero.m_strAlias, strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText =
 "Arlia has been worried that you might not wake up." + OFFSET_ENDL +
 "And has been tending to you day and night. I sent her home" + OFFSET_ENDL +
 "this morning, she was feeling ill. Probably from the lack of" + OFFSET_ENDL +
 "rest. How are you feeling?";
 Common :: dialogue ("Innkeeper", strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText = "I feel alright, a little tired, but other than that, I'm fine.";
 Common :: dialogue (kHero.m_strAlias, strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText =
 "Please, don't take this the wrong way, but If you are feeling " + OFFSET_ENDL +
 "well enough, I must ask that you head home. I need the space for" + OFFSET_ENDL +
 "paying customers. ";
 Common :: dialogue ("Innkeeper", strText, true);
}// END DIALOGUE
 
{// START DIALOGUE
 std :: string strText = "Haha, Of course my good man. Thank you, for your hospitality.";
 Common :: dialogue (kHero.m_strAlias, strText);
}// END DIALOGUE

 Common :: pause (center_press_return);

 iStoryProgress [1] = 1;      // story trigger 1 has fired
 kHero.setPosition (55, 44);  // move hero
 iCurrent_map = EAST_ZULAR;   // change map
 updateCurrentLocation ();    // update map
 updateCurrentMapTriggers (); // update triggers
 disableTrigger (index);      // turn this trigger off
 
}


