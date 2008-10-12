
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
// spawnEnemies.cpp
////////////////////////////////////////////////////////////////////////////////

// include the project header
//#include "project.h"

void spawnEnemies ()
{

 // check for this being a safe zone
 // hahahaha
 if (vptMasterMapList.at (iCurrent_location)->eSafe == eMapIsSafe)return;
 

 // alert to a battle 
 cout << PRINT_OFFSET  
      << "YOU HAVE ENCOUNTERED SOME ENEMIES" << endl;
      
 Common :: pause ("");
 Common :: clearscreen ();
 
 // how many spawns
 int iNumOfSpawns = rand() % 3 + 1;  // 1-3
 int iID;
 vector <ENTITY*> vpkEnemies;
 
 // spawn our monsters 
// for (int index = 0; index < iNumOfSpawns; index++)
// {
//  iID = rand () % int(vstrMasterEnemyList.size ()); // get an index for a monster
//  vpkEnemies.push_back (new ENTITY (vstrMasterEnemyList.at (iID)));
// }

 #ifdef DEBUG_BUILD
  cerr << "DEBUG: Spawning " << iNumOfSpawns << " instances of ENTITY" << endl;
 #endif 

 bool bFound = false;
 // spawn our monsters 
 for (int index = 0; index < iNumOfSpawns; index++)
 {
  bFound = false;
  do
  {
   iID = rand() % int(vtMasterEnemyList.size ());
   if ( vtMasterEnemyList.at (iID).strLocation == szMapNames [iCurrent_map] )
   {
    ENTITY* pkEnemy = new ENTITY ();
    pkEnemy->loadTemplate ( vtMasterEnemyList.at (iID).strEnemy );
    pkEnemy->buildGrowthTable ();
    vpkEnemies.push_back (pkEnemy);
    bFound = true;
   }
   else
   {
    #ifdef DEBUG_BUILD
     cerr << "DEBUG: cannot spawn enemy. no enemies for location: " 
     << szMapNames [iCurrent_map] << endl;
    #endif 
   }
    
  }while (bFound == false);
 }
 
 
 #ifdef DEBUG_BUILD
  cerr << "DEBUG: Adjusting Levels " << endl;
 #endif 

 // adjust enemy levels
 adjustLevel (vpkEnemies);
 
 // DO BATTLE!
 INITIATE_BATTLE (rkHero, vpkEnemies);
 
 #ifdef DEBUG_BUILD
  cerr << "DEBUG: Checking for loot dropped by slain enemies..." << endl;
 #endif 

 
 // check for loot
 int iIndex;
 
 for (int index = 0; index < vpkEnemies.size(); index++)
 {
  if (vpkEnemies.at(index)->m_eState == eDead)
  {
   iIndex = rand() % 100;
   if (iIndex >= 60)
   {
    iIndex = rand() % vpkEnemies.at(index)->m_vstrItems.size();
    kHero.giveItem (vpkEnemies.at(index)->m_vstrItems.at(iIndex), 1);
   }
  }
 }
 
 #ifdef DEBUG_BUILD
  cerr << "DEBUG: Cleanup after the battle " << endl;
 #endif 

 // clean up pointers
 vector<ENTITY*> :: iterator iter;
 for (iter = vpkEnemies.begin(); iter != vpkEnemies.end(); ++iter)
 {
  if ( (*iter) )
  {
   delete (*iter);
   (*iter) = NULL; 
  } 
 }
 
}


