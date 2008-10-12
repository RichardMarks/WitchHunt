
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

// Common Include

// namespace Common
// hr - draws a horizontal line
// input - prompts user for input, returns std::string
// cint = returns an int from an std::string
#ifndef __COMMON_H__
#define __COMMON_H__

#include <string>
#include <iostream>
#include <cstdlib>
#include <map>

typedef std :: map <std :: string, int> common_association;
typedef std :: map <std :: string, int> :: iterator common_association_iterator;

const std :: string strPrintOffset = "\t";
const std :: string strOffsetEndl  = "\n\t";
const std :: string center_press_return = "                                   Press Return";

const char BoxTL = 201;
const char BoxTC = 205;
const char BoxTR = 187;
const char BoxLC = 186;
const char BoxRC = 186;
const char BoxBL = 200;
const char BoxBC = 205;
const char BoxBR = 188;


#ifndef PRINT_OFFSET
 #define PRINT_OFFSET strPrintOffset
#endif

#ifndef OFFSET_ENDL
 #define OFFSET_ENDL strOffsetEndl
#endif

#ifndef PRINT_VERTICAL_OFFSET
 #define PRINT_VERTICAL_OFFSET 5
#endif

namespace Common
{
 extern inline void hr (void);
 extern std :: string input        (std :: string strPrompt = "");
 extern int         cint           (std :: string strValue);
 extern void        pause          (std :: string strPrompt = "Press Return");
 extern void        clearscreen    (int x = 0);
 extern int         getmappedindex (common_association& caMap, std :: string strAlias);
 extern void        mapintoncamap  (common_association& caMap, std :: string strAlias, int iIndex);
 extern void        center         (char* text);
 extern void        present        (std :: string strText, int iDelay = 15);
 
 extern void        dialogue       (std :: string strSpeaker, std :: string strText, bool bMoreText = false, bool bClearScreen = true);
 
 extern void        DrawBoxTop     (int width);
 extern void        DrawBoxBottom  (int width);
 extern int         random         (int vMin, int vMax);
 
};

#endif


