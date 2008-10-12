
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
// ITEM_macros.h
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBRARY_ITEM_MACROS_H__
#define __LIBRARY_ITEM_MACROS_H__
  
////////////////////////////////////////////////////////////////////////////////
// maximum number of unique items supported
//////////////////////////////////////////////////////////////////////////////// 
 #ifndef NUM_ITEMS
  #define NUM_ITEMS 2048
 #endif

////////////////////////////////////////////////////////////////////////////////
// variable name for the global item map
////////////////////////////////////////////////////////////////////////////////
 #ifndef GLOBAL_ITEM_MAP
  #define GLOBAL_ITEM_MAP ____global_item_map____
 #endif

////////////////////////////////////////////////////////////////////////////////
// the variable name for the global master item list
////////////////////////////////////////////////////////////////////////////////
 #ifndef GLOBAL_MASTER_ITEM_LIST
  #define GLOBAL_MASTER_ITEM_LIST ____global_master_item_list____
 #endif

////////////////////////////////////////////////////////////////////////////////
// create a global instance of the common_association type
////////////////////////////////////////////////////////////////////////////////
 #ifndef CREATE_ITEM_MAP
  #define CREATE_ITEM_MAP common_association GLOBAL_ITEM_MAP
 #endif

////////////////////////////////////////////////////////////////////////////////
// called by main application as a global; creates the array of items
////////////////////////////////////////////////////////////////////////////////
 #ifndef CREATE_MASTER_ITEM_LIST
  #define CREATE_MASTER_ITEM_LIST ITEMLIST GLOBAL_MASTER_ITEM_LIST [NUM_ITEMS];
 #endif

////////////////////////////////////////////////////////////////////////////////
// associate an int with a string
////////////////////////////////////////////////////////////////////////////////
 #ifndef XMAP_ITEM
  #define XMAP_ITEM(camap,alias,index) Common :: mapintoncamap  (camap, #alias , index)
 #endif

////////////////////////////////////////////////////////////////////////////////
// associate an int with a string, and place in the global item map
////////////////////////////////////////////////////////////////////////////////
 #ifndef MAP_ITEM
  #define MAP_ITEM(alias,index) Common :: mapintoncamap  (GLOBAL_ITEM_MAP, #alias , index)
 #endif

////////////////////////////////////////////////////////////////////////////////
// associate an int with a string, and place in the global item map
////////////////////////////////////////////////////////////////////////////////
 #ifndef MAP_EQUIPMENT
  #define MAP_EQUIPMENT(alias,index) Common :: mapintoncamap  (GLOBAL_ITEM_MAP, #alias , index)
 #endif

////////////////////////////////////////////////////////////////////////////////
// returns the int associated with string
////////////////////////////////////////////////////////////////////////////////
 #ifndef getItemIndex
  #define getItemIndex(camap,alias) Common :: getmappedindex (camap, #alias )
 #endif

////////////////////////////////////////////////////////////////////////////////
// returns the int associated with string
////////////////////////////////////////////////////////////////////////////////
 #ifndef getItemIndexFromString
  #define getItemIndexFromString(camap,stralias) Common :: getmappedindex (camap, stralias )
 #endif
 
////////////////////////////////////////////////////////////////////////////////
// return type for items
////////////////////////////////////////////////////////////////////////////////
 #ifndef ITEMRET
  #define ITEMRET std::string 
 #endif

////////////////////////////////////////////////////////////////////////////////
// parameters for an ITEM
////////////////////////////////////////////////////////////////////////////////
 #ifndef ITEMPARAMS
  #define ITEMPARAMS  (ITEMLIST& item, ENTITY* user, ENTITY& target)
 #endif

////////////////////////////////////////////////////////////////////////////////
// gives the ITEM method address
////////////////////////////////////////////////////////////////////////////////
 #ifndef ITEMADDR
  #define ITEMADDR(itm)   &ITEM:: itm
 #endif

////////////////////////////////////////////////////////////////////////////////
// define the use method for an ITEM
////////////////////////////////////////////////////////////////////////////////
 #ifndef DEFITEM
  #define DEFITEM(itm)   ITEMRET ITEM :: itm ITEMPARAMS
 #endif
 
////////////////////////////////////////////////////////////////////////////////
// define the equip method for an ITEM
////////////////////////////////////////////////////////////////////////////////
 #ifndef DEFEQUIP
  #define DEFEQUIP(itm)   ITEMRET ITEM :: equip##itm ITEMPARAMS
 #endif

////////////////////////////////////////////////////////////////////////////////
// define the unequip method for an ITEM
////////////////////////////////////////////////////////////////////////////////
 #ifndef DEFUNEQUIP
  #define DEFUNEQUIP(itm)   ITEMRET ITEM :: unequip##itm ITEMPARAMS
 #endif

////////////////////////////////////////////////////////////////////////////////
// access to the requested item used in a call to useItem ()
////////////////////////////////////////////////////////////////////////////////
 #ifndef MIL
  #define MIL(index) \
  GLOBAL_MASTER_ITEM_LIST [index], \
  GLOBAL_MASTER_ITEM_LIST [index].m_strAlias, \
  GLOBAL_MASTER_ITEM_LIST [index].m_fpkItem
 #endif

