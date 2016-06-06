#include "Game.hpp"

#include "World.hpp"

namespace Asteroids
{
	Game::Game(Engine::App* app, Engine::Vector3 background)
		: Engine::Scene(background)
	{
		this->AddGameObject(new World(app->GetWidth(), app->GetHeight()));
		app->SetCurrentScene(this);
	}
}