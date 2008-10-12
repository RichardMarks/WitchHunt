
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

////////////////////////////////////////////////////////////////////////////////
// doCheatMenu.h
//
// void doCheatMenu_LevelUp ();
// void doCheatMenu_LearnAbility ();
// void doCheatMenu_CreateItem ();
// void doCheatMenu_MaxStats ();
// void doCheatMenu_Warp ();
////////////////////////////////////////////////////////////////////////////////

void doCheatMenu_LevelUp ()
{
 kHero.m_strClass = "Cheater";
 
 cout << OFFSET_ENDL;
 
 kHero.giveExperience (1000);
 kHero.canLevel ();
 Common :: pause ("");
}
////////////////////////////////////////////////////////////////////////////////
void doCheatMenu_LearnAbility ()
{
 kHero.m_strClass = "Cheater";
 
 cout << OFFSET_ENDL;
 
 string strAbility = Common :: input ("Enter the ability name: ");
 
 int i = getItemIndexFromString (GLOBAL_ABILITY_MAP, strAbility);
 
 if ( i > -1 )
 {
  kHero.learnAbility (strAbility);
  Common :: pause ("");
 }
 else
 {
  cout << PRINT_OFFSET << "You cannot learn the " << strAbility << " ability.";
  Common :: pause ("");
 }
}
////////////////////////////////////////////////////////////////////////////////
void doCheatMenu_CreateItem ()
{
 kHero.m_strClass = "Cheater";
 
 cout << OFFSET_ENDL;
 
 string strItem = Common :: input ("Enter the item name: ");
 
 int i = getItemIndexFromString (GLOBAL_ITEM_MAP, strItem);
 
 if ( i > -1 )
 {
  kHero.giveItem (strItem, 1, false);
  Common :: pause ("");
 }
 else
 {
  cout << PRINT_OFFSET << "You cannot create an item of type " << strItem << ".";
  Common :: pause ("");
 }
}
////////////////////////////////////////////////////////////////////////////////
void doCheatMenu_MaxStats ()
{
 kHero.m_strClass = "Cheater";
}
////////////////////////////////////////////////////////////////////////////////
void doCheatMenu_Warp ()
{
 kHero.m_strClass = "Cheater";
 
 
 cout << PRINT_OFFSET << "Cheat::Warp" << OFFSET_ENDL;
 string strMapNum = Common :: input ("Enter Destination Map Number: ");
 
 cout << PRINT_OFFSET << "Cheat::Warp" << OFFSET_ENDL;
 string strMapX = Common :: input ("Enter Destination X Coord: ");
 
 cout << PRINT_OFFSET << "Cheat::Warp" << OFFSET_ENDL;
 string strMapY = Common :: input ("Enter Destination Y Coord: ");
 
 int l_m = atoi (strMapNum.c_str ());
 int l_x = atoi (strMapX.c_str ());
 int l_y = atoi (strMapY.c_str ());
 
 kHero.setPosition (l_x, l_y);  // move hero
 iCurrent_map = l_m;            // change map
 updateCurrentLocation ();      // update map
 updateCurrentMapTriggers ();   // update triggers
 
 cout << PRINT_OFFSET << "You raise your hands to the heavens and are warped to a new place.";
 Common :: pause ("");
}
////////////////////////////////////////////////////////////////////////////////

