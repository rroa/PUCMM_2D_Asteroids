#include "Bullet.hpp"
#include <SDL2/SDL_opengl.h>

namespace Asteroids
{
	Bullet::Bullet()
		: m_currentLifespan(0.f)
		, m_lifespan(120.f)
	{}

	void Bullet::ApplyImpulse(Engine::Vector2 impulse)
	{
		if (m_mass > 0)
		{
			m_velocity.x += (impulse.x / m_mass);
			m_velocity.y += (impulse.y / m_mass);
		}
	}

	void Bullet::Update(float deltaTime, int worldWidth, int worldHeight)
	{
		if (m_currentLifespan < m_lifespan)
		{
			m_currentLifespan++;
		}
		else
		{ 
			m_state = EntityState::State::DELETED;
		}

		Entity::Update(deltaTime, worldWidth, worldHeight);
	}

	void Bullet::Render()
	{
		glLoadIdentity();

		glPointSize(2.0f);

		glEnable(GL_POINT_SMOOTH);

		glBegin(GL_POINTS);

			glVertex2f(m_position.x, m_position.y);

		glEnd();
	}
}