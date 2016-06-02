#include "Entity.hpp"

namespace Asteroids
{
	inline float wrap(float x, float min, float max)
	{
		if (x < min)
		{
			return max - (min - x);
		}

		if (x > max)
		{
			return min + (x - max);
		}

		return x;
	}

	Entity::Entity()
		: m_mass(1.0f)
	{}

	void Entity::Update(float deltaTime, int worldWidth, int worldHeight)
	{
		m_position.x += m_velocity.x * static_cast<float>(deltaTime);
		m_position.y += m_velocity.y * static_cast<float>(deltaTime);

		float worldMinX = -(worldWidth / 2);
		float worldMaxX =  (worldWidth / 2);

		float worldMinY = -(worldHeight / 2);
		float worldMaxY =  (worldHeight / 2);

		m_position.x = wrap(m_position.x, worldMinX, worldMaxX);
		m_position.y = wrap(m_position.y, worldMinY, worldMaxY);
	}
}