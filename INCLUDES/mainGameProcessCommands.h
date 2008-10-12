
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



  if (strUseraction == "quit" || 
      strUseraction == "QUIT" ||
      strUseraction == "exit" ||
      strUseraction == "EXIT" ||
      strUseraction == "bye"  ||
      strUseraction == "BYE")      
  {
   Common :: clearscreen ();
   //buildMasterTriggerList ();
   bPlaying = false;
  }
  else if (strUseraction == "help" || strUseraction == "HELP" || strUseraction == "?")
  {
   helpScreen ();
   Common :: pause ();
  }
  else if (strUseraction == "st" || strUseraction == "ST")
  {
   shortStats ();
   Common :: pause ();
  }
  else if ((strUseraction == "menu") || (strUseraction == "MENU"))
  {
   doGameMenu ();
  }
  else if (strUseraction == "lista" || strUseraction == "LISTA")
  {
   Common :: clearscreen (PRINT_VERTICAL_OFFSET);
   kHero.showAbilities ();
   Common :: pause (center_press_return);
  }
  else if (strUseraction == "listi" || strUseraction == "LISTI")
  {
   Common :: clearscreen (PRINT_VERTICAL_OFFSET);
   kHero.showInventory ();
   Common :: pause (center_press_return);
  }
  else if (strUseraction == "liste" || strUseraction == "LISTE")
  {
   Common :: clearscreen (PRINT_VERTICAL_OFFSET);
   kHero.showEquipped ();
   Common :: pause (center_press_return);
  }
  
  // ============================================================
  
  else if (strUseraction == "nw" || strUseraction == "NW" || strUseraction == "northwest" || strUseraction == "NORTHWEST")
  {
   navigateHero (eNorthWest, eSouthEast);
  }
  else if (strUseraction == "n" || strUseraction == "N" || strUseraction == "north" || strUseraction == "NORTH")
  {
   navigateHero (eNorth, eSouth);
  }
  else if (strUseraction == "ne" || strUseraction == "NE" || strUseraction == "northeast" || strUseraction == "NORTHEAST")
  {
   navigateHero (eNorthEast, eSouthWest);
  }
  else if (strUseraction == "e" || strUseraction == "E" || strUseraction == "east" || strUseraction == "EAST")
  {
   navigateHero (eEast, eWest);
  }
  else if (strUseraction == "se" || strUseraction == "SE" || strUseraction == "southeast" || strUseraction == "SOUTHEAST")
  {
   navigateHero (eSouthEast, eNorthWest);
  }
  else if (strUseraction == "s" || strUseraction == "S" || strUseraction == "south" || strUseraction == "SOUTH")
  {
   navigateHero (eSouth, eNorth);
  }
  else if (strUseraction == "sw" || strUseraction == "SW" || strUseraction == "southwest" || strUseraction == "SOUTHWEST")
  {
   navigateHero (eSouthWest, eNorthEast);
  }
  else if (strUseraction == "w" || strUseraction == "W" || strUseraction == "west" || strUseraction == "WEST")
  {
   navigateHero (eWest, eEast);
  }  
  else
  {
   cout << PRINT_OFFSET  
        << "Unknown command." 
        << OFFSET_ENDL 
        << "Type [help] to see available commands." << OFFSET_ENDL;
   Common :: pause ();
  }
  
  
