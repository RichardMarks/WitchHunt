
// main.cpp

// WitchHunt Remake 2008
// (C) Copyright 2008, CCPS Solutions
// http://www.ccpssolutions.com

#include "Game.h"

int main(int argc, char* argv[])
{
	Game* game = new Game();
	game->Initialize(argc, argv);
	int result = game->Execute();
	delete game;
	return result;
}

