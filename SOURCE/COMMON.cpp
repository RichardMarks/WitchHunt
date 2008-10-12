
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

#include "Common.h"

#include <ctime>

namespace Common
{

 void hr (void)
 {
  std :: cout << "============================================================" 
              << std :: endl;
 }

 std :: string input (std :: string strPrompt)
 {
  fflush (stdin);
  std :: string strReply;
  std :: cout << strPrompt;
  std :: getline (std :: cin, strReply);
  return strReply;
 }
 
 int cint (std :: string strValue)
 {
  return atoi (strValue.c_str ());
 }
 
 void pause (std :: string strPrompt)
 {
  fflush (stdin);
  std :: string strWait;
  std :: cout << strPrompt; 
  std :: getline(std :: cin, strWait);
 }
 
 void clearscreen (int x)
 { 
  system ("cls");   // windows
  
  for(int m = 0; m < x; m++)
  {
   std :: cout << std :: endl;
  }
  
  //system ("clear"); // linux
 }
 
 
 
 
 
 
 // returns an integer that has been mapped to a string
 // returns negative one on failure to find the string in the map
 int getmappedindex (common_association& caMap, std :: string strAlias)
 {
  common_association_iterator iter;
  if ( (iter = caMap.find (strAlias)) != caMap.end ())
   return iter->second;
  return -1;
 }
 
 void mapintoncamap (common_association& caMap, std :: string strAlias, int iIndex)
 {
  caMap [ strAlias ] = iIndex;
 } 
 
 void center (char* text)
 {
  int iLimit = 40 - (int(strlen(text)) / 2);
  for (int n = 1; n < iLimit; n++)
  {
   std :: cout << " "; 
  } 
  std :: cout << text;
 }


 void present (std :: string strText, int iDelay)
 {
  #if defined(DEBUG_BUILD)
   std :: cout << strText;
  #elif !defined(DEBUG_BUILD)
   int iTextLength = strText.size () - 1;
   long lDelayClocks = (CLOCKS_PER_SEC / iDelay);
   for (int ch = 0; ch < iTextLength; ch += 2)
   {
    std :: cout << strText.at(ch) << strText.at(ch + 1);
    clock_t CLWait = clock () + 1 * lDelayClocks;
    while (clock () < CLWait);
   }
  #endif
  
 }


 void dialogue (std :: string strSpeaker, std :: string strText, bool bMoreText, bool bClearScreen)
 {
  if (bClearScreen)
  {
   clearscreen (PRINT_VERTICAL_OFFSET);
  } 
  std :: cout << PRINT_OFFSET << strSpeaker << ":" << OFFSET_ENDL << OFFSET_ENDL;
  std :: cout << "\"";
  present (strText);
  std :: cout << "\"\n";
  if (bMoreText)
  {
   std :: cout << OFFSET_ENDL;
   pause ("(More)");
  } 
 }



 
 void DrawBoxTop (int width)
 {
  std :: cout << BoxTL;
  for (int n = 0; n < width - 2; n++)
   std :: cout << BoxTC;
  std :: cout << BoxTR;
 }

 void DrawBoxBottom (int width)
 {
  std :: cout << BoxBL;
  for (int n = 0; n < width - 2; n++)
   std :: cout << BoxBC;
  std :: cout << BoxBR;
 }



 int random (int vMin, int vMax)
 { 
  int vMod = vMax - vMin;
  if (vMod <= 0) vMod = 1;
  int vRet = vMin + rand () % vMod;
  #if defined(SHOW_RANDOM_VALUES_BEFORE_RETURN)
   std :: cerr << "DEBUG: Common :: random (" << vMin << ", " << vMax << ") = " << vRet << std :: endl;
   #if defined (ALLOW_DEBUG_PAUSE)
    Common :: pause("DEBUG: <PAUSED>");
   #endif
  #endif
  return (vRet == 0) ? 1 : vRet;
 }




};





