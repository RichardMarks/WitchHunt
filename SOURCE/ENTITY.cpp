
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

//#include "entity_libraryheader.h"

//#include <cmath>
//using namespace std;


#define GROWTH_PERCENTAGE 1.739

////////////////////////////////////////////////////////////////////////////////
// constructor
////////////////////////////////////////////////////////////////////////////////
ENTITY :: ENTITY ()              
{
 m_fpkAction    = NULL;
 m_eState       = eNormal;
 m_strAlias     = "Undefined";
 m_strClass     = "Undefined";
 m_iXpos        = 0; m_iYpos        = 0; m_iHp          = 0; m_iMp          = 0;
 m_iMaxHp       = 0; m_iMaxMp       = 0; m_iStrength    = 0; m_iVitality    = 0;
 m_iPhysicalAtk = 0; m_iPhysicalDef = 0; m_iMagickalAtk = 0; m_iMagickalDef = 0;
 m_iMoney       = 0; m_iLevel       = 0; m_iExperience  = 0; m_iSpacesMoved = 0;
 
 #ifdef DEBUG_BUILD
  cerr << "DEBUG: instance of ENTITY class created" << endl;
 #endif 
}

////////////////////////////////////////////////////////////////////////////////
// alternate constructor
////////////////////////////////////////////////////////////////////////////////
ENTITY :: ENTITY (std :: string strTemplate)
{
 if (loadTemplate (strTemplate) == false)
 {
  #ifdef DEBUG_BUILD
   cout << "WARNING! Could not load the Template: " << strTemplate << endl;
  #endif 
 }
 else
 { 
  #ifdef DEBUG_BUILD
   cerr << "DEBUG: instance of ENTITY class created from template:" 
        << strTemplate << endl;
  #endif 
 } 
}

////////////////////////////////////////////////////////////////////////////////
// destructor
////////////////////////////////////////////////////////////////////////////////
ENTITY :: ~ENTITY ()
{
 #ifdef DEBUG_BUILD
  cerr << "DEBUG: instance of ENTITY class destroyed: " << m_strAlias << endl;
  Common :: pause ("DEBUG: -PAUSED- (Press Return)");
 #endif 
}

////////////////////////////////////////////////////////////////////////////////
// removes an item from the item list for the entity
////////////////////////////////////////////////////////////////////////////////
void ENTITY :: x_useItem (std::string strItem)
{ 
 std::vector<std::string>::iterator i;
 for (i = m_vstrItems.begin (); i < m_vstrItems.end (); i++)
 {
  if (strItem == (*i))
  {
   #ifdef DEBUG_BUILD
    cerr << "DEBUG: x_useItem() called by " << m_strAlias << endl;
   #endif
   m_vstrItems.erase (i);
   return;
  } 
 }
}

////////////////////////////////////////////////////////////////////////////////
// adds an item to the entity's equipped item list
////////////////////////////////////////////////////////////////////////////////
void ENTITY :: x_equipItem (std::string strItem)
{
 if (!hasItemEquipped (strItem))
 {
  #ifdef DEBUG_BUILD
   cerr << "DEBUG: x_equipItem() called by " << m_strAlias << endl;
  #endif
  m_vstrEquipped.push_back (strItem);
 }
}

////////////////////////////////////////////////////////////////////////////////
// removes an item from the entity's equipped item list
////////////////////////////////////////////////////////////////////////////////  
void ENTITY :: x_unequipItem (std::string strItem)
{
 std::vector<std::string>::iterator i;
 for (i = m_vstrEquipped.begin (); i < m_vstrEquipped.end (); i++)
 {
  if (strItem == (*i))
  {
   #ifdef DEBUG_BUILD
    cerr << "DEBUG: x_unequipItem() called by " << m_strAlias << endl;
   #endif
   m_vstrEquipped.erase (i);
   return; 
  } 
 }
} 

////////////////////////////////////////////////////////////////////////////////
// generic string vector listing that also counts duplicates
////////////////////////////////////////////////////////////////////////////////
void ENTITY :: x_listInventory (std::vector<std::string>& strItems)
{
 #ifdef DEBUG_BUILD
  cerr << "DEBUG: x_listInventory() called by " << m_strAlias << endl;
 #endif
   
 int iCount = 0;
 int iIndex = 1;
 std::string strTarget;
 std::vector<std::string> vstrTemp;
 
 for (int index = 0; index < int(strItems.size ()); index++)
 {
  vstrTemp.push_back (strItems.at (index));
 }
 
 while (!vstrTemp.empty ())
 {
  strTarget = vstrTemp.at (0);
  iCount = 0;
  
  for (int index = 0; index < int(vstrTemp.size ()); index++)
  {
   if (vstrTemp.at (index) == strTarget)
   {
    vstrTemp.erase (vstrTemp.begin () + index);
    iCount++;
    index--;
   }
  }
  
  cout << PRINT_OFFSET 
       << setw(30) 
       << setiosflags(ios::left) << strTarget << " x" << iCount 
       << setw(0) << resetiosflags(ios::left) << endl;
  iIndex++;
 }
}


void ENTITY :: buildGrowthTable ()
{
 for (int index = 0; index < MAXIMUM_EXP_LEVEL; index++)
 {
 
  int iExperience = (index * 75);
  float fGrowth = logf (GROWTH_PERCENTAGE) / logf (2);
 
  m_iGrowthTable [index]  = 250;
  m_iGrowthTable [index] += static_cast <int> (iExperience * powf (index, fGrowth));
  
 }
}

void ENTITY :: clearInventory  ()
{
 m_vstrItems.clear ();
 m_vstrEquipped.clear ();
}

