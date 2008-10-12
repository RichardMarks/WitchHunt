
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

bool ENTITY :: loadTemplate (std::string strFilename)
{
 int index = 0, iAbilityCount = 0, iItemCount = 0, iEquipCount = 0;
 std::string garbage = "";
  
 char sTemplateName [255] = "";

 sprintf (sTemplateName, "%s-template.txt", strFilename.c_str ()); 
 ifstream checkFile (sTemplateName);
 if ( checkFile.fail () )
 {
  sprintf (sTemplateName, "bin\\%s-template.txt", strFilename.c_str ()); 
 }else{checkFile.close ();}
   
 ifstream inFile (sTemplateName);

 if (inFile.is_open ())
 {
  #if defined(DEBUG_BUILD)
  cerr << "DEBUG: Loading Template: " << sTemplateName << endl;
   #if defined (ALLOW_DEBUG_PAUSE)
    Common :: pause("DEBUG: <PAUSED>");
   #endif
  #endif
  // read filename and description header
  std::getline (inFile, garbage);
  std::getline (inFile, garbage);

  // read alias and class
  inFile >> garbage >> ws; std::getline (inFile, m_strAlias);
  inFile >> garbage >> ws; std::getline (inFile, m_strClass);

  #if defined(DEBUG_BUILD)
  cerr << "DEBUG: Alias: " << m_strAlias << endl;
  cerr << "DEBUG: Class: " << m_strClass << endl;
  #if defined (ALLOW_DEBUG_PAUSE)
    Common :: pause("DEBUG: <PAUSED>");
   #endif
  #endif

  // read stats
  inFile >> garbage; inFile >> m_iLevel >> ws;
  inFile >> garbage; inFile >> m_iMaxHp >> ws;
  inFile >> garbage; inFile >> m_iMaxMp >> ws;
  inFile >> garbage; inFile >> m_iStrength >> ws; 
  inFile >> garbage; inFile >> m_iVitality >> ws;
  inFile >> garbage; inFile >> m_iPhysicalAtk >> ws;
  inFile >> garbage; inFile >> m_iPhysicalDef >> ws;
  inFile >> garbage; inFile >> m_iMagickalAtk >> ws;
  inFile >> garbage; inFile >> m_iMagickalDef >> ws;
  inFile >> garbage; inFile >> m_iMoney >> ws;
  inFile >> garbage; inFile >> m_iExperience >> ws;

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

  // read number of abilities
  inFile >> garbage; inFile >> iAbilityCount >> ws;
  
  // read abilities
  {
   for (int index = 0; index < iAbilityCount; index++)
   {
    std::string strTemp;
    std::getline (inFile, strTemp);
    inFile >> ws; 
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
  
  // read number of items
  inFile >> garbage >> iItemCount >> ws;
    
  // read items
  {
   for (int index = 0; index < iItemCount; index++)
   {
    std::string strTemp;
    std::getline (inFile, strTemp);
    inFile >> ws;
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

  // read number of equipped items
  inFile >> garbage; inFile >> iEquipCount >> ws;

  // read equipped items
  for (index = 0; index < iEquipCount; index++)
  {
   std::string strTemp;
   inFile >> ws; std::getline (inFile, strTemp);
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

  // close data file
  inFile.close ();

  // set other entity member variables to defaults
  m_eState       = eNormal;
  m_iXpos        = 0;
  m_iYpos        = 0;
  m_iHp          = m_iMaxHp;
  m_iMp          = m_iMaxMp;
  m_iSpacesMoved = 0;

  // return true so that the caller knows load succeeded
  return true;
 }

 // return false so that the caller knows load failed
 return false; 
}

