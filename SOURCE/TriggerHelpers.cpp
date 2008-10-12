
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
// TriggerHelpers.cpp
////////////////////////////////////////////////////////////////////////////////

// include the project header
//#include "project.h"

////////////////////////////////////////////////////////////////////////////////
// adds a TRIGGER pointer to the master trigger list vector
////////////////////////////////////////////////////////////////////////////////
void addTrigger (TRIGGER* tTrigger)
{
 vptMasterTriggerList.push_back (tTrigger);
 #ifdef DEBUG_BUILD
  cerr << "DEBUG: addTrigger() called:" << endl;
 #endif 
}

////////////////////////////////////////////////////////////////////////////////
// returns a TRIGGER pointer fully initialized with the data
////////////////////////////////////////////////////////////////////////////////


TRIGGER* createTrigger (void (*func)(ENTITY &e, int index), int iXpos, int iYpos, int Map, bool bAutoOff, bool bArmed)
{
 #ifdef DEBUG_BUILD
  cerr << "DEBUG: createTrigger() called:" 
       << "x:"        << iXpos 
       << "y:"        << iYpos
       << "armed:"    << bArmed
       << "func:"     << &func
       << "Map: "     << Map
       << "AutoOff: " << bAutoOff
       << endl;
 #endif
 
 TRIGGER* tTrigger      = new TRIGGER;
  tTrigger->iXpos       = iXpos;
  tTrigger->iYpos       = iYpos;
  tTrigger->func        = func;
  tTrigger->bArmed      = bArmed;
  tTrigger->bAutoOff    = bAutoOff;
  tTrigger->iMap        = Map;
  tTrigger->iTargetXpos = iXpos;
  tTrigger->iTargetYpos = iYpos;
  tTrigger->iTargetMap  = Map;
  tTrigger->strExtra    = "";
 return tTrigger;
}

void clearMasterTriggerList ()
{
 #ifdef DEBUG_BUILD
  cerr << "DEBUG: clearMasterTriggerList() called" << endl;
 #endif
 
 if (!vptMasterTriggerList.empty ())
 {
  vector<TRIGGER*> :: iterator iter;
  for (iter = vptMasterTriggerList.begin (); iter < vptMasterTriggerList.end (); iter++)
  {
   if ( (*iter) )
   {
    delete (*iter);
    (*iter) = NULL; 
    #ifdef DEBUG_BUILD
     cerr << "DEBUG: delete (*iter)" << endl;
    #endif
   } 
  } 
  vptMasterTriggerList.clear (); 
 } 
 #ifdef DEBUG_BUILD
  cerr << "DEBUG: clearMasterTriggerList() finished" << endl;
  Common :: pause ("-DEBUG- Paused. (Press Return)");
 #endif
}


void disableTrigger (int index)
{
 #ifdef DEBUG_BUILD
 cerr << "DEBUG: Disabling Trigger: " << index << endl;
 #endif
 vptMasterTriggerList.at (index)->bArmed = DisarmedTrigger;
}

void enableTrigger (int index)
{
 #ifdef DEBUG_BUILD
 cerr << "DEBUG: Enabling Trigger: " << index << endl;
 #endif
 vptMasterTriggerList.at (index)->bArmed = ArmedTrigger;
}

// WARP TRIGGER USAGE:
/*
 addWarp (src_map, src_x, src_y, dst_map, dst_x, dst_y)        // default persistent warp
 addWarp (src_map, src_x, src_y, dst_map, dst_x, dst_y, false) // one-time use warp
*/



