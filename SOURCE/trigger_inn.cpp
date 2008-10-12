
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


void trigger_inn                 (ENTITY &e, int index)
{
 int iCost = 20;
 
 // Inn costs $20 
 // Greet Hero
 // Prompt to stay the night
  
 {// START DIALOGUE
 std :: string strText = "Hello, traveler.";
 Common :: dialogue ("Innkeeper", strText, true);
}// END DIALOGUE

{// START DIALOGUE
 std :: string strText = "Would you like to rent a room for the night?";
 Common :: dialogue ("Innkeeper", strText);
}// END DIALOGUE

 cout << OFFSET_ENDL;
 std :: string strChoice = Common :: input (": ");
 if (strChoice == "y" || strChoice == "Y" || strChoice == "yes" || strChoice == "YES")
 {
  // If yes,
  // check for enough funds
  if (kHero.m_iMoney >= iCost)
  {
   {// START DIALOGUE
    std :: string strText = "Sleep well.";
    Common :: dialogue ("Innkeeper", strText, true);
   }// END DIALOGUE

   // if enough funds, take funds, restore hp/mp/vit
   kHero.takeMoney (iCost);
   kHero.giveHp (9999);
   kHero.giveMp (9999);
   kHero.giveVitality (255);
  }
  else
  { 
   // if not enough funds, inform Hero and then do nothing
   {// START DIALOGUE
    std :: string strText = "You don't have enough money!";
    Common :: dialogue ("Innkeeper", strText, true);
   }// END DIALOGUE
  } 
 }
 // If No, do nothing
}

