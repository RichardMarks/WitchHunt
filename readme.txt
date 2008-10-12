WiTCHHUNT, The Dawn of the Blood. 
(C) Copyright 2007, CCPS Solutions
http://www.ccpssolutions.com/witchhunt


What is included in this archive?

All the C++ source code that went into the game is included here for your enjoyment.

It should compile under Dev-C++ version 4.9.8.7

It will not compile under Microsoft Visual C++

You must have Windows XP or higher. 
Sorry, linux users will have a very hard time compiling this.
If you compile this on linux, then LET US KNOW ABOUT IT!

Most of the game content files have been removed.


To compile this monstrosity you will need to create a new console application in Dev-C++
and then add the source & include files to the project.

However, you need to know that not ALL the source files (.cpp) are COMPILED.
We used some dirty #include tricks to speed up the build time.

The .cpp files you HAVE to compile are:

COMMON.cpp
CTIMER.cpp
KEYDRIVER.cpp
STRINGUTILITY.cpp
ABILITY.cpp
BATTLE.cpp
ITEM.cpp
HACK_TheTriggers.cpp
HACK_TheItems.cpp
HACK_TheAbilities.cpp
HACK_TheWORLDMAPCode.cpp
HACK_TheENTITYCode.cpp
HACK_TheGameCode.cpp
ingameMenuSystem.cpp

Compile Flags:

-D NODEBUG_BUILD  
-D NOMAP_TESTER  
-D NOALLOW_DEBUG_PAUSE 
-D NOSHOW_RANDOM_VALUES_BEFORE_RETURN    
-pg 
-g3


Compiling any other .cpp files will result in errors.
This is because of the dirty tricks I told you about.

This source is provided under the GNU GPL license terms.
Read license.txt included with the source for details.

Thank you.
-Richard Marks
CEO, CCPS Solutions
