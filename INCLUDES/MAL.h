
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
// abilities
//
// MAP_ABILITY (alias, index);
////////////////////////////////////////////////////////////////////////////////
 
 #ifdef DEBUG_BUILD
  cerr << "DEBUG: Building Master Ability List" << endl;
 #endif
 
 #ifdef DEBUG_BUILD
  cerr << "DEBUG: Mapping abilities" << endl;
 #endif
  
 MAP_ABILITY (Attack,                   0); 
 MAP_ABILITY (Ferocious Strike,         1); 
 MAP_ABILITY (Heal,                     2); 
 MAP_ABILITY (Mind Blast,               3); 
 MAP_ABILITY (Unholy Aura,              4); 
 MAP_ABILITY (Vamp Bite,                5); 
 MAP_ABILITY (Curse,                    6); 
 MAP_ABILITY (Wolf Bite,                7); 
 MAP_ABILITY (Dark Stare,               8); 
 MAP_ABILITY (Summon,                   9); 
 MAP_ABILITY (Slash,                    10); 

////////////////////////////////////////////////////////////////////////////////
// add abilities to the master ability list
// 
// ADD_ABILITY (alias, method_name); 
// category can be eStory or eUsable
//////////////////////////////////////////////////////////////////////////////// 

 #ifdef DEBUG_BUILD
  cerr << "DEBUG: Adding abilities" << endl;
 #endif 

 ADD_ABILITY (Attack,                   poa_Attack);
 ADD_ABILITY (Ferocious Strike,         poa_FerociousStrike);
 ADD_ABILITY (Heal,                     poa_Heal);
 ADD_ABILITY (Mind Blast,               poa_MindBlast);
 ADD_ABILITY (Unholy Aura,              poa_UnholyAura);
 ADD_ABILITY (Vamp Bite,                poa_VampBite);
 ADD_ABILITY (Curse,                    poa_Curse);
 ADD_ABILITY (Wolf Bite,                poa_WolfBite);
 ADD_ABILITY (Dark Stare,               noa_DarkStare);
 ADD_ABILITY (Summon,                   noa_Summon);
 ADD_ABILITY (Slash,                    noa_Slash);
 
 
 
 
 
 
