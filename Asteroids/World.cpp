#include "World.hpp"

#include "Ship.hpp"

namespace Asteroids
{
	World::World(int width, int height)
		: m_width(width)
		, m_height(height)
	{
		this->AddChild(new Ship());
	}
}