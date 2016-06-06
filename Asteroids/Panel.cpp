#include "Panel.hpp"
#include <SDL2/SDL_opengl.h>

namespace Asteroids
{
	Panel::Panel(float heightPercent) : Entity(heightPercent)
	{
		m_velocity.x = 0;
		m_velocity.y = 0;
	}

	void Panel::ApplyImpulse(Engine::Vector2 impulse)
	{
	}

	void Panel::Update(float deltaTime, int worldWidth, int worldHeight)
	{
	}

	void Panel::Update(float deltaTime, int worldWidth, int worldHeight, int lives)
	{
		float halfHeight = (worldHeight / 2.0f);

		m_position.x = worldWidth / 2.0f;
		m_position.y = -(halfHeight - (worldHeight * (m_height_percent / 2.0f)));
		m_lives = lives;
	}

	void Panel::DrawLine()
	{
		glLoadIdentity();
		glColor3f(255.0f, 255.0f, 255.0f);

		glBegin(GL_LINE_LOOP);
		glVertex2f(-m_position.x, m_position.y);
		glVertex2f(m_position.x, m_position.y);
		glEnd();

	}

	void Panel::DrawLives()
	{
		int gap = 10;
		glColor3f(0.0f, 255.0f, 0.0f);

		for (int i = 0; i < m_lives; i++)
		{
			glLoadIdentity();
			glBegin(GL_TRIANGLES);
			glVertex2f(-m_position.x + 15 + (gap * i), m_position.y - 10);
			glVertex2f(-m_position.x + 20 + (gap * i), m_position.y - 20);
			glVertex2f(-m_position.x + 10 + (gap * i), m_position.y - 20);
			glEnd();
		}
	}

	void Panel::Render()
	{		
		DrawLine();
		DrawLives();
	}
}