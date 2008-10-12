
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

// STRINGUTILITY.cpp

#include "STRINGUTILITY.h"
#include <iostream>
using namespace std;
STRINGUTILITY_REPLACE :: STRINGUTILITY_REPLACE ()
{
 m_strFind    = "";
 m_strReplace = "";
 #ifdef DEBUG_BUILD
 STRINGUTILITY_CER << "\nSTRINGUTILITY_REPLACE constructor called without params\n";
 #endif
}

STRINGUTILITY_REPLACE :: STRINGUTILITY_REPLACE (STRINGUTILITY_STR strFind, STRINGUTILITY_STR strReplace)
{
 m_strFind    = strFind;
 m_strReplace = strReplace;
 #ifdef DEBUG_BUILD
 STRINGUTILITY_CER << "\nSTRINGUTILITY_REPLACE constructor called with params:\n\t1."
      << strFind 
      << "\n\t2. " 
      << strReplace << "\n";
 #endif
}

STRINGUTILITY_REPLACE :: ~STRINGUTILITY_REPLACE ()
{
 /* nothing to do really */
 #ifdef DEBUG_BUILD
 STRINGUTILITY_CER << "\nSTRINGUTILITY_REPLACE destructor called\n";
 #endif
}

STRINGUTILITY :: STRINGUTILITY ()
{
 #ifdef DEBUG_BUILD
 STRINGUTILITY_CER << "\nSTRINGUTILITY constructor called\n";
 #endif
 /* nothing to do really */
}

STRINGUTILITY :: ~STRINGUTILITY ()
{
 #ifdef DEBUG_BUILD
 STRINGUTILITY_CER << "\nSTRINGUTILITY destructor called\n";
 #endif
 // delete all pointers in vector
 STRINGUTILITY_VEC <STRINGUTILITY_REPLACE*> :: iterator iter = m_vkReplace.begin ();
 while ( iter < m_vkReplace.end () )
 {
  if ( (*iter) )
  {
   delete (*iter);
   #ifdef DEBUG_BUILD
   STRINGUTILITY_CER << "\ndelete (*iter)\n";
   #endif
  } 
  iter++;
 }
 
}

void STRINGUTILITY :: addPair (STRINGUTILITY_STR strFind, STRINGUTILITY_STR strReplace)
{
 // add a pair of strings to the vector
 #ifdef DEBUG_BUILD
 STRINGUTILITY_CER << "\nSTRINGUTILITY addPair called with params:\n\t1."
      << strFind 
      << "\n\t2. " 
      << strReplace << "\n";
 #endif
 m_vkReplace.push_back ( new STRINGUTILITY_REPLACE (strFind, strReplace) );
 
}

void STRINGUTILITY :: clear ()
{
 #ifdef DEBUG_BUILD
 STRINGUTILITY_CER << "\nSTRINGUTILITY clear called\n";
 #endif
 // clear the vector
 STRINGUTILITY_VEC <STRINGUTILITY_REPLACE*> :: iterator iter = m_vkReplace.begin ();
 while ( iter < m_vkReplace.end () )
 {
  if ( (*iter) )
  {
   delete (*iter);
   #ifdef DEBUG_BUILD
   STRINGUTILITY_CER << "\ndelete (*iter)\n";
   #endif
  } 
  iter++;
 }
 m_vkReplace.clear ();
}

STRINGUTILITY_STR STRINGUTILITY :: replace (STRINGUTILITY_STR strSource)
{
 #ifdef DEBUG_BUILD
 STRINGUTILITY_CER << "\nSTRINGUTILITY replace called on string:\n" << strSource << "\n";
 #endif
 // set our final string to the source string
 STRINGUTILITY_STR strFinal = strSource;
 
 // get an iterator to the pairs vector
 STRINGUTILITY_VEC <STRINGUTILITY_REPLACE*> :: iterator iter = m_vkReplace.begin ();
 
 #ifdef DEBUG_BUILD
 STRINGUTILITY_CER << "replacing " << m_vkReplace.size () << " pairs" << endl;
 #endif
 
 // we're on pass one (used in debugging)
 int iPass = 1;
 
 // while there are still pairs to find and replace in the vector
 while (iter < m_vkReplace.end ())
 {
 
  #ifdef DEBUG_BUILD
  STRINGUTILITY_CER << "pass #" << iPass << endl;
  #endif
  
  // find first occurence
  size_t iFound = strFinal.find ((*iter)->m_strFind);
    
  #ifdef DEBUG_BUILD
  if (iFound != string::npos)
  {
   STRINGUTILITY_CER << "found occurrence of " << (*iter)->m_strFind << " at " << int(iFound) << endl;
  } 
  #endif
  
  // while theres still occurences to replace 
  while ( iFound != string::npos )
  {
   // replace
   strFinal.replace(iFound, (*iter)->m_strFind.length (), (*iter)->m_strReplace);
   
   // find next
   iFound = strFinal.find ((*iter)->m_strFind, iFound + 1);
      
   #ifdef DEBUG_BUILD
   if (iFound != string::npos)
   {
    STRINGUTILITY_CER << "found occurrence of " << (*iter)->m_strFind << " at " << int(iFound) << endl;
   } 
   #endif
    
  } // end replace all occurences
  
  // next pair
  iter++;
  
  // next pass
  iPass++;
 }
 
 // return our final string
 return strFinal; 
}

