
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
// OBTAIN A TARGET
////////////////////////////////////////////////////////////////////////////////
   do
   {
    Common :: clearscreen (PRINT_VERTICAL_OFFSET);
    
    // display hero stats
    cout << PRINT_OFFSET << "HEALTH : ";
    
    cout.fill('0'); cout << setw(4) << kHero.m_iHp << setw(0);
    cout.fill(' '); cout << " / ";
    cout.fill('0'); cout << setw(4) << kHero.m_iMaxHp << setw(0);
    cout.fill(' '); cout << "  PHY ATK: ";
    cout.fill('0'); cout << setw(3) << kHero.m_iPhysicalAtk << setw(0);
    cout.fill(' '); cout << "  MAG ATK: ";
    cout.fill('0'); cout << setw(3) << kHero.m_iMagickalAtk << setw(0);
    cout << OFFSET_ENDL;

    cout.fill(' '); cout << "MANA   : ";
    cout.fill('0'); cout << setw(3) << kHero.m_iMp << setw(0);
    cout.fill(' '); cout << " / ";
    cout.fill('0'); cout << setw(3) << kHero.m_iMaxMp << setw(0);
    
    cout.fill(' '); cout << "  PHY DEF: ";
    cout.fill('0'); cout << setw(3) << kHero.m_iPhysicalDef << setw(0);
    cout.fill(' '); cout << "  MAG DEF: ";
    cout.fill('0'); cout << setw(3) << kHero.m_iMagickalDef << setw(0);
    cout.fill(' ');
    cout << OFFSET_ENDL << OFFSET_ENDL << OFFSET_ENDL << endl;
    
    
    // display targets
    for (index = 0; index < int(vpkEnemies.size ()); index++)
    {
     if(vpkEnemies.at(index)->m_eState != eDead)
     {
      #if defined(DEBUG_BUILD)
       cerr << PRINT_OFFSET 
            << index + 1 << ": (L" 
            << vpkEnemies.at(index)->m_iLevel 
            << ")  " << vpkEnemies.at(index)->m_strAlias << endl;
      #elif !defined(DEBUG_BUILD)
      cout << PRINT_OFFSET  << index + 1 << ": " << vpkEnemies.at(index)->m_strAlias << endl;
      #endif
     }
     else
     { 
      #if defined(DEBUG_BUILD)
       cerr << PRINT_OFFSET 
            << index + 1 << ": (L" 
            << vpkEnemies.at(index)->m_iLevel 
            << ")  " << vpkEnemies.at(index)->m_strAlias << " [DEAD]" << endl;
      #elif !defined(DEBUG_BUILD)
      cout << PRINT_OFFSET  << index + 1 << ": " << vpkEnemies.at(index)->m_strAlias << " [DEAD]" << endl;
      #endif
     }
    }
    
    
    cout << PRINT_OFFSET << OFFSET_ENDL;
    string strInput = Common :: input ("Select a target: ");
    iTarget = Common :: cint (strInput);

    if ((iTarget < 1) || (iTarget > int(vpkEnemies.size ())))
    {
     continue;
    }
    else
    {
     if (vpkEnemies.at(iTarget - 1)->m_eState == eDead)
     {
      cout << PRINT_OFFSET  << "That enemy is dead please choose a new target" << endl;
      iTarget = -1;
      Common :: pause (center_press_return);
      continue;
     }
    }
    Common :: clearscreen (PRINT_VERTICAL_OFFSET);
    
   }while ((iTarget < 1) || (iTarget > int(vpkEnemies.size ())));
////////////////////////////////////////////////////////////////////////////////