void ENTITY :: clearAbilityList()
{
 m_vstrAbilities.clear ();
}

void ENTITY :: saveMe (ofstream& os)
{
 os << m_strAlias << endl;
 os << m_iXpos << endl;
 os << m_iYpos << endl;
 os << m_iHp << endl;
 os << m_iMp << endl;
 os << m_iMaxHp << endl;
 os << m_iMaxMp << endl;
 os << m_iStrength << endl;
 os << m_iVitality << endl;
 os << m_iPhysicalAtk << endl;
 os << m_iPhysicalDef << endl;
 os << m_iMagickalAtk << endl;
 os << m_iMagickalDef << endl;
 os << m_iMoney << endl;
 os << m_iLevel << endl;
 os << m_iExperience << endl;
 os << static_cast<int> ( m_iSpacesMoved ) << endl;
 
 {
  os << m_vstrAbilities.size () << endl;
  for (int n = 0; n < m_vstrAbilities.size (); n++)
  {
   os << m_vstrAbilities.at (n) << endl;
  }
 }
 
 {
  os << m_vstrItems.size () << endl;
  for (int n = 0; n < m_vstrItems.size (); n++)
  {
   os << m_vstrItems.at (n) << endl;
  }
 }
 
 {
  os << m_vstrEquipped.size () << endl;
  for (int n = 0; n < m_vstrEquipped.size (); n++)
  {
   os << m_vstrEquipped.at (n) << endl;
  }
 }
 
}

void ENTITY :: loadMe (ifstream& is)
{
 getline (is, m_strAlias);
 is >> m_iXpos >> ws;
 is >> m_iYpos >> ws;
 is >> m_iHp >> ws;
 is >> m_iMp >> ws;
 is >> m_iMaxHp >> ws;
 is >> m_iMaxMp >> ws;
 is >> m_iStrength >> ws;
 is >> m_iVitality >> ws;
 is >> m_iPhysicalAtk >> ws;
 is >> m_iPhysicalDef >> ws;
 is >> m_iMagickalAtk >> ws;
 is >> m_iMagickalDef >> ws;
 is >> m_iMoney >> ws;
 is >> m_iLevel >> ws;
 is >> m_iExperience >> ws;
 is >> m_iSpacesMoved >> ws;
 
 #if defined(DEBUG_BUILD)
  cerr << "DEBUG: Level: " << m_iLevel << endl;
  cerr << "DEBUG: MaxHp: " << m_iMaxHp << endl;
  cerr << "DEBUG: MaxMp: " << m_iMaxMp << endl;
  cerr << "DEBUG: Strength: " << m_iStrength << endl;
  cerr << "DEBUG: Vitality: " << m_iVitality << endl;
  cerr << "DEBUG: P Atk: " << m_iPhysicalAtk << endl;
  cerr << "DEBUG: P Def: " << m_iPhysicalDef << endl;
  cerr << "DEBUG: M Atk: " << m_iMagickalAtk << endl;
  cerr << "DEBUG: M Def: " << m_iMagickalDef << endl;
  cerr << "DEBUG: Money: " << m_iMoney << endl;
  cerr << "DEBUG: Exp: " << m_iExperience << endl;
  #if defined (ALLOW_DEBUG_PAUSE)
    Common :: pause("DEBUG: <PAUSED>");
   #endif
  #endif
 
 
 string strTemp = "";
 int iCounter   = 0;
 {
  m_vstrAbilities.clear ();
  is >> iCounter >> ws;
  #if defined(DEBUG_BUILD)
   cerr << "DEBUG: Counter = " << iCounter << endl;
  #endif
  for (int n = 0; n < iCounter; n++)
  {
   getline (is, strTemp);
   m_vstrAbilities.push_back (strTemp);
   #if defined(DEBUG_BUILD)
    cerr << "DEBUG: Ability: " << char(34) << strTemp << char(34) << endl;
    #endif
  }
  #if defined(DEBUG_BUILD)
    #if defined (ALLOW_DEBUG_PAUSE)
    Common :: pause("DEBUG: <PAUSED>");
    #endif
    #endif 
 }
 
 {
  m_vstrItems.clear ();
  is >> iCounter >> ws;
  #if defined(DEBUG_BUILD)
   cerr << "DEBUG: Counter = " << iCounter << endl;
  #endif
  for (int n = 0; n < iCounter; n++)
  {
   getline (is, strTemp);
   m_vstrItems.push_back (strTemp);
   #if defined(DEBUG_BUILD)
     cerr << "DEBUG: Item: " << char(34) << strTemp << char(34) << endl;
    #endif 
  }
  #if defined(DEBUG_BUILD)
    #if defined (ALLOW_DEBUG_PAUSE)
    Common :: pause("DEBUG: <PAUSED>");
    #endif
    #endif 
 }
 
 {
  m_vstrEquipped.clear ();
  is >> iCounter >> ws;
  #if defined(DEBUG_BUILD)
   cerr << "DEBUG: Counter = " << iCounter << endl;
  #endif
  for (int n = 0; n < iCounter; n++)
  {
   getline (is, strTemp);
   m_vstrEquipped.push_back (strTemp);
   #if defined(DEBUG_BUILD)
     cerr << "DEBUG: Equipment: " << char(34) << strTemp << char(34) << endl;
   #endif 
  }
  #if defined(DEBUG_BUILD)
    #if defined (ALLOW_DEBUG_PAUSE)
    Common :: pause("DEBUG: <PAUSED>");
    #endif
    #endif 
 }
 
}


