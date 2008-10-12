
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
// story_End.cpp
////////////////////////////////////////////////////////////////////////////////

// include the project header
//#include "project.h"

void storyEnd (ENTITY &e, int index)
{
 if (iStoryProgress[2] == 1)
 {
  vector<ENTITY*> vpkBoss;
  
  vpkBoss.push_back (new ENTITY ("Azrael"));
  vpkBoss.push_back (new ENTITY ("Hell Hound"));
  vpkBoss.push_back (new ENTITY ("Hell Hound"));
  
  INITIATE_BATTLE (rkHero, vpkBoss);
  
  vector<ENTITY*> :: iterator iter;
  for (iter = vpkBoss.begin(); iter != vpkBoss.end(); ++iter)
  {
   if ( (*iter) )
    delete (*iter);
   (*iter) = NULL; 
   //vpkBoss.erase (iter);
  }
 }
}

