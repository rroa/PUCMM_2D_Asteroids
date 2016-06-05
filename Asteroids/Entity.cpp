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

	Entity::Entity(float heightPercent)
		: m_mass(1.0f)
		, m_state(EntityState::State::NORMAL)
		, m_height_percent(heightPercent)
	{}

	void Entity::Update(float deltaTime, int worldWidth, int worldHeight)
	{
		m_position.x += m_velocity.x * static_cast<float>(deltaTime);
		m_position.y += m_velocity.y * static_cast<float>(deltaTime);

		float halfWidth = (worldWidth / 2.0f);
		float halfHeight = (worldHeight / 2.0f);

		float worldMinX = -halfWidth;
		float worldMaxX = halfWidth;

		float worldMinY = -((worldHeight * m_height_percent) - halfHeight);
		float worldMaxY = halfHeight;

		m_position.x = wrap(m_position.x, worldMinX, worldMaxX);
		m_position.y = wrap(m_position.y, worldMinY, worldMaxY);
	}

	void Entity::Teleport(float newX, float newY)
	{
		m_position.x = newX;
		m_position.y = newY;
	}

	bool Entity::DetectCollision(Entity* entity)
	{
		// TODO: RR: Move this to a library
		// Calculating squared distance
		float radii = (m_radius + entity->m_radius);

		float xdiff = m_position.x - entity->m_position.x;
		float ydiff = m_position.y - entity->m_position.y;

		float squaredDistance = (xdiff * xdiff) + (ydiff * ydiff);

		// Checking for collision
		bool collision = (radii * radii) >= squaredDistance;

		// Setting the actors state
		if (collision)
		{
			m_state = EntityState::State::COLLIDED;
			entity->m_state = EntityState::State::COLLIDED;
		}

		return collision;
	}
}