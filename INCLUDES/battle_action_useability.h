
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
// SELECTED 'USE AN ABILITY'
////////////////////////////////////////////////////////////////////////////////

else if (iAction == 2)
{
 bool bValidAbility = false;
 int x = 0;
 do
 {
  Common :: clearscreen (PRINT_VERTICAL_OFFSET);
  
  kHero.showAbilities ();
  
  string strInput = Common :: input ("Enter the name of the Ability you wish to use: ");

  int iAbility = kHero.abilityIndex (strInput);

  if (iAbility != -1)
  {
   USE_ABILITY_IN_BATTLE (strOutput, kHero, strInput, *vpkEnemies.at(iTarget - 1));

   bValidAbility = true;
  } // end if valid ability
  else
  {
   cout << PRINT_OFFSET  
        << "You do not know the \"" 
        << strInput 
        << "\" Ability!" 
        << OFFSET_ENDL;
        
   Common :: pause ("Press Return and Try Again");
  } // end else invalid ability
     
 } while (!bValidAbility);
    
} // end else use ability
////////////////////////////////////////////////////////////////////////////////

