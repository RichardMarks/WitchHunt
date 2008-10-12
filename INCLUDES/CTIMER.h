
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

/*
 A Simple Timer Class by Richard Marks
 (C) Copyright 2007, CCPS Solutions
 http://www.ccpssolutions.com
 
 Example Usage:
 
 // Create an instance of the CTIMER class
 CTIMER* kTimer = new CTIMER();
 
 // set the timer for 1 second
 kTimer->setTimer (1);

 // start the timer
 kTimer->startTimer ();

 // give a notice (not required to work)
 cout << "starting timer: " << endl << flush;

 // enter a loop that ends when getTicking() returns false
 // you can force an exit by calling stopTimer ()
 while (kTimer->getTicking ())
 {
  // do something during the time to wait
  cout << "tick, ";
 }

 // end timer has stopped, tell the user (not required)
 cout << "timer stopped" << endl;

 // delete the instance of the CTIMER class
 // since it is not being used anymore
 delete kTimer;

*/

#ifndef __LIBRARY_CTIMER_H__
#define __LIBRARY_CTIMER_H__

#include <ctime>

class CTIMER
{
private:
 int  m_iStartTime;
 int  m_iCurrentTime;
 int  m_iStopTime;
 int  m_iDelay;
 bool m_bTicking;
 
public:
 CTIMER              ();
 virtual ~CTIMER     ();
 
 void setTimer       (int iSeconds);
 void resetTimer     ();
 
 void startTimer     ();
 void stopTimer      ();
 
 int  getStartTime   ();
 int  getCurrentTime ();
 int  getStopTime    ();
 bool getTicking     ();
};

#endif

