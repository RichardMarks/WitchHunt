
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
// OBTAIN AN ACTION
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
    cout << OFFSET_ENDL << OFFSET_ENDL << OFFSET_ENDL << OFFSET_ENDL;
    
    cout << "1: Use an Item" 
         << OFFSET_ENDL
         << "2. Use an Ability" 
         << OFFSET_ENDL
         << "3. Run from battle" 
         << OFFSET_ENDL << OFFSET_ENDL;
    
    string strInput = Common :: input ("Select an action: ");
    iAction = Common :: cint (strInput);
    
   }while ((iAction < 1) || (iAction > 3));
////////////////////////////////////////////////////////////////////////////////

