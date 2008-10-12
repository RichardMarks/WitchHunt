
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


void trigger_shop                (ENTITY &e, int index)
{

 // Shop Script
 //
 //
 // create an entity to serve as the shopkeeper
 // give the shopkeeper 99 teas and bandages
 // Teas cost $30
 // Bandages cost $30
 // Teas sell for $10
 // Bandages sell for $10
 
 //
 // Greet Hero
 // Show Shop Menu (Buy/Sell/Leave)
 // If Buy, show shopkeeper's items
 //  prompt for an item name
 //  if valid item name
 //   and if shopkeeper has the item
 //    prompt for purchase yes/no
 //     if yes, prompt for amount
 //      if amount < 99 
 //        if hero has enough funds for amount items
 //         take amount * item cost from hero's money
 //         give hero amount of item
 //         return to shop menu
 //      if amount > 99
 //       tell hero they cannot buy more than 99 items today
 //       return to shop menu
 //     if no, return to item list
 // If Sell, show hero's items
 //  prompt for an item name
 //  if valid item name
 //   and if hero has the item
 //    prompt to sell the item yes/no
 //     if yes, remove an item from the hero's inventory
 //     and give hero $10
 //     return to shop menu
 //     if no, return to shop menu
 // If Leave, do nothing
 
}

