
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

//#include "entity_libraryheader.h"

void ENTITY :: showInventory ()
{
 int iCount = 0;
 int iIndex = 1;
 std::string strTarget;
 std::vector<std::string> vstrTemp;
 char cTemp2 [8];
 char cTemp [30]; 

 cout << PRINT_OFFSET 
      << "Viewing Inventory for " << m_strAlias << "\n\n";


 cout << PRINT_OFFSET; Common :: DrawBoxTop (40); cout << endl;
 
 for (int index = 0; index < int(m_vstrItems.size ()); index++)
 {
  vstrTemp.push_back (m_vstrItems.at (index));
 }
 
 while (!vstrTemp.empty ())
 {
  strTarget = vstrTemp.at (0);
  iCount = 0;
  
  for (int index = 0; index < int(vstrTemp.size ()); index++)
  {
   if (vstrTemp.at (index) == strTarget)
   {
    vstrTemp.erase (vstrTemp.begin () + index);
    iCount++;
    index--;
   }
  }
  
   sprintf(cTemp2,"x%d ", iCount);
  
  
  if (hasItemEquipped (strTarget)) // equipped show with [E] next to it
  {
   sprintf(cTemp," [E] %s",strTarget.c_str ());
  }
  else // not equipped
  {
   sprintf(cTemp,"     %s",strTarget.c_str ());
  }
  
  cout << PRINT_OFFSET << BoxLC
        << setw(30) 
        << setiosflags(ios::left) << cTemp << setiosflags(ios::right) 
        << setw(8) << cTemp2 << resetiosflags(ios::right)
        << setw(0) << resetiosflags(ios::left) << BoxRC << endl;
  
  
  iIndex++;
 }
 
 cout << PRINT_OFFSET; Common :: DrawBoxBottom (40); cout << endl;
}

