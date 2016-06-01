#if _MSC_VER && _DEBUG
	#define _CRTDBG_MAP_ALLOC
	#include <crtdbg.h>
#endif

// C++ STL
#include <cassert>
#include <iostream>
#include <cstdlib>
#include <ctime>

// 
#include "Game.hpp"

const int WIDTH = 1136;
const int HEIGHT = 640;

int main(int argc, char* argv[])
{
#if _MSC_VER && _DEBUG
	// https://msdn.microsoft.com/en-us/library/x98tx3cf.aspx
	// This will help you detect leaks when using Visual C++
	// Uncomment this line to start getting reports!
	assert(_CrtCheckMemory());
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	// Create Game Object
	//
	Engine::Game* game = new Engine::Game("Asteroids!", WIDTH, HEIGHT);

	// Initialize game
	//
	if(!game->OnInit())
	{
		std::cout << "Game Init error!\n";
		return -1;
	}

	// Execute game
	//
	game->OnExecute();

	// Delete game object
	//
	delete game;

	return 0;
}