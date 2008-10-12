
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


#include "macros.h"

#include <string>

struct ITEMLIST;
class ENTITY;

enum eItemCategory
{
 eStory     = 0,
 eUsable    = 1,
 eEquipment = 2
};

enum eItemType
{
 eItem       = 0,
 eWeapon     = 1,
 eArmor      = 2,
 eAccessory  = 3
};

class ITEM
{
private:
   
public:
 ITEM ();
 virtual ~ITEM ();
   
 DEFITEM(Bandage);
 DEFITEM(Tea);
 DEFITEM(Birthwart);
 DEFITEM(Fenugreek);
 DEFITEM(WolfsBlood);
 DEFITEM(ChapterOnePotion);  
 DEFITEM(Brimstone);
 
 DEFEQUIP(LeatherArmor);
 DEFUNEQUIP(LeatherArmor);
 DEFEQUIP(BlackRobe);
 DEFUNEQUIP(BlackRobe);
 DEFEQUIP(BlueRobe);
 DEFUNEQUIP(BlueRobe);
 DEFEQUIP(HellAmulet);
 DEFUNEQUIP(HellAmulet);
 DEFEQUIP(DuskAmulet);
 DEFUNEQUIP(DuskAmulet);
 DEFEQUIP(DawnAmulet);
 DEFUNEQUIP(DawnAmulet);
};

// maintains a master list of items
// need an instance of this
struct ITEMLIST
{
 std::string   m_strAlias;
 eItemCategory m_eCategory;
 eItemType     m_eType;
 int           m_iPhysicalAtk;
 int           m_iPhysicalDef;
 int           m_iMagickalAtk;
 int           m_iMagickalDef;
 ITEMRET (ITEM::*m_fpkItem)ITEMPARAMS;
};







