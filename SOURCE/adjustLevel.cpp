
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
//#include "project.h"

/*
 this function sets the enemies level equal to the level of the hero.
 this is a gameplay balancing function and can be augmented as needed 
 to better enhance the gameplay.
*/



void adjustLevel (std :: vector <ENTITY*> vpkEnemies)
{
 // min + (rand() % (max - min))
 int x;
 for (int index = 0; index < vpkEnemies.size(); index++)
 {
  // if hero is lvl 1 dont adjust
  if(kHero.m_iLevel == 1)
  {
   return;
  }
  // adjust for a level of x or x - 1
  x = (kHero.m_iLevel - 1) + (rand() % (kHero.m_iLevel - (kHero.m_iLevel - 1)));
  vpkEnemies.at(index)->levelUp (x);
 }
 
 return;
}
