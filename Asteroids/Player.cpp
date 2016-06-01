#include "Player.hpp"
#include <SDL2/SDL_opengl.h>

namespace Asteroids
{
	Player::Player()
		: m_angle(0.0f)
	{
		// Set model render vertices
		//
		m_points.push_back(Engine::Vector2(0.0f, 20.0f));
		m_points.push_back(Engine::Vector2(12.0f, -10.0f));
		m_points.push_back(Engine::Vector2(6.0f, -4.0f));
		m_points.push_back(Engine::Vector2(-6.0f, -4.0f));
		m_points.push_back(Engine::Vector2(-12.0f, -10.0f));
	}

	void Player::Update()
	{
	}

	void Player::Render()
	{
		glLoadIdentity();
		glTranslatef(m_position.x, m_position.y, 0.0f);
		glRotatef(m_angle, 0.0f, 0.0f, 1.0f);

		glBegin(GL_LINE_LOOP);
		
		std::vector<Engine::Vector2>::iterator it = m_points.begin();
		for ( ;it != m_points.end(); ++it)
		{
			glVertex2f((*it).x, (*it).y);
		}
		
		glEnd();
	}
}