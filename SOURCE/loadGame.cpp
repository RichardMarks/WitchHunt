
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
// loadGame.cpp
////////////////////////////////////////////////////////////////////////////////

void loadGame ()
{
 
 /* 
 
 load story flags that have fired
 iStoryProgress
 
 load triggers states
 vptMasterTriggerList
 
 load current map
 iCurrent_map
 
 load hero entity structure
 kHero
 
 */
 Common :: clearscreen (PRINT_VERTICAL_OFFSET);
 cout << PRINT_OFFSET << "System :: Load Game\n\n";
 
 // display a list of saved games
 // getFileList (string extension, bool display extension)
 vector <std :: string> strProfiles = getFileList ("sav", false);
 
 { 
  cout << PRINT_OFFSET; Common :: DrawBoxTop (60); cout << endl;
  for (int n = 0; n < strProfiles.size (); n++)
  {
   cout << PRINT_OFFSET 
       << BoxLC 
       << " "
       << setw(57) 
       << setiosflags(ios::left) 
       << strProfiles.at (n) 
       << BoxRC
       << resetiosflags(ios::left)
       << endl;
  }
  cout << PRINT_OFFSET; Common :: DrawBoxBottom (60); cout << endl;
 }
 
 cout << PRINT_OFFSET << "Enter the name of the profile you wish to load:" << OFFSET_ENDL
      << "Enter nothing to cancel." << OFFSET_ENDL;
 string strFilename = Common :: input ("Profile: ");
 if (strFilename == "")return;
 
 strFilename += ".sav";
 ifstream inFile (strFilename.c_str ());
 
 if (inFile)
 {
  
  // save current map
  inFile >> iCurrent_map >> ws;
  
  // load hero entity
  kHero.loadMe (inFile);
  
  string strTemp;
  // load story flags
  {
   getline (inFile, strTemp); inFile >> ws;
   for (int n = 0; n < strTemp.size (); n++)
   {
    int iValue = static_cast<int> (strTemp.at (n));
    iStoryProgress [n] = (iValue - 65);
    #if defined(DEBUG_BUILD)
     cerr << "DEBUG: Story State = " << iValue << "(" << iStoryProgress [n] << ")" << endl;
    #endif
   }
   
   #if defined(DEBUG_BUILD)
    #if defined (ALLOW_DEBUG_PAUSE)
    Common :: pause("DEBUG: <PAUSED>");
    #endif
    #endif 
  }
  
  // load trigger armed state
  {
   int iChunks;
   int iOffset = 0;
   inFile >> iChunks >> ws;
   #if defined(DEBUG_BUILD)
    cerr << "DEBUG: Chunks = " << iChunks << endl;
   #endif 
   #if defined(DEBUG_BUILD)
    #if defined (ALLOW_DEBUG_PAUSE)
    Common :: pause("DEBUG: <PAUSED>");
    #endif
    #endif 
   for (int iChunk = 0; iChunk < iChunks; iChunk++)
   {
    // grab a chunk
    getline (inFile, strTemp); inFile >> ws;
    
    // parse chunk
    for (int n = 0; n < strTemp.size (); n++)
    {
     int iValue = static_cast<int> (strTemp.at (n));
     
     vptMasterTriggerList.at (iChunk + n)->bArmed = static_cast<bool> (iValue);
     
     #if defined(DEBUG_BUILD)
      cerr << "DEBUG: Trigger State = " 
           << iValue 
           << "(" 
           << vptMasterTriggerList.at (iChunk + n)->bArmed 
           << ")" 
           << endl;
     #endif
    }
    
    #if defined(DEBUG_BUILD)
    #if defined (ALLOW_DEBUG_PAUSE)
    Common :: pause("DEBUG: <PAUSED>");
    #endif
    #endif 
   }
   
  }
  

  #if defined(DEBUG_BUILD)
   cerr << "DEBUG: Current Map = " << iCurrent_map << endl;
  #endif 
  
  
  inFile.close ();
 }
 else
 { 
  #if defined(DEBUG_BUILD)
   cerr << "DEBUG: Cannot load the game!\n";
  #endif
 }
 
}


