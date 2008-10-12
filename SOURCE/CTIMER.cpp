
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
// CTIMER.cpp
//
// Implementation of the CTIMER class
////////////////////////////////////////////////////////////////////////////////

#include "CTIMER.h"
#include <iostream>
using namespace std;
CTIMER :: CTIMER ()
{ 
 resetTimer (); 
 #ifdef DEBUG_BUILD
  cerr << "DEBUG: instance of CTIMER class created" << endl;
 #endif
}
////////////////////////////////////////////////////////////////////////////////
CTIMER :: ~CTIMER ()
{
 #ifdef DEBUG_BUILD
  cerr << "DEBUG: instance of CTIMER class destroyed" << endl;
 #endif
}
////////////////////////////////////////////////////////////////////////////////
void CTIMER :: setTimer (int iSeconds) 
{ 
 m_iDelay = iSeconds; 
}
////////////////////////////////////////////////////////////////////////////////
void CTIMER :: resetTimer ()             
{ 
 m_iStartTime   = 0;
 m_iStopTime    = 0;
 m_iCurrentTime = 0;
 m_iDelay       = 0;
 m_bTicking     = false;
}
////////////////////////////////////////////////////////////////////////////////
void CTIMER :: startTimer ()             
{ 
 m_iStartTime = static_cast <int> ( time (NULL) ); 
 m_iStopTime  = m_iStartTime + m_iDelay;
 m_bTicking   = true; 
}
////////////////////////////////////////////////////////////////////////////////
void CTIMER :: stopTimer ()
{ 
 m_bTicking = false; 
}
////////////////////////////////////////////////////////////////////////////////
int CTIMER :: getStartTime ()
{ 
 return m_iStartTime; 
}
////////////////////////////////////////////////////////////////////////////////
int CTIMER :: getCurrentTime ()             
{ 
 return m_iCurrentTime; 
}
////////////////////////////////////////////////////////////////////////////////
int CTIMER :: getStopTime ()             
{ 
 return m_iStopTime; 
}
////////////////////////////////////////////////////////////////////////////////
bool CTIMER :: getTicking ()
{ 
 if ( static_cast <int> ( time (NULL) ) == m_iStopTime )
 {
  m_bTicking = false;
 } 
 return m_bTicking; 
}
////////////////////////////////////////////////////////////////////////////////

