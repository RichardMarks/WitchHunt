
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

void trigger_story_2 (ENTITY &e, int index)
{
 if (iStoryProgress [1] != 1) return;
 
// PAGE 1
/////////////////////////////////////////////////////////////////
Common :: clearscreen (PRINT_VERTICAL_OFFSET);
{
 string strStory = 
 PRINT_OFFSET +
 "You start feeling a little dizzy, and remember that there are" + OFFSET_ENDL +
 "supplies in the [Shed] left over from when your lovely wife" + OFFSET_ENDL +
 "[Darla] had sprained her ankle in the forest [East] of" + OFFSET_ENDL +
 "your home.\n\n" + OFFSET_ENDL;
 Common :: present (strStory);
} 
Common :: pause (center_press_return);

 iStoryProgress [2] = 1; // story trigger 2 has fired
 disableTrigger (index);      // turn this trigger off
}

