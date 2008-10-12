
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

//#include "worldmap_libraryheader.h"

// creates a folder using mkdir to hold exported data files
void WORLDMAP :: prepareExportDir (std::string strDirName)
{
 m_strExportDir = strDirName;
 char sTemp [255];
 sprintf (sTemp, "mkdir \"%s\"", strDirName.c_str ());
 system (sTemp);
}

 // exports all locations of a map to
 // export-dir\\location-id_location-name_location.txt
string WORLDMAP :: saveLocations ()
{
 string strFailed = "";
 if (m_vpkLocations.empty ()) return "No locations to save!\n";
 if (m_strExportDir == "") return "No export directory defined. Use prepareExportDir()";
 vector<WORLDMAPAREA*>::iterator iter;
 for (iter = m_vpkLocations.begin (); iter < m_vpkLocations.end (); iter++)
 {
  int iLeft   = (*iter)->m_iXpos [0];
  int iTop    = (*iter)->m_iYpos [0];
  int iRight  = (*iter)->m_iXpos [1];
  int iBottom = (*iter)->m_iYpos [1];
  
  unsigned int iID = (*iter)->m_ID; // 0-65535 
  
  char sTemp [1024];
  sprintf (sTemp, "%s\\%d_%s.txt", m_strExportDir.c_str (), (*iter)->m_ID, (*iter)->m_strName.c_str ());
 
  ofstream outFile (sTemp);
  
  if (outFile.is_open ())
  {
   // opened, write data
   outFile << (*iter)->m_iLayer << endl;
   outFile << (*iter)->m_ID << endl;
   outFile << (*iter)->m_strName << endl;
   outFile << (*iter)->m_strDescription [0] << endl;
   outFile << (*iter)->m_strDescription [1] << endl;
   outFile << (*iter)->m_iXpos [0] << endl;
   outFile << (*iter)->m_iYpos [0] << endl;
   outFile << (*iter)->m_iXpos [1] << endl;
   outFile << (*iter)->m_iYpos [1] << endl;
   if      ((*iter)->m_eSafe == eMapIsSafe) outFile << "A" << endl;
   else if ((*iter)->m_eSafe == eMapIsNotSafe) outFile << "B" << endl;
   else outFile << "X" << endl; 
   if      ((*iter)->m_eSolid == eMapIsPassable) outFile << "C" << endl;
   else if ((*iter)->m_eSolid == eMapIsNotPassable) outFile << "D" << endl;
   else outFile << "X" << endl;
   outFile << endl;
   // close
   outFile.close ();
  }
  else
  {
   strFailed += "ERROR: Cannot export to file: ";
   strFailed += sTemp;
   strFailed += "\n";
  } // end else error
 } // end for iter
 return strFailed;
}

