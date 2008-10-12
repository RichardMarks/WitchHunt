
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



vector<std :: string> getFileList (std :: string strExtension, bool bDisplayExtension)
{
 vector <std :: string> vstr;
 
 // create temporary file
 char szFilename [128];
 sprintf (szFilename, "dir *.%s /b > savegame.txt", strExtension.c_str ());
 system (szFilename);

 ifstream is ("savegame.txt");
 if (is)
 {
  vstr.clear ();
  while (!is.eof ())
  {
   string strTemp;
   getline(is, strTemp);
   if (bDisplayExtension)
   {
    vstr.push_back (strTemp);
   }
   else
   {
    STRINGUTILITY* pKSU = new STRINGUTILITY();
    pKSU->addPair (strExtension, "");
    vstr.push_back (pKSU->replace (strTemp));
    pKSU->clear ();
    delete pKSU; 
   }
  }
  is.close ();
 }
 system ("del savegame.txt"); 
 return vstr;
}



