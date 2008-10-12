
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


#ifndef __LIBRARY_WORLDMAP_H__
#define __LIBRARY_WORLDMAP_H__

#include <string>
//#include <vector>

enum eMapFlags
{
 eMapIsSafe        = 0,  // A
 eMapIsNotSafe     = 1,  // B
 eMapIsPassable    = 2,  // C
 eMapIsNotPassable = 3,  // D
 eMapInvalid       = 255 // X
};

struct MAPDATA
{
 std :: string strName;
 std :: string strDesc;
 int iId;              // ascii code for the terrain
 eMapFlags eSafe;
 eMapFlags eSolid;    
};

/*
// defines a location
class WORLDMAPAREA
{
public:
 WORLDMAPAREA ();
 virtual ~WORLDMAPAREA ();
 unsigned int m_ID; // 0-65535 
 std::string m_strName;       // map name
 std::string m_strDescription [2]; // descriptions for map
 
 
 int m_iXpos [2]; // x position for upperleft (0) and lowerright(1)
 int m_iYpos [2]; // y position for upperleft (0) and lowerright(1)
 
 
 int m_iLayer; // depth layer 
 
 eMapFlags m_eSafe;
 eMapFlags m_eSolid;
};



// manages all the locations for a map
class WORLDMAP
{
private:
 // stl stack of all the locations
 std::vector<WORLDMAPAREA*> m_vpkLocations; 
 
 // export directory
 std::string m_strExportDir; 
 
 // returns true if the x/y lies within the bounds of left,top,right,bottom
bool x_pointWithin (int iXpos, int iYpos, int iLeft, int iTop, int iRight, int iBottom);
 
public:
 // constructor
 WORLDMAP (); 
 
 // destructor
 virtual ~WORLDMAP ();

 // add an instance of WORLDMAPAREA to the map
 int addLocation (WORLDMAPAREA* pkLocation);
 
 // add a location to the map; returns the index of the location
 
 int addLocation (int iLayer, int iLeft, int iTop, int iRight, int iBottom, 
	 std::string strName, std::string strPrimaryDescription, std::string strSecondaryDescription, eMapFlags eSafe, eMapFlags eSolid);
 
 // load a location from a file to the map; returns the index of the location -1 on fail
 int loadLocation (std::string strFilename);
 
 // creates a folder using mkdir to hold exported data files
 void prepareExportDir (std::string strDirName);
 
 // exports all locations of a map to
 // export-dir\\location-id_location-name_location.txt
 // returns  an error string if there was one
 std::string saveLocations ();
 
 // clears the map of all locations; returns the number of locations deleted
 int clear ();
 
 // removes a location from the map; returns the number of locations after removal
 int remove (std::vector<WORLDMAPAREA*>::iterator iter);
 
 // returns the id of the location that the x/y lies in
 unsigned int getID (int iXpos, int iYpos);
 
 // returns the name of the location that the x/y lies in
 std::string getName (int iXpos, int iYpos);
 
 // returns the description of the location that the x/y lies in
 std::string getPrimaryDescription (int iXpos, int iYpos);
 
 // returns the description of the location that the x/y lies in
 std::string getSecondaryDescription (int iXpos, int iYpos);
 
 // returns the 'safe' flag of the location that the x/y lies in
 eMapFlags getSafe (int iXpos, int iYpos);
 
 // returns the 'solid' flag of the location that the x/y lies in
 eMapFlags getSolid (int iXpos, int iYpos);
 
 // returns the name of the location
 std::string getNameFromIndex (int index);
 
 // returns the description of the location
 std::string getPrimaryDescriptionFromIndex (int index);
 
  // returns the description of the location
 std::string getSecondaryDescriptionFromIndex (int index);
 
 // returns the 'safe' flag of the location
 eMapFlags getSafeFromIndex (int index);
 
 // returns the 'solid' flag of the location
 eMapFlags getSolidFromIndex (int index);
 
 // returns an iterator for you to use
 std::vector<WORLDMAPAREA*>::iterator getIteratorFromIndex (int index);
 
 // returns a location element
 WORLDMAPAREA* getElement (int index);
 
 // returns size of the maplist
 int getLocationCount ();
 
 int getLayer (int iXpos, int iYpos);
 int getLayerFromIndex (int index);
 
};

*/
#endif

