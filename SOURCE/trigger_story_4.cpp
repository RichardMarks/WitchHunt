
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

void trigger_story_4 (ENTITY &e, int index)
{
 if (iStoryProgress [3] != 1) return;

 system ("cutscene.exe 1");
 Common :: pause ("");

// PAGE 1
/////////////////////////////////////////////////////////////////
Common :: clearscreen (PRINT_VERTICAL_OFFSET);
{
 string strStory = 
 PRINT_OFFSET +
 "As you are walking up the large, smooth, granite steps of the" + OFFSET_ENDL +
 "[Church], you can smell the incense and candles that are" + OFFSET_ENDL +
 "burning inside. Entering the antechamber you notice that a" + OFFSET_ENDL +
 "ceremony had recently taken place, and see a man clothed in" + OFFSET_ENDL +
 "white kneeling in prayer across the way." + OFFSET_ENDL + OFFSET_ENDL + OFFSET_ENDL +
 "You walk over to the man and quietly speak to him.\n\n" + OFFSET_ENDL;
 Common :: present (strStory);
}
Common :: pause (center_press_return);


{// START DIALOGUE
 std :: string strText = "[Brother Friel]...";
 Common :: dialogue (kHero.m_strAlias, strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText =
 "A long time has past since we have spoken my friend, what" + OFFSET_ENDL +
 "brings you to [Murias]?";
 Common :: dialogue ("Brother Friel", strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText =
 "I'm afraid my visit is not is not a pleasant one." + OFFSET_ENDL +
 "Let me explain...";
 Common :: dialogue (kHero.m_strAlias, strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText =
 "...and so that is the reason I have come to [Murias]," + OFFSET_ENDL +
 "to seek your aid.";
 Common :: dialogue (kHero.m_strAlias, strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText =
 "Indeed a truly disturbing tale " +
 kHero.m_strAlias +
 "! Show me the mark. I" + OFFSET_ENDL +
 "will do what I can.";
 Common :: dialogue ("Brother Friel", strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText = "I feel a burning sensation in the sunlight.";
 Common :: dialogue (kHero.m_strAlias, strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText =
 "I see, come, we must seek the knowledge of the ancient" + OFFSET_ENDL +
 "texts.";
 Common :: dialogue ("Brother Friel", strText);
}// END DIALOGUE

Common :: pause (center_press_return);

// PAGE 2
/////////////////////////////////////////////////////////////////
Common :: clearscreen (PRINT_VERTICAL_OFFSET);
{
 string strStory =
 PRINT_OFFSET +
 "[Brother Friel] leads you through the [Church] and down an" + OFFSET_ENDL +
 "old stone spiral staircase to the [Catacombs] beneath the" + OFFSET_ENDL +
 "[Church]. The halls are lit with a calming blue light, that" + OFFSET_ENDL +
 "seems to come out of nowhere. You arrive at a large door" + OFFSET_ENDL +
 "that [Brother Friel] opens with a small brass key.\n\n" + OFFSET_ENDL;
 Common :: present (strStory);
}
Common :: pause (center_press_return);

{// START DIALOGUE
 std :: string strText =
 "The [Forgotten Library]. A tomb of many tomes written by" + OFFSET_ENDL +
 "the elder clerics.";
 Common :: dialogue ("Brother Friel", strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText = "I see, and the cure is to be found here?";
 Common :: dialogue (kHero.m_strAlias, strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText =
 "I wish it were that easy, " +
 kHero.m_strAlias +
 "." + OFFSET_ENDL +
 "Alas, I must have some time to find a cure.";
 Common :: dialogue ("Brother Friel", strText);
}// END DIALOGUE

 Common :: pause (center_press_return);
 Common :: clearscreen (PRINT_VERTICAL_OFFSET);
 kHero.rest ();
 Common :: pause (center_press_return);

// PAGE 3
/////////////////////////////////////////////////////////////////
Common :: clearscreen (PRINT_VERTICAL_OFFSET);
{
 string strStory =
 PRINT_OFFSET +
 "You awaken at the clattering of books falling to the ground.\n\n" + OFFSET_ENDL;
 Common :: present (strStory);
}
Common :: pause (center_press_return);

{// START DIALOGUE
 std :: string strText = "[Brother Friel]?";
 Common :: dialogue (kHero.m_strAlias, strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText =
 "Ah, " + kHero.m_strAlias + 
 ", I have found something" + OFFSET_ENDL +
 "that may prove to be useful to you.";
 Common :: dialogue ("Brother Friel", strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText = "The cure?";
 Common :: dialogue (kHero.m_strAlias, strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText = "This tome speaks of a [Scroll] of healing concoctions.";
 Common :: dialogue ("Brother Friel", strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText = "And the cure is listed on this scroll?";
 Common :: dialogue (kHero.m_strAlias, strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText = "A bit impatient today aren't we, " + kHero.m_strAlias + "?";
 Common :: dialogue ("Brother Friel", strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText = "You would be too!";
 Common :: dialogue (kHero.m_strAlias, strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText =
 "Listen to me " + kHero.m_strAlias + 
 ", you must find" + OFFSET_ENDL +
 "this scroll and return to me.";
 Common :: dialogue ("Brother Friel", strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText = "How am I to find this scroll?";
 Common :: dialogue (kHero.m_strAlias, strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText =
 "Head [East] of [Murias] to the [Jindar Forest]." + OFFSET_ENDL +
 "Search the forest for a stone structure." + OFFSET_ENDL +
 "You will find the entrance to a [Tomb] holding many" + OFFSET_ENDL +
 "ancient scrolls. You should be able to find the scroll" + OFFSET_ENDL +
 "in the tomb." + OFFSET_ENDL + OFFSET_ENDL +
 "Look for a [Scroll] bearing the seal of this ring.";
 Common :: dialogue ("Brother Friel", strText);
}// END DIALOGUE

Common :: pause (center_press_return);

// PAGE 4
/////////////////////////////////////////////////////////////////
Common :: clearscreen (PRINT_VERTICAL_OFFSET);
{
 string strStory =
 PRINT_OFFSET +
 "The cleric hands you a ring with a strange symbol on it.\n\n" + OFFSET_ENDL;
 Common :: present (strStory);
}
Common :: pause (center_press_return);

{// START DIALOGUE
 std :: string strText =
 "I shall depart at once. Thank you for your help." + OFFSET_ENDL +
 "I shall return.";
 Common :: dialogue (kHero.m_strAlias, strText, true);
}// END DIALOGUE

 iStoryProgress [4] = 1;             // story trigger 4 has fired
 kHero.giveItem ("Solomon Ring", 1); // give hero murias amulet
 Common :: pause (center_press_return);
 disableTrigger (index);      // turn this trigger off
}


