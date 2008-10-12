
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

// about fucking time this thing works!
// ^_^
//

void displayMinimap ()
{ 
 int xStart = kHero.m_iXpos - 5;
 int yStart = kHero.m_iYpos - 5;
 
 cout << PRINT_OFFSET; Common :: DrawBoxTop (13); cout << endl;
 
 for (int y = 0; y < 11; y++)
 {
  cout << PRINT_OFFSET << BoxLC;
  for (int x = 0; x < 11; x++)
  {
   if ( (x == 5) && (y == 5) )
   {
    cout << char(1);
   }
   else
   {
    cout << char (vpiMaps.at(iCurrent_map)[(yStart * 72) + xStart]);
    
    // handle heads up display
    if ( (x == 10) && (y == 0) )
    {
     cout << BoxRC << " " << kHero.m_strAlias;
    }
    else if ( (x == 10) && (y == 1) )
    {
     cout << BoxRC <<            " HEALTH " << setw(4) << kHero.m_iHp << setw(0) << " / " << setw(4) << kHero.m_iMaxHp;
    }
    else if ( (x == 10) && (y == 2) )
    {
     cout << BoxRC << setw(0) << " MANA   " << setw(4) << kHero.m_iMp << setw(0) << " / " << setw(4) << kHero.m_iMaxMp;
    }
    
    #if defined(DEBUG_BUILD)
     #if defined(MAP_TESTER)
      else if ( (x == 10) && (y == 4) )
      {
       cout << BoxRC << " ";
       cout << "iCurrent_location = " << iCurrent_location;
      }
      else if ( (x == 10) && (y == 5) )
      {
       cout << BoxRC << " ";
       cout << "iCurrent_map      = " << iCurrent_map;
      }
     #endif
    #endif
    
    //else if ( (x == 10) && (y == 4) )
    //{ 
    // location information
    // cout << BoxRC << " " << vptMasterMapList.at (iCurrent_location)->strDesc;
    //}
    else if ( (x == 10) && (y == 6) )
    {
     cout << BoxRC << " " << szMapNames [iCurrent_map];
    }
    else if ( (x == 10) && (y == 7) )
    {
     // safe zone?
     if (vptMasterMapList.at (iCurrent_location)->eSafe == eMapIsSafe)
     {
      cout << BoxRC << " This area is safe.";
     }
     else 
     { 
      cout << BoxRC << " This area is unsafe.";
     } // end if safe else unsafe
    
    }
    #if defined(DEBUG_BUILD)
     #if defined(MAP_TESTER)
      else if ( (x == 10) && (y == 9) )
      {
       cout << BoxRC << " ";
       cout << "X: " << kHero.m_iXpos;
      }
      else if ( (x == 10) && (y == 10) )
      {
       cout << BoxRC << " ";
       cout << "Y: " << kHero.m_iYpos;
      }
     #endif
    #endif 
    else
    {
     if (x==10)
      cout << BoxRC;
    } // end draw heads up display
    
   } // end else if not drawing the hero
   
   xStart++;
  }
  xStart = kHero.m_iXpos - 5;
  yStart++;
  cout << endl;
 }
 
 cout << PRINT_OFFSET; 
 Common :: DrawBoxBottom (13); 
 return;
}

