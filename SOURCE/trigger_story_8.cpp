
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

void trigger_story_8 (ENTITY &e, int index)
{
 if (iStoryProgress [7] != 1) return;

// PAGE 1
/////////////////////////////////////////////////////////////////
Common :: clearscreen (PRINT_VERTICAL_OFFSET);
{
 string strStory =
 PRINT_OFFSET +
 "Reaching the [Church], you race up the steps into the" + OFFSET_ENDL +
 "antechamber...\n\n" + OFFSET_ENDL;
 Common :: present (strStory);
}
Common :: pause (center_press_return);

{// START DIALOGUE
 std :: string strText =
 kHero.m_strAlias + 
 "! Have you found the [Scroll]?";
 Common :: dialogue ("Brother Friel", strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText =
 "I have it here. There is something I must tell you about" + OFFSET_ENDL +
 "the [Tomb of Knowledge].";
 Common :: dialogue (kHero.m_strAlias, strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText = "You were attacked by the dead sprits of the forgotten.";
 Common :: dialogue ("Brother Friel", strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText = "H..How .... could you have known?";
 Common :: dialogue (kHero.m_strAlias, strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText =
 "Hell's gate has been opened, there are legions of" + OFFSET_ENDL +
 "demons walking the earth as we speak.";
 Common :: dialogue ("Brother Friel", strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText = "Give me the [Scroll].";
 Common :: dialogue ("Brother Friel", strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText = "... ... ...";
 Common :: dialogue (kHero.m_strAlias, strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText =
 "Alas, I cannot translate all of these inscriptions but" + OFFSET_ENDL +
 "there is one who I believe can help.";
 Common :: dialogue ("Brother Friel", strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText = "Tell me, how did you know I was attacked in the tomb?";
 Common :: dialogue (kHero.m_strAlias, strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText =
 "I was watching. Remember, I'm not only a cleric my boy." + OFFSET_ENDL +
 "I am an alchemist.";
 Common :: dialogue ("Brother Friel", strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText =
 "Alchemy! Of course! You used a sight spell," + OFFSET_ENDL +
 "heh I thought I was being watched.";
 Common :: dialogue (kHero.m_strAlias, strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText = "So, what is going on?";
 Common :: dialogue (kHero.m_strAlias, strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText =
 "There is a dark soul conjuring spirits and raising the" + OFFSET_ENDL +
 "dead in these lands. You must make haste!";
 Common :: dialogue ("Brother Friel", strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText =
 "Undead, demons, dark souls... ... ... Wait, haste!?" + OFFSET_ENDL +
 "Where am I going!?";
 Common :: dialogue (kHero.m_strAlias, strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText =
 "You must seek the help of [Forlis Hungraz]." + OFFSET_ENDL +
 "A master of the forgotten tongue.";
 Common :: dialogue ("Brother Friel", strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText =
 "He should be able to help translate the [Scroll]." + OFFSET_ENDL +
 "Hurry now, I shall be waiting for you.";
 Common :: dialogue ("Brother Friel", strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText = "Where am I to find this [Forlis Hungraz]?";
 Common :: dialogue (kHero.m_strAlias, strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText = "You must go to [Hiram]. Far [North] of [Jindar].";
 Common :: dialogue ("Brother Friel", strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText = "Take these supplies with you.";
 Common :: dialogue ("Brother Friel", strText);
}// END DIALOGUE

 kHero.giveItem ("Bandage", 8);

{// START DIALOGUE
 std :: string strText =
 "Now, go to [Hiram]." + OFFSET_ENDL +
 "Have [Forlis Hungraz] translate the [Scroll]!";
 Common :: dialogue ("Brother Friel", strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText = "I shall return.";
 Common :: dialogue (kHero.m_strAlias, strText);
}// END DIALOGUE
 
 iStoryProgress [8] = 1;
 disableTrigger (index);      // turn this trigger off

}


