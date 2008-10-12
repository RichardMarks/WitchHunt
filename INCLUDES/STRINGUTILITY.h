
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

// STRINGUTILITY.h
#ifndef __LIBRARY_STRINGUTILITY_H__
#define __LIBRARY_STRINGUTILITY_H__

#include <string>
#include <vector>

#define STRINGUTILITY_STR std :: string
#define STRINGUTILITY_VEC std :: vector
#define STRINGUTILITY_CER std :: cerr 

class STRINGUTILITY_REPLACE
{
public:
 STRINGUTILITY_REPLACE ();
 STRINGUTILITY_REPLACE (STRINGUTILITY_STR strFind, STRINGUTILITY_STR strReplace);
 virtual ~STRINGUTILITY_REPLACE ();
 STRINGUTILITY_STR m_strFind;
 STRINGUTILITY_STR m_strReplace;
};

class STRINGUTILITY
{
private:
 STRINGUTILITY_VEC <STRINGUTILITY_REPLACE*> m_vkReplace;
 
public:
 STRINGUTILITY ();
 virtual ~STRINGUTILITY ();
 void clear ();
 void addPair (STRINGUTILITY_STR strFind, STRINGUTILITY_STR strReplace);
 STRINGUTILITY_STR replace (STRINGUTILITY_STR strSource); 
};

#endif

