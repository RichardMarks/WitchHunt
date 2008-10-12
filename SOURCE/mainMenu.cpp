
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
// mainMenu.cpp
////////////////////////////////////////////////////////////////////////////////

// include the project header
//#include "project.h"

void mainMenu ()
{
 bool bMainMenu = true;
 
 while (bMainMenu)
 {
  displayMainMenu ();
  
  string strChoice = Common :: input(": ");
  
  if (strChoice == "n" || strChoice == "N")
  {
   newGame ();
  } 
  else if (strChoice == "l" || strChoice == "L")
  {
   
   //------------------------------------------------------------
   // reset storyline flags 
 #ifdef DEBUG_BUILD
  cerr << "DEBUG: Resetting Storyline Flags" << endl;
 #endif 
 for (int m = 0; m < C_NUM_STORY_EVENTS; m++)
 {
  if (m == 0)
  {
   iStoryProgress[m] = 1;
  }
  else
  {
   iStoryProgress[m] = 0;
  }
 }
 
 // rebuild trigger list
 buildMasterTriggerList ();
 
 // reset hero inventory
 kHero.clearInventory ();
 
 // reset hero ability list
 kHero.clearAbilityList ();
  
 // reload hero template
 kHero.loadTemplate ("Hero");

 // rebuild growth table
 kHero.buildGrowthTable ();

 // position hero in his home (needs coords from real game map)
 kHero.setPosition (34, 60); // something like that...
 
 loadGame ();
 
 // start the gameplay
 mainGame ();
   //////////////////////////////////////////////////////////////
   
  } 
  else if (strChoice == "q" || strChoice == "Q")
  {
   bMainMenu = false;
  } 
  else if (strChoice == "c" || strChoice == "C") 
  {
   displayCredits ();
  } 
  
 } // end while
 displayCredits ();
}

