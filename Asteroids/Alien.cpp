#include "Alien.hpp"

#include <SDL2\SDL_opengl.h>
#include <cmath>

namespace Asteroids
{
	const float PI = 3.141592653f;
	const float ANGLE_OFFSET = 0.f;

	Alien::Alien()
		: m_angle(0.0f),
		m_rotation(350)
	{
		m_mass = 1.0f;
		m_radius = 22.0f;
		m_position.x = -520;
		m_position.y = 70;

		m_points.push_back(Engine::Vector2(0, 0));
		m_points.push_back(Engine::Vector2(-13, 0));
		m_points.push_back(Engine::Vector2(-25, -10));
		m_points.push_back(Engine::Vector2(-30, 0));
		m_points.push_back(Engine::Vector2(-34, -5));
		m_points.push_back(Engine::Vector2(-34, 5));
		m_points.push_back(Engine::Vector2(-12, 30));
		m_points.push_back(Engine::Vector2(0, 30));
		m_points.push_back(Engine::Vector2(12, 30));
		m_points.push_back(Engine::Vector2(34, 5));
		m_points.push_back(Engine::Vector2(34, -5));
		m_points.push_back(Engine::Vector2(30, 0));
		m_points.push_back(Engine::Vector2(25, -10));
		m_points.push_back(Engine::Vector2(13, 0));
	}

	void Alien::ApplyImpulse(Engine::Vector2 impulse)
	{
		if (m_mass > 0)
		{
			m_velocity.x += (impulse.x / m_mass) * cosf(m_angle + ANGLE_OFFSET * (PI / 180));
			m_velocity.y += (impulse.y / m_mass) * sinf(m_angle + ANGLE_OFFSET * (PI / 180));
		}
	}

	void Alien::Update(float deltaTime, int worldWidth, int worldHeight, float player_x, float player_y)
	{
		// Chase the player	

		if (m_position.x >= player_x) 
		{ 
			m_position.x = m_position.x - 2; 
		} 
		if (m_position.x <= player_x) 
		{ 
			m_position.x = m_position.x + 1; 
		} 
		if (m_position.y <= player_y) 
		{ 
			m_position.y = m_position.y + 1; 
		} 
		if (m_position.y >= player_y) 
		{ 
			m_position.y = m_position.y - 1; 
		}
	}

	void Alien::Render()
	{
		glLoadIdentity();
		glTranslatef(m_position.x, m_position.y, 0.0f);
		glRotatef(m_angle, 0.0f, 0.0f, 1.0f);

		glColor3f(1.0f, 0, 0);

		glBegin(GL_LINE_LOOP);

		std::vector<Engine::Vector2>::iterator it = m_points.begin();
		for (; it != m_points.end(); ++it)
		{
			glVertex2f((*it).x, (*it).y);
		}

		glEnd();

		glColor3f(1.0f, 1.0f, 1.0f);
	}
}
