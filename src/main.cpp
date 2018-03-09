#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include "CApplication.hpp"
#include "Tools/CRandom.hpp"

int main()
{
	//Seed du random
	CRandom::init();

	CApplication game;
	game.runMainLoop();	// Lancement du jeu

	return EXIT_SUCCESS;
}
