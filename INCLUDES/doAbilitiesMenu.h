
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
// doAbilitiesMenu.h
//
// void doAbilitiesMenu_UseAbility ();
////////////////////////////////////////////////////////////////////////////////

void doAbilitiesMenu_UseAbility ()
{
 cout << OFFSET_ENDL;
 
 string strAbility = Common :: input ("Enter the ability name: ");
 
 int i = getAbilityIndexFromString (GLOBAL_ABILITY_MAP, strAbility);
 
 if ( i > -1 )
 {
  // can only use abilities that you have learned
  if (kHero.learnedAbility (GLOBAL_MASTER_ABILITY_LIST [i].m_strAlias))
  {
   cout << PRINT_OFFSET 
        << kHero.useAbility (GLOBAL_MASTER_ABILITY_LIST [i].m_fpkAbility, kHero) 
        << OFFSET_ENDL;
  } // end if hero learned the ability
  else
  {
   cout << PRINT_OFFSET
        << "You do not know that ability." 
        << OFFSET_ENDL;
  } // end else ability not learned
  
 }
 else
 {
  cout << PRINT_OFFSET << strAbility << " is not a valid ability." << OFFSET_ENDL;
 }
 
 Common :: pause ("");
 
}
////////////////////////////////////////////////////////////////////////////////