////////////////////////////////////////////////////////////////////////////////
// call this now from the main source; it will access the common_association 
// map for items to get the index for you
////////////////////////////////////////////////////////////////////////////////
 #ifndef ADD_ITEM
  #define ADD_ITEM(alias,method_name,category) \
  { \
   int index = getItemIndex (GLOBAL_ITEM_MAP, alias); \
   if (index < 0) { \
    cout << "Cannot add unmapped item {" << #alias << "}" << endl; \
   } else { \
    GLOBAL_MASTER_ITEM_LIST [index].m_strAlias     = #alias ; \
    GLOBAL_MASTER_ITEM_LIST [index].m_fpkItem      = ITEMADDR (method_name); \
    GLOBAL_MASTER_ITEM_LIST [index].m_iPhysicalAtk = 0; \
    GLOBAL_MASTER_ITEM_LIST [index].m_iPhysicalDef = 0; \
    GLOBAL_MASTER_ITEM_LIST [index].m_iMagickalAtk = 0; \
    GLOBAL_MASTER_ITEM_LIST [index].m_iMagickalDef = 0; \
    GLOBAL_MASTER_ITEM_LIST [index].m_eCategory    = category; \
    GLOBAL_MASTER_ITEM_LIST [index].m_eType        = eItem; \
   } \
  } 
 #endif 


////////////////////////////////////////////////////////////////////////////////
// add 2 items to the MIL to represent a piece of equipment
////////////////////////////////////////////////////////////////////////////////
 #ifndef ADD_EQUIPMENT
  #define ADD_EQUIPMENT(alias,method_name,pha,phd,maa,mad,type) \
  { \
   int index = getItemIndex (GLOBAL_ITEM_MAP, alias); \
   if (index < 0) { \
    cout << "Cannot add unmapped item {" << #alias << "}" << endl; \
   } else { \
    GLOBAL_MASTER_ITEM_LIST [index].m_strAlias       = #alias ; \
    GLOBAL_MASTER_ITEM_LIST [index].m_fpkItem        = ITEMADDR(equip##method_name) ; \
    GLOBAL_MASTER_ITEM_LIST [index].m_iPhysicalAtk   = pha;  \
    GLOBAL_MASTER_ITEM_LIST [index].m_iPhysicalDef   = phd; \
    GLOBAL_MASTER_ITEM_LIST [index].m_iMagickalAtk   = maa; \
    GLOBAL_MASTER_ITEM_LIST [index].m_iMagickalDef   = mad; \
    GLOBAL_MASTER_ITEM_LIST [index+1].m_strAlias     = #alias ; \
    GLOBAL_MASTER_ITEM_LIST [index+1].m_fpkItem      = ITEMADDR(unequip##method_name) ; \
    GLOBAL_MASTER_ITEM_LIST [index+1].m_iPhysicalAtk = pha;  \
    GLOBAL_MASTER_ITEM_LIST [index+1].m_iPhysicalDef = phd; \
    GLOBAL_MASTER_ITEM_LIST [index+1].m_iMagickalAtk = maa; \
    GLOBAL_MASTER_ITEM_LIST [index+1].m_iMagickalDef = mad; \
    GLOBAL_MASTER_ITEM_LIST [index+1].m_eCategory    = eEquipment; \
    GLOBAL_MASTER_ITEM_LIST [index+1].m_eType        = type; \
    GLOBAL_MASTER_ITEM_LIST [index].m_eCategory      = eEquipment; \
    GLOBAL_MASTER_ITEM_LIST [index].m_eType          = type; \
   } \
  }
 #endif





////////////////////////////////////////////////////////////////////////////////
// helper for calling useItem ()
////////////////////////////////////////////////////////////////////////////////
 #ifndef ITEMDESC
  #define ITEMDESC(index) GLOBAL_MASTER_ITEM_LIST [index].m_strAlias
 #endif

////////////////////////////////////////////////////////////////////////////////
// just calls MIL
////////////////////////////////////////////////////////////////////////////////
 #ifndef MEL_EQUIP
  #define MEL_EQUIP(index) MIL(index)
 #endif

////////////////////////////////////////////////////////////////////////////////
// calls the next item in MIL 
////////////////////////////////////////////////////////////////////////////////
 #ifndef MEL_UNEQUIP
  #define MEL_UNEQUIP(index) MIL(index+1)
 #endif

////////////////////////////////////////////////////////////////////////////////
// quick global to class var hack
////////////////////////////////////////////////////////////////////////////////
 #ifndef CITEMDESC
  #define CITEMDESC(index) m_MIL [index].m_strAlias
 #endif

////////////////////////////////////////////////////////////////////////////////
// like MIL but for a class
////////////////////////////////////////////////////////////////////////////////
 #ifndef CMIL
  #define CMIL(index) m_MIL [index], m_MIL [index].m_strAlias, m_MIL [index].m_fpkItem
 #endif

////////////////////////////////////////////////////////////////////////////////
// end safe include
////////////////////////////////////////////////////////////////////////////////
#endif


 
 
 
