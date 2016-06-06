#if _MSC_VER && _DEBUG
	#define _CRTDBG_MAP_ALLOC
	#include <crtdbg.h>
#endif

// C++ STL
#include <cassert>
#include <iostream>

// 
#include "App.hpp"
#include "GameObject.hpp"
#include "Component.hpp"
#include "RigidBodyComponent.h"
#include "CollisionComponent.hpp"
#include "TransformationComponent.hpp"

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
	Engine::App* app = new Engine::App("Asteroids!", WIDTH, HEIGHT);

	// Initialize game
	//
	if(!app->OnInit())
	{
		std::cout << "Game Init error!\n";
		return -1;
	}

	// Execute game
	//
	app->OnExecute();

	// Delete game object
	//
	delete app;

	/*Engine::GameObject* go = new Engine::GameObject();
	Engine::PhysicsComponent* pc = new Engine::PhysicsComponent();
	Engine::CollisionComponent* cc = new Engine::CollisionComponent();
	Engine::TransformationComponent* tc = new Engine::TransformationComponent();

	go->AttachComponent(pc);
	go->AttachComponent(cc);
	go->AttachComponent(tc);

	Engine::PhysicsComponent* rt = go->GetComponent<Engine::PhysicsComponent>();
	assert(rt);
	if (rt)
	{
		std::cout << rt->GetName() << std::endl;
		std::cout << rt->GetMass() << std::endl;
	}

	std::cin.get();*/

	//delete go;



	return 0;
}