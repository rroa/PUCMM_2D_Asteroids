#pragma once
#ifndef WORLD_HPP
#define WORLD_HPP

#include "GameObject.hpp"

namespace Asteroids
{
	class World : public Engine::GameObject
	{
	public:
		World(int width, int height);
	private:
		int m_width;
		int m_height;
	};
}

#endif // !WORLD_HPP