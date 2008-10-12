
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

ABILRET ENTITY :: useAbility (ABILRET (ABILITY::*action)(ENTITY*, ENTITY&), ENTITY& target)
{ 
 #if defined(DEBUG_BUILD)
  cerr << "DEBUG: useAbility() called by " << m_strAlias << endl;
  cerr << "DEBUG: func = " << action << endl;
  
  #if defined(ALLOW_DEBUG_PAUSE)
   Common :: pause("DEBUG: <PAUSED>");
  #endif
 #endif
 m_fpkAction = action;
 ABILITY inst;
 ABILRET sResults = static_cast <ABILRET> ( (inst.*m_fpkAction)(this, target) ); 
 
 #if defined(DEBUG_BUILD)
  
  #if defined(ALLOW_DEBUG_PAUSE)
   Common :: pause("DEBUG: <PAUSED>");
  #endif
 #endif
 
 return sResults;
}

