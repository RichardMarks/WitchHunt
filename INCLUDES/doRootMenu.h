
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
// doRootMenu.h
//
// void doGameMenu ();
// void doItemsMenu ();
// void doAbilitiesMenu ();
// void doCheatMenu ();
////////////////////////////////////////////////////////////////////////////////

void doGameMenu ()
{
 bool bGameMenu = true;
 string strChoice;
 while (bGameMenu)
 {
  Common :: clearscreen (PRINT_VERTICAL_OFFSET);
 
  cout << PRINT_OFFSET 
       << "1. Manage Items" << OFFSET_ENDL << OFFSET_ENDL
       << "2. Manage Abilities" << OFFSET_ENDL << OFFSET_ENDL
       << "3. View Status" << OFFSET_ENDL << OFFSET_ENDL
       << "4. Rest" << OFFSET_ENDL << OFFSET_ENDL
       << "5. Save Game" << OFFSET_ENDL << OFFSET_ENDL
       << "6. Load Game" << OFFSET_ENDL << OFFSET_ENDL
       << "0. Return to Game" << OFFSET_ENDL << OFFSET_ENDL;
  
  strChoice = Common :: input ("Action: ");
  
  if (strChoice == "0") bGameMenu = false;
  if (strChoice == "1") doItemsMenu ();
  if (strChoice == "2") doAbilitiesMenu ();
  if (strChoice == "3") doGameMenu_Status ();
  if (strChoice == "4") doGameMenu_Rest ();
  if (strChoice == "5") doGameMenu_Save ();
  if (strChoice == "6") doGameMenu_Load ();
  // hidden cheat menu option
  if (strChoice == "uber vestigium 1984") doCheatMenu ();
  
  // testers menu
  #if defined(DEBUG_BUILD)
   #if defined(MAP_TESTER)
    if (strChoice == "tester:storychange")
    {
     Common :: clearscreen (PRINT_VERTICAL_OFFSET);
     cout << PRINT_OFFSET;
     for (int n = 0; n < 10; n++)
      cout << "[" << n << "] = " << iStoryProgress [n] << OFFSET_ENDL;
     string strCh = Common :: input ("Story To Change: ");
     int l_ch = atoi (strCh.c_str ());
     if (l_ch < C_NUM_STORY_EVENTS)
     {
      if (iStoryProgress [l_ch] != 1)
       iStoryProgress [l_ch] = 1;
      else
       iStoryProgress [l_ch] = 0;
     }  
    }
    if (strChoice == "tester:mapchange")
    {
     Common :: clearscreen (PRINT_VERTICAL_OFFSET);
     cout << PRINT_OFFSET;
     string strMapNum = Common :: input ("Enter Destination Map Number (-1 to cancel): ");
     cout << PRINT_OFFSET;
     string strMapX   = Common :: input ("Enter Destination X Coord (-1 to cancel): ");
     cout << PRINT_OFFSET;
     string strMapY   = Common :: input ("Enter Destination Y Coord (-1 to cancel): ");
     if (strMapNum == "-1" || strMapX == "-1" || strMapY == "-1")
     {
     }
     else
     {
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
    }
   #endif
  #endif  
  //
   
 }
}
////////////////////////////////////////////////////////////////////////////////
void doItemsMenu ()
{
 bool bItemsMenu = true;
 string strChoice;
 while (bItemsMenu)
 {
  Common :: clearscreen (PRINT_VERTICAL_OFFSET);
  kHero.showInventory ();
  
  cout << OFFSET_ENDL
       << "1. Use Item  \t\t"
       << "2. Drop Item     " << OFFSET_ENDL << OFFSET_ENDL
       << "3. Equip Item\t\t"
       << "4. Unequip Item  " << OFFSET_ENDL << OFFSET_ENDL
       << "0. Cancel" 
       << OFFSET_ENDL
       << OFFSET_ENDL;
  
  strChoice = Common :: input ("Action: ");
  
  if (strChoice == "0") bItemsMenu = false;
  if (strChoice == "1") doItemsMenu_UseItem ();
  if (strChoice == "2") doItemsMenu_DropItem ();
  if (strChoice == "3") doItemsMenu_EquipItem ();
  if (strChoice == "4") doItemsMenu_UnequipItem ();
 }
}
////////////////////////////////////////////////////////////////////////////////
void doAbilitiesMenu ()
{
 bool bAbilitiesMenu = true;
 string strChoice;
 while (bAbilitiesMenu)
 {
  Common :: clearscreen (PRINT_VERTICAL_OFFSET);
  kHero.showAbilities ();
  cout << OFFSET_ENDL
       << "1. Use Ability  \t\t"
       << "0. Cancel           " 
       << OFFSET_ENDL
       << OFFSET_ENDL;
  
  strChoice = Common :: input ("Action: ");
  
  if (strChoice == "0") bAbilitiesMenu = false;
  if (strChoice == "1") doAbilitiesMenu_UseAbility ();
 }
}
////////////////////////////////////////////////////////////////////////////////
static inline void strto1337 (std :: string str)
{
 for (int ch = 0; ch < str.size (); ch++){printf ("%02X ", str.at (ch));}
}
void doCheatMenu ()
{
 bool bCheatMenu = true;
 string strChoice;
 while (bCheatMenu)
 {
  Common :: clearscreen (PRINT_VERTICAL_OFFSET);

/*
  cout << PRINT_OFFSET 
       << "D38UG R00/\\/\\" << OFFSET_ENDL << OFFSET_ENDL
       << "1. 13v315" << OFFSET_ENDL << OFFSET_ENDL
       << "2. 57475" << OFFSET_ENDL << OFFSET_ENDL
       << "3. \\/\\/4rp" << OFFSET_ENDL << OFFSET_ENDL
       << "4. 48!1!7y" << OFFSET_ENDL << OFFSET_ENDL
       << "5. !7!/\\/\\" << OFFSET_ENDL << OFFSET_ENDL
       << "0. Cancel" << OFFSET_ENDL
       << OFFSET_ENDL;
*/

  string strMenuOptions [] =
  {
   "  D E B U G R O O M ",
   " L eve     I     l ",
   " S tat     C     s ",
   " W ar      H     p ",
   " L ear    MARKS  n ",
   " C reat    R     e ",
   " C ance    D     l ",
  };

  cout << PRINT_OFFSET; strto1337 (strMenuOptions[0]); cout << OFFSET_ENDL << OFFSET_ENDL;

  for (int n = 1; n < sizeof(strMenuOptions)/sizeof(string); n++)
  { 
   cout << n << ". ";
   strto1337 (strMenuOptions[n]);
   cout << OFFSET_ENDL << OFFSET_ENDL;
  } 

  strChoice = Common :: input ("1337: ");
  
  if (strChoice == "6") bCheatMenu = false;
  if (strChoice == "1") doCheatMenu_LevelUp ();
  if (strChoice == "2") doCheatMenu_MaxStats ();
  if (strChoice == "3") doCheatMenu_Warp ();
  if (strChoice == "4") doCheatMenu_LearnAbility ();
  if (strChoice == "5") doCheatMenu_CreateItem ();
 }
}

////////////////////////////////////////////////////////////////////////////////

