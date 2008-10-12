
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
// newGame.cpp

// reset storyline flags 
// rebuild trigger list
// reset hero inventory
// reset hero ability list
// reload hero template
// rebuild growth table
// display introduction story
// prompt the player to name the hero
// position hero in his home
// start the gameplay
////////////////////////////////////////////////////////////////////////////////

// include the project header
//#include "project.h"

void newGame ()
{
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

 // display introduction story
 #ifndef DEBUG_BUILD
 #include "story_introduction.h"
 #endif
 
 bool bValidName = false;
 string strAlias = "";
 while (!bValidName)
 {
  // prompt the player to name the hero
  Common :: clearscreen (PRINT_VERTICAL_OFFSET);
 
  Common :: center ("What is thy name traveler?");
 
  cout << OFFSET_ENDL << OFFSET_ENDL;
      
  strAlias = Common :: input (": ");
  
  if ( (strAlias != "" ) && (strAlias.size () < 12))
  {
   bValidName = true;
  } 
  else 
  {
   cout << OFFSET_ENDL;
   Common :: pause ("Invalid Name. Try again.");
  } 
 }
 kHero.m_strAlias = strAlias; 
 
 // position hero in his home (needs coords from real game map)
 kHero.setPosition (34, 60); // something like that...
 
 // start the gameplay
 mainGame ();
 
}

