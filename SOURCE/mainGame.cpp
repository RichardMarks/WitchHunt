
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
// mainGame.cpp
//
// void mainGame ()
// void checkForEvent (ENTITY &e)
////////////////////////////////////////////////////////////////////////////////

// include the project header
//#include "project.h"

void mainGame ()
{
 
 bool bPlaying = true;
 
 while (bPlaying != false)
 { 
  // check for events
  checkForEvent (rkHero);
  
  // some events may end the game
  if (iStoryProgress [0] == 255) bPlaying = false;
    
  // check for dead party
  if (kHero.m_eState == eDead)
  {
   bPlaying = false;
   displayGameover ();
  } 
  else
  {
   // display the main viewing screen here
   Common :: clearscreen (PRINT_VERTICAL_OFFSET);
  
   displayMinimap ();
  
   cout << endl << OFFSET_ENDL;
   
   // NEW KEYBOARD DRIVER
   Common :: KEYDRIVER kKeyboard;
   kKeyboard.install ();
   kKeyboard.getKey ();
   if (kKeyboard.escKey ())     { bPlaying = false; }
   if (kKeyboard.upArrow ())    { navigateHero (eNorth, eSouth); }
   if (kKeyboard.downArrow ())  { navigateHero (eSouth, eNorth); }
   if (kKeyboard.leftArrow ())  { navigateHero (eWest, eEast); }
   if (kKeyboard.rightArrow ()) { navigateHero (eEast, eWest); }
   if (kKeyboard.tabKey ())     
   {
    string strUseraction = Common :: input ("Action: ");  
    #include "maingameProcessCommands.h"
   }
   
  } // end else party not dead
 }  // end while bPlaying
}

////////////////////////////////////////////////////////////////////////////////
// checks to see if the ENTITY e has moved onto an event TRIGGER
////////////////////////////////////////////////////////////////////////////////
void checkForEvent (ENTITY &e)
{
 /*
 for (int index = 0; index < int(vptCurrentTriggers.size ()); index++)
 {
  if (vptCurrentTriggers.at(index)->iXpos == e.m_iXpos)
  {
   if (vptCurrentTriggers.at(index)->iYpos == e.m_iYpos)
   {
    if (vptCurrentTriggers.at(index)->bArmed)
    {
     vptMasterTriggerList.at(index)->func (e);
     vptMasterTriggerList.at(index)->bArmed = false;
    } // end if armed
   } // end if y
  } // end if x
 } // end for
 */
 
 int iCheck = 0;
 for (int index = 0; index < int(viCurrentMapTriggers.size ()); index++)
 {
  iCheck = viCurrentMapTriggers.at (index);
  if (vptMasterTriggerList.at (iCheck)->bArmed)
  {
   if (vptMasterTriggerList.at (iCheck)->iXpos == e.m_iXpos)
   {
    if (vptMasterTriggerList.at (iCheck)->iYpos == e.m_iYpos)
    {
     // call trigger function
     vptMasterTriggerList.at (iCheck)->func (e, iCheck);
     // unset the trigger if auto off
     if (vptMasterTriggerList.at (iCheck)->bAutoOff == EnableAutoOff)
     {
      disableTrigger (iCheck);
     } // end if auto off 
    } // end if y
   } // end if x
  } // end if armed
 } // end for index 
}







void navigateHero (eMotionDirection eOkDir, eMotionDirection eNotOkDir)
{ 
 // move where we want to go
 kHero.navigate (eOkDir);
 updateCurrentLocation ();
 kHero.m_iSpacesMoved++;
 
 // check for solid area 
 if (vptMasterMapList.at (iCurrent_location)->eSolid == eMapIsNotPassable)
 {
  // move back to where we were
  kHero.navigate (eNotOkDir);
  updateCurrentLocation ();
 }
 else
 {
  // check for Battle
  
  int iBattle = rand () % 1024;  
  
  if ( static_cast <int> (kHero.m_iSpacesMoved) >= iBattle )
  {
   // start a battle
   spawnEnemies ();
   kHero.m_iSpacesMoved = 0;
  }
  
  if ( (rand () % 50) == 0)
   kHero.takeVitality (1);
 } // end else check for solid
 
}
/*

 everytime you take a step,
 iSpacesMoved increases
 
 if iSpacesMoved >= iBattleFrequency
  spawnenemies
  reset spacesmoved

*/

