//
//	*main.cpp
//
//	KaissouDev | Eat-the-Mushroom 
//	(c) 2023
//

#include "main.hpp"
#include "game.hpp"


#include <iostream>

#ifdef WIN32
	#include <Windows.h>
	int wWinMain(HINSTANCE hInst, HINSTANCE hPreInst, LPWSTR nCmdLine, int nCmdShow)
#endif
#ifndef WIN32
	int main(int argc, char **argv)
#endif

{	
	Game game;

	game.RunGame();
    return 0;
}
