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

		float halfWidth = (worldWidth / 2.0f);
		float halfHeight = (worldHeight / 2.0f);

		float worldMinX = -halfWidth;
		float worldMaxX =  halfWidth;

		float worldMinY = -halfHeight;
		float worldMaxY =  halfHeight;

		m_position.x = wrap(m_position.x, worldMinX, worldMaxX);
		m_position.y = wrap(m_position.y, worldMinY, worldMaxY);
	}

	void Entity::Teleport(float newX, float newY)
	{
		m_position.x = newX;
		m_position.y = newY;
	}
}