
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
// displayCredits.cpp
////////////////////////////////////////////////////////////////////////////////

// include the project header
//#include "project.h"

void displayCredits ()
{
 Common :: clearscreen ();
char* creditsscreen_data [] = {
"��������������������������������������������������������������������������������",
"��������������������������                             �������������������������",
"��������������������������     W i T C H  H U N T      �������������������������",
"��������������������������                             �������������������������",
"��������������������������������������������������������������������������������",
"������                                                                     �����",
"������  Story and Design - Richard Marks, Rafael Hermosillo, Jeff Stagg    �����",
"������                                                                     �����",
"������  Artwork          - Richard Marks                                   �����",
"������                                                                     �����",
"������  Programming      - Richard Marks, Rafael Hermosillo                �����",
"������                                                                     �����",
"������  �      �������������������������������������������������������     �����",
"������ �����  �     ��    ��   ��� � �������    ��    ��   ���    ���� � � �����",
"������������ ���� ��� ����� ��� � � � ����� ����� ����� ��� � ���������� � �����",
"�������������� �� ���     �     � � � ����� ����� �����    ���   ���������������",
"����������������� ��� ����� ��� � � � ����� ����� ����� ��������� ��������������",
"����������������� ����    � ��� � � � ������    ��    � �����    ���������������",
"��������������������������������������������������������������������������������",
"������������������� w w w . c c p s s o l u t i o n s . c o m ������������������"
};

 for (int row = 0; row < sizeof (creditsscreen_data)/sizeof(char*); row++)
 {
  cout << creditsscreen_data [row];
 }
 cout << endl;

 Common :: pause ("");
}

