
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
// saveGame.cpp
////////////////////////////////////////////////////////////////////////////////

void saveGame ()
{
 // save game
 
 /* 
 
 save story flags that have fired
 iStoryProgress
 
 save triggers states
 vptMasterTriggerList
 
 save current map
 iCurrent_map
 
 save hero entity structure
 kHero
 
 */
 
 // filename is alias of hero
 string strFilename = kHero.m_strAlias + ".sav";
 
 ofstream outFile (strFilename.c_str ());
 
 if (outFile)
 {
  // save current map
  outFile << iCurrent_map << endl;
  
  // save hero entity
  kHero.saveMe (outFile);
  
  // save story flags
  // as a string of characters
  // char(65 + flag)
  {
   for (int n = 0; n < C_NUM_STORY_EVENTS; n++)
   {
    outFile << static_cast<char> (65 + iStoryProgress [n]);
   }
   outFile << endl;
  }
  
  // save trigger armed state
  {
   int iChunkSize     = 64;
   int iDataLength    = static_cast<int> ( vptMasterTriggerList.size () );
   int iChunks        = static_cast<int> (iDataLength / iChunkSize);
   int iChunksWritten = 0;
   
   outFile << iChunks << endl;
   
   for (int n = 0; n < vptMasterTriggerList.size (); n++)
   {
    if (vptMasterTriggerList.at (n)->bArmed == true)
    {
     outFile << static_cast<char> (98);
    } 
    else  
    {
     outFile << static_cast<char> (97);
    } 
    iChunksWritten++;
    if ( (iChunksWritten % iChunkSize) == 0)
    {
     outFile << endl;
    }
   }
   outFile << endl;
  }
  
  
  
  outFile.close ();
 }
 else
 { 
  #if defined(DEBUG_BUILD)
   cerr << "DEBUG: Cannot save the game!\n";
  #endif
 }
 
}





