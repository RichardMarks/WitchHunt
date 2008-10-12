
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
// buildGrowthTable.cpp
////////////////////////////////////////////////////////////////////////////////

// include the project header
#include "project.h"

#include <cmath>
using namespace std;

 // growth = experience * current_level ^ log(growth_percentage) / log(2)

#define GROWTH_PERCENTAGE 1.739

void buildGrowthTable ()
{
 for (int index = 0; index < MAXIMUM_EXP_LEVEL; index++)
 {
 
  int iExperience = (index * 75);
  float fGrowth = logf (GROWTH_PERCENTAGE) / logf (2);
 
  iGrowthTable [index] = (int)(iExperience * powf (index, fGrowth));
  
 }
}




