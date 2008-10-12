
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

 // load a location from a file to the map; returns the index of the location -1 on fail
int WORLDMAP :: loadLocation (string strFilename)
{
 ifstream inFile (strFilename.c_str ());
 if (inFile.is_open ())
 {
  WORLDMAPAREA* ptArea          = new WORLDMAPAREA;
 
  inFile >> ptArea->m_iLayer >> ws;
  inFile >> ptArea->m_ID >> ws;
  getline (inFile, ptArea->m_strName);
  getline (inFile, ptArea->m_strDescription [0]);
  getline (inFile, ptArea->m_strDescription [1]);
  
  inFile >> ptArea->m_iXpos [0] >> ws;
  inFile >> ptArea->m_iYpos [0] >> ws;
  inFile >> ptArea->m_iXpos [1] >> ws;
  inFile >> ptArea->m_iYpos [1] >> ws;
  
  string strSafe;
  string strSolid;
  
  inFile >> strSafe >> ws;
  inFile >> strSolid >> ws;
  
  if      (strSafe == "A") ptArea->m_eSafe = eMapIsSafe;
  else if (strSafe == "B") ptArea->m_eSafe = eMapIsNotSafe;
  else ptArea->m_eSafe = eMapInvalid;
  
  if      (strSolid == "C") ptArea->m_eSolid = eMapIsPassable;
  else if (strSolid == "D") ptArea->m_eSolid = eMapIsNotPassable;
  else ptArea->m_eSolid = eMapInvalid;
    
  inFile >> ws;
  
  inFile.close ();
 
  m_vpkLocations.push_back (ptArea);
   
  return int(m_vpkLocations.size ());
  
 }
 return -1; // failed
}

