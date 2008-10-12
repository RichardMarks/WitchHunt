
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

void startBattle (int iEnemies, ...)
{
 va_list vaList;
 va_start(vaList, iEnemies);
 vector <ENTITY*> vpkBattleParty;

 for (int nArg = 0; nArg < iEnemies; nArg++)
 {
  const char* szEnemyName = va_arg(vaList, const char*);

  ENTITY* pkEnemy = new ENTITY ();
  std :: string strEnemyName = szEnemyName;
  pkEnemy->loadTemplate ( strEnemyName );
  pkEnemy->buildGrowthTable ();
  vpkBattleParty.push_back (pkEnemy);
 } 

 va_end(vaList);

 INITIATE_BATTLE (rkHero, vpkBattleParty);

 vector <ENTITY*> :: iterator iter;
 for (iter = vpkBattleParty.begin(); iter != vpkBattleParty.end(); ++iter)
 {
  if ( (*iter) )
  {
   delete (*iter);
   (*iter) = NULL; 
  } 
 }

}
