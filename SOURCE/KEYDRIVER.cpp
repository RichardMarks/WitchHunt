
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

#include "KEYDRIVER.h"
#include <conio.h>

namespace Common
{
 const char C_UP_ARROW    = 72;
 const char C_DOWN_ARROW  = 80;
 const char C_LEFT_ARROW  = 75;
 const char C_RIGHT_ARROW = 77;
 const char C_TAB_KEY     = 9;
 const char C_ESC_KEY     = 27;

 KEYDRIVER :: ~KEYDRIVER ()      { m_cKeyPress = 0; }
 void KEYDRIVER :: install ()    { m_cKeyPress = kbhit (); }
 char KEYDRIVER :: getKey ()     { m_cKeyPress = getch (); return m_cKeyPress; }
 bool KEYDRIVER :: upArrow ()    { return static_cast<bool> (m_cKeyPress == C_UP_ARROW); }
 bool KEYDRIVER :: downArrow ()  { return static_cast<bool> (m_cKeyPress == C_DOWN_ARROW); }
 bool KEYDRIVER :: leftArrow ()  { return static_cast<bool> (m_cKeyPress == C_LEFT_ARROW); }
 bool KEYDRIVER :: rightArrow () { return static_cast<bool> (m_cKeyPress == C_RIGHT_ARROW); }
 bool KEYDRIVER :: tabKey ()     { return static_cast<bool> (m_cKeyPress == C_TAB_KEY); }
 bool KEYDRIVER :: escKey ()     { return static_cast<bool> (m_cKeyPress == C_ESC_KEY); }
 
} // end namespace

