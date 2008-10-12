
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
/*

// this is a blank story block
// use this to create your story
// displays

Common :: clearscreen (PRINT_VERTICAL_OFFSET);
{
 string strStory = 
 PRINT_OFFSET +
 "" + OFFSET_ENDL +
 "" + OFFSET_ENDL +
 "" + OFFSET_ENDL +
 "" + OFFSET_ENDL +
 "" + OFFSET_ENDL +
 "\n\n" + OFFSET_ENDL;
 Common :: present (strStory);
}
Common :: pause (center_press_return);



*/


///////////////////////////////////////////////////////////////////////
// page 1
Common :: clearscreen (PRINT_VERTICAL_OFFSET);
{
 string strStory = 
 PRINT_OFFSET +
 "Unaware of your surroundings; You lie there, still, peaceful." + OFFSET_ENDL +
 "Silently dreaming of the many wonders of the world. Suddenly, " + OFFSET_ENDL +
 "you are awakened by a blood-curdling scream emanating from" + OFFSET_ENDL +
 "outside the window of your moon-lit bedroom.\n\n" + OFFSET_ENDL;
 Common :: present (strStory);
} 
Common :: pause (center_press_return);

///////////////////////////////////////////////////////////////////////
// page 2
Common :: clearscreen (PRINT_VERTICAL_OFFSET);
{
 string strStory = 
 PRINT_OFFSET +
 "As you grasp frantically for your striking stones to light the" + OFFSET_ENDL +
 "delicate wick of the short candle at your bedside, you begin" + OFFSET_ENDL +
 "to hear voices and another scream. This scream was not as the" + OFFSET_ENDL +
 "last, for this one was not even human. Striking the stones" + OFFSET_ENDL +
 "together causes a blinding flash and floods your room with" + OFFSET_ENDL +
 "white light temporarily.\n\n" + OFFSET_ENDL;
 Common :: present (strStory);
}
Common :: pause (center_press_return);

///////////////////////////////////////////////////////////////////////
// page 3
Common :: clearscreen (PRINT_VERTICAL_OFFSET);
{
 string strStory = 
 PRINT_OFFSET +
 "A familiar smell wafts through the air as the oils in the wick" + OFFSET_ENDL +
 "ignite from the striking stone's hot sparks." + OFFSET_ENDL +
 "You have more light now, though your sight has not yet" + OFFSET_ENDL +
 "adjusted to the change in brightness. You half-blindedly" + OFFSET_ENDL +
 "stumble across your room and gather your few things, then make" + OFFSET_ENDL +
 "your way to the door.\n\n" + OFFSET_ENDL;
 Common :: present (strStory);
}
Common :: pause (center_press_return);

///////////////////////////////////////////////////////////////////////
// page 4
Common :: clearscreen (PRINT_VERTICAL_OFFSET);
{
 string strStory = 
 PRINT_OFFSET +
 "Cautiously you turn the key in the rusted lock, and the door" + OFFSET_ENDL +
 "slowly creaks open. The rest of your home is dark, and the" + OFFSET_ENDL +
 "light from your candle is not enough to cast away the many" + OFFSET_ENDL +
 "shadows that surround you.\n\n" + OFFSET_ENDL;
 Common :: present (strStory);
}
Common :: pause (center_press_return);


///////////////////////////////////////////////////////////////////////
// page 5
Common :: clearscreen (PRINT_VERTICAL_OFFSET);
{
 string strStory = 
 PRINT_OFFSET +
 "You feel a slight chill as a cool breeze blows across your" + OFFSET_ENDL +
 "naked feet, and you soon realize that the door to your home" + OFFSET_ENDL +
 "has been left wide open...\n\n" + OFFSET_ENDL;
 Common :: present (strStory);
}
Common :: pause (center_press_return);



