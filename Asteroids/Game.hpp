#pragma once
#ifndef GAME_HPP
#define GAME_HPP

#include "App.hpp"
#include "Scene.hpp"
#include "Vector3.hpp"

namespace Asteroids
{
	class Game : public Engine::Scene
	{
	public:
		Game(Engine::App* app, Engine::Vector3 background);
	};
}

#endif // !GAME_HPP