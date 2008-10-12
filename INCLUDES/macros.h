
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


// generic macros

// adds a to the variable v and limits to imax
/*
#ifndef INC_AND_LIMIT
 #define INC_AND_LIMIT(v,a,imax) v+=a;if(v>imax)v=imax
#endif 

// subtracts a from the variable v and limits to imin
#ifndef DEC_AND_LIMIT
 #define DEC_AND_LIMIT(v,a,imin) v-=a;if(v<imin)v=imin
#endif 
*/

#ifndef __INCDEC_TEMPLATES__
template <typename T> 
void INC_AND_LIMIT (T& v, T a, T m) { v += a; if (v > m) { v = m; } }


template <typename T> 
void DEC_AND_LIMIT (T& v, T a, T m) { v -= a; if (v < m) { v = m; } }
#define __INCDEC_TEMPLATES__
#endif


// include macros for the ABILITY class
#include "ABILITY_macros.h"

// include macros for the ITEM class
#include "ITEM_macros.h"

// include macros for the BATTLE class
#include "BATTLE_macros.h"





