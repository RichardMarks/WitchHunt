
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

#ifndef __LIBRARY_ENTITY_H__
#define __LIBRARY_ENTITY_H__

#include <string>
#include <vector>
#include <fstream>

#include "macros.h"

#define MAXIMUM_EXP_LEVEL 100


////////////////////////////////////////////////////////////////////////////////
// FORWARD TYPE DECLARATIONS
////////////////////////////////////////////////////////////////////////////////
struct ITEMLIST;
class  ITEM;
class  ABILITY;
class  ENTITY;

////////////////////////////////////////////////////////////////////////////////
// ENTITY LOGISTICS STATE ENUMERATION
////////////////////////////////////////////////////////////////////////////////
enum eEntityState
{
 eNormal        = 0,
 ePoisoned      = 1,
 eBlind         = 2,
 eConfused      = 3,
 eSilenced      = 4,
 eFrozen        = 5,
 eDying         = 6,
 eDead          = 7,
 eUnDead        = 8
};


////////////////////////////////////////////////////////////////////////////////
// ENTITY DIRECTION MOVEMENT ENUMERATION
////////////////////////////////////////////////////////////////////////////////
enum eMotionDirection
{
 eNorth     = 0,
 eSouth     = 1,
 eEast      = 2,
 eWest      = 3,
 eNorthWest = 4,
 eNorthEast = 5,
 eSouthWest = 6,
 eSouthEast = 7
};


////////////////////////////////////////////////////////////////////////////////
// ENTITY CLASS DECLARATION
////////////////////////////////////////////////////////////////////////////////
class ENTITY
{ 
private:

////////////////////////////////////////////////////////////////////////////////
// PRIVATE MEMBERS
////////////////////////////////////////////////////////////////////////////////
 ABILRET (ABILITY::*m_fpkAction)(ENTITY*, ENTITY&);
 ITEMRET (ITEM::*m_fpkItem)ITEMPARAMS;
 
////////////////////////////////////////////////////////////////////////////////
// PRIVATE METHODS
////////////////////////////////////////////////////////////////////////////////
 void x_useItem (std::string strItem);    // removes item from inventory
 void x_equipItem (std::string strItem); // adds item to equippped list 
 void x_unequipItem (std::string strItem);  // removes item from equipped list
 void x_listInventory (std::vector<std::string>& strItems); // lists the 'inventory' that is in the vector

public:

////////////////////////////////////////////////////////////////////////////////
// CONSTRUCTORS and DESTRUCTORS
////////////////////////////////////////////////////////////////////////////////
 ENTITY ();              // constructor
 ENTITY (std :: string strTemplate); // alternate constructor
 virtual ~ENTITY ();     // destructor

////////////////////////////////////////////////////////////////////////////////
// MEMBERS
////////////////////////////////////////////////////////////////////////////////
 std::string              m_strAlias;       // name
 std::string              m_strClass;       // class (warrior, thief cleric)
 int                      m_iXpos;          // x position
 int                      m_iYpos;          // y position
 int                      m_iHp;            // health
 int                      m_iMp;            // mana
 int                      m_iMaxHp;         // max health
 int                      m_iMaxMp;         // max mana
 int                      m_iStrength;      // strength
 int                      m_iVitality;      // vitality
 int                      m_iPhysicalAtk;   // physical attack
 int                      m_iPhysicalDef;   // physical defense
 int                      m_iMagickalAtk;   // magic attack
 int                      m_iMagickalDef;   // magic defense
 unsigned int             m_iMoney;         // money 
 int                      m_iLevel;         // current level
 unsigned int             m_iExperience;    // current exp
 unsigned char            m_iSpacesMoved;   // how long until a battle 
 eEntityState             m_eState;         // flag for alive and dead
 std::vector<std::string> m_vstrAbilities;  // abilities that the entity "knows"
 std::vector<std::string> m_vstrItems;      // item inventory
 std::vector<std::string> m_vstrEquipped;   // items that are equipped

 int                      m_iGrowthTable [MAXIMUM_EXP_LEVEL]; // exponential growth chart

////////////////////////////////////////////////////////////////////////////////       
// METHODS - sorted by return type and params
//////////////////////////////////////////////////////////////////////////////// 


 int  abilityIndex    (std::string strAbility);
 bool loadTemplate    (std::string strFilename);
 bool learnedAbility  (std::string strAbility);
 bool hasItem         (std::string strItem);
 bool hasItemEquipped (std::string strItem);
 void rest            ();
 void canLevel        ();
 void levelUp         (int x = 0);
 void showAbilities   ();
 void showInventory   ();
 void showEquipped    ();
 void showStats       ();
 void buildGrowthTable();
 void clearInventory  ();
 void clearAbilityList();
 void giveHp          (int iAmount);
 void giveMp          (int iAmount);
 void giveMaxHp       (int iAmount);
 void giveMaxMp       (int iAmount);
 void giveStrength    (int iAmount);
 void giveVitality    (int iAmount);
 void givePhysicalAtk (int iAmount);
 void givePhysicalDef (int iAmount);
 void giveMagickalAtk (int iAmount);
 void giveMagickalDef (int iAmount);
 void giveMoney       (unsigned int iAmount);
 void giveLevel       (int iAmount);
 void giveExperience  (unsigned int iAmount);   
 void takeHp          (int iAmount);
 void takeMp          (int iAmount);
 void takeMaxHp       (int iAmount);
 void takeMaxMp       (int iAmount);
 void takeStrength    (int iAmount);
 void takeVitality    (int iAmount);
 void takePhysicalAtk (int iAmount);
 void takePhysicalDef (int iAmount);
 void takeMagickalAtk (int iAmount);
 void takeMagickalDef (int iAmount);
 void takeMoney       (unsigned int iAmount);
 void takeDamage      (int iAmount);
 void setPosition     (int iXpos = 0, int iYpos = 0);
 void dropItem        (std::string strItem);
 void learnAbility    (std::string strAbility); 
 void navigate        (eMotionDirection eDir); 
 void giveItem        (std::string strItem, int iAmount = 1, bool bPrintMsg = true); 
 void outputStat      (int st, const char* desc, int stat_digits); 
 ABILRET useAbility   (ABILRET (ABILITY::*action)(ENTITY*, ENTITY&), ENTITY& target); 
 ITEMRET useItem      (ITEMLIST& ilist, std::string strItem, ITEMRET (ITEM::*item)ITEMPARAMS, ENTITY& target);
 ITEMRET equipItem    (ITEMLIST& ilist, std::string strItem, ITEMRET (ITEM::*item)ITEMPARAMS, ENTITY& target);
 ITEMRET unequipItem  (ITEMLIST& ilist, std::string strItem, ITEMRET (ITEM::*item)ITEMPARAMS, ENTITY& target); 
 std :: string getVitalString ();
 void saveMe          (std :: ofstream& os);
 void loadMe          (std :: ifstream& is);
};
////////////////////////////////////////////////////////////////////////////////
#endif
