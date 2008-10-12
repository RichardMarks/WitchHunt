
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

void trigger_restoration         (ENTITY &e, int index)
{
 Common :: clearscreen (PRINT_VERTICAL_OFFSET);
 {
  string strStory =
  PRINT_OFFSET +
  "There is a pool of water here.\n\n" + OFFSET_ENDL;
  Common :: present (strStory);
 }

 string strChoice = Common :: input ("Drink the water? ");
 if (strChoice == "y" || strChoice == "Y" || strChoice == "yes" || strChoice == "YES")
 {
  Common :: clearscreen (PRINT_VERTICAL_OFFSET);
  {
   string strStory =
   PRINT_OFFSET +
   "You sip the cool crystal clear water, and feel refreshed.\n\n" + OFFSET_ENDL;
   Common :: present (strStory);
  }
  Common :: pause (center_press_return);

  kHero.giveHp (9999);
  kHero.giveMp (9999);
 } 
}