void addWarp (int iMap, int iXpos, int iYpos, int iTargetMap, int iTargetXpos, int iTargetYpos, bool bAutoOff)
{
 #ifdef DEBUG_BUILD
 cerr << "DEBUG: Adding WARP Location to map " << iMap << endl;
 cerr << "DEBUG: WARP Position   : " << iXpos << ", " << iYpos << endl;
 cerr << "DEBUG: WARP Destination: " << iTargetXpos << ", " << iTargetYpos << " on map " << iTargetMap << endl;
 #endif
 
 {
 TRIGGER* tTrigger       = new TRIGGER;
  tTrigger->iXpos        = iXpos;
  tTrigger->iYpos        = iYpos;
  tTrigger->iTargetXpos  = iTargetXpos;
  tTrigger->iTargetYpos  = iTargetYpos;
  tTrigger->iTargetMap   = iTargetMap;
  tTrigger->func         = generic__warp__trigger;
  tTrigger->bArmed       = true;
  tTrigger->bAutoOff     = bAutoOff;
  tTrigger->iMap         = iMap;
  tTrigger->strExtra     = "";
 addTrigger (tTrigger);
 }{
 TRIGGER* tTrigger       = new TRIGGER;
  tTrigger->iXpos        = iXpos+1;
  tTrigger->iYpos        = iYpos;
  tTrigger->iTargetXpos  = iTargetXpos+1;
  tTrigger->iTargetYpos  = iTargetYpos;
  tTrigger->iTargetMap   = iTargetMap;
  tTrigger->func         = generic__warp__trigger;
  tTrigger->bArmed       = true;
  tTrigger->bAutoOff     = bAutoOff;
  tTrigger->iMap         = iMap;
  tTrigger->strExtra     = "";
 addTrigger (tTrigger);
 }{
 TRIGGER* tTrigger       = new TRIGGER;
  tTrigger->iXpos        = iXpos+1;
  tTrigger->iYpos        = iYpos+1;
  tTrigger->iTargetXpos  = iTargetXpos+1;
  tTrigger->iTargetYpos  = iTargetYpos+1;
  tTrigger->iTargetMap   = iTargetMap;
  tTrigger->func         = generic__warp__trigger;
  tTrigger->bArmed       = true;
  tTrigger->bAutoOff     = bAutoOff;
  tTrigger->iMap         = iMap;
  tTrigger->strExtra     = "";
 addTrigger (tTrigger);
 }{
 TRIGGER* tTrigger       = new TRIGGER;
  tTrigger->iXpos        = iXpos;
  tTrigger->iYpos        = iYpos+1;
  tTrigger->iTargetXpos  = iTargetXpos;
  tTrigger->iTargetYpos  = iTargetYpos+1;
  tTrigger->iTargetMap   = iTargetMap;
  tTrigger->func         = generic__warp__trigger;
  tTrigger->bArmed       = true;
  tTrigger->bAutoOff     = bAutoOff;
  tTrigger->iMap         = iMap;
  tTrigger->strExtra     = "";
 addTrigger (tTrigger);
 }
}

void addItemSpawn (int iMap, int iXpos, int iYpos, std :: string strItemName, int iAmount)
{
 int i = getItemIndexFromString (GLOBAL_ITEM_MAP, strItemName);
 
 if ( i > -1 )
 {
  // add trigger
  TRIGGER* tTrigger       = new TRIGGER;
   tTrigger->iXpos        = iXpos;
   tTrigger->iYpos        = iYpos;
   tTrigger->iTargetXpos  = iAmount;
   tTrigger->iTargetYpos  = iAmount;
   tTrigger->iTargetMap   = iMap;
   tTrigger->func         = generic__itemspawn__trigger;
   tTrigger->bArmed       = true;
   tTrigger->bAutoOff     = true;
   tTrigger->iMap         = iMap;
   tTrigger->strExtra     = strItemName;
  addTrigger (tTrigger);
 }
 else
 {
  // warning if debug build
  #ifdef DEBUG_BUILD
  cerr << "DEBUG: warning, attempted to add spawn of invalid item! : " 
       << strItemName << ".\n"
       << "DEBUG: spawn position: " << iXpos << ", " << iYpos 
       << "\nDEBUG: on Map: " << szMapNames [iMap] << "\n";
  Common :: pause ("");
  #endif  
 }
}

