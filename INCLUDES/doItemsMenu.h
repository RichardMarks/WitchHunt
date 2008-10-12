
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
// doItemsMenu.h
//
// void doItemsMenu_UseItem ();
// void doItemsMenu_DropItem ();
// void doItemsMenu_EquipItem ();
// void doItemsMenu_UnequipItem ();
////////////////////////////////////////////////////////////////////////////////

void doItemsMenu_UseItem ()
{
 cout << OFFSET_ENDL;
 
 string strItem = Common :: input ("Enter the item name: ");
 
 int i = getItemIndexFromString (GLOBAL_ITEM_MAP, strItem);
 
 if ( i > -1 )
 {
  // can only use usable type items
  if (GLOBAL_MASTER_ITEM_LIST [i].m_eCategory == eUsable)
  {
   cout << PRINT_OFFSET 
        << kHero.useItem (GLOBAL_MASTER_ITEM_LIST [i],
                          GLOBAL_MASTER_ITEM_LIST [i].m_strAlias,
                          GLOBAL_MASTER_ITEM_LIST [i].m_fpkItem, kHero) 
        << OFFSET_ENDL;
  } // end if usable
  else
  {
   cout << PRINT_OFFSET
        << "You cannot use that item." 
        << OFFSET_ENDL;
  } // end else cannot use
  
 }
 else
 {
  cout << PRINT_OFFSET << strItem << " is not a valid item." << OFFSET_ENDL;
 }
 
 Common :: pause ("");
}
////////////////////////////////////////////////////////////////////////////////
void doItemsMenu_DropItem ()
{
 cout << OFFSET_ENDL;
 
 string strItem = Common :: input ("Enter the item name: ");
 
 int i = getItemIndexFromString (GLOBAL_ITEM_MAP, strItem);
 
 if ( i > -1 )
 {
  cout << PRINT_OFFSET 
       << "Are you sure that you want to drop your " 
       << strItem 
       << " ";
  string strYesNo = Common :: input ("? ");
  if (strYesNo == "yes" || strYesNo == "y" || strYesNo == "YES" || strYesNo == "Y")
  {
   kHero.dropItem (strItem);
  } 
 }
 else
 {
  cout << PRINT_OFFSET << strItem << " is not a valid item." << OFFSET_ENDL;
 }
 
 Common :: pause ("");
 
}
////////////////////////////////////////////////////////////////////////////////
void doItemsMenu_EquipItem ()
{
 cout << OFFSET_ENDL;
 
 string strItem = Common :: input ("Enter the item name: ");
 
 int i = getItemIndexFromString (GLOBAL_ITEM_MAP, strItem);
 
 if ( i > -1 )
 {
  // can only equip equipment type items
  if (GLOBAL_MASTER_ITEM_LIST [i].m_eCategory == eEquipment)
  {
   cout << PRINT_OFFSET 
        << kHero.equipItem (GLOBAL_MASTER_ITEM_LIST [i],
                            GLOBAL_MASTER_ITEM_LIST [i].m_strAlias,
                            GLOBAL_MASTER_ITEM_LIST [i].m_fpkItem, kHero) 
        << OFFSET_ENDL;
  } // end if equipment
  else
  {
   cout << PRINT_OFFSET
        << "You cannot equip that item." 
        << OFFSET_ENDL;
  } // end else cannot equip
 }
 else
 {
  cout << PRINT_OFFSET << strItem << " is not a valid item." << OFFSET_ENDL;
 }
 
 Common :: pause ("");
 
}
////////////////////////////////////////////////////////////////////////////////
void doItemsMenu_UnequipItem ()
{
 cout << OFFSET_ENDL;
 
 string strItem = Common :: input ("Enter the item name: ");
 
 int i = getItemIndexFromString (GLOBAL_ITEM_MAP, strItem);
 
 if ( i > -1 )
 {
  // can only unequip equipment type items that are equipped
  if (GLOBAL_MASTER_ITEM_LIST [i+1].m_eCategory == eEquipment)
  {
   if (kHero.hasItemEquipped (strItem))
   {
    cout << PRINT_OFFSET 
         << kHero.unequipItem (GLOBAL_MASTER_ITEM_LIST [i+1],
                               GLOBAL_MASTER_ITEM_LIST [i+1].m_strAlias,
                               GLOBAL_MASTER_ITEM_LIST [i+1].m_fpkItem, kHero) 
         << OFFSET_ENDL;
   } // end if item is equipped
   else
   {
    cout << PRINT_OFFSET
        << "That item is not equipped." 
        << OFFSET_ENDL;
   }
  } // end if equipment
  else
  {
   cout << PRINT_OFFSET
        << "That item is not equipment." 
        << OFFSET_ENDL;
  } // end else cannot equip
 }
 else
 {
  cout << PRINT_OFFSET << strItem << " is not a valid item." << OFFSET_ENDL;
 }
 
 Common :: pause ("");

}
////////////////////////////////////////////////////////////////////////////////

