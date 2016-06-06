#include "Panel.hpp"
#include <SDL2/SDL_opengl.h>

namespace Asteroids
{
	Panel::Panel(float heightPercent) : Entity(heightPercent)
	{
		m_velocity.x = 0;
		m_velocity.y = 0;
		m_initialLivePanelPoint = 200;
	}

	void Panel::ApplyImpulse(Engine::Vector2 impulse)
	{
	}

	void Panel::Update(float deltaTime, int worldWidth, int worldHeight)
	{
	}

	void Panel::Update(float deltaTime, int worldWidth, int worldHeight, int lives, int level)
	{
		float halfHeight = (worldHeight / 2.0f);
		m_worldHeight = worldHeight;

		m_position.x = worldWidth / 2.0f;
		m_position.y = -(halfHeight - (worldHeight * (m_height_percent / 2.0f)));
		m_lives = lives;
		m_level = level;
	}

	void Panel::DrawLives()
	{
		int gap = 10;
		glColor3f(0.0f, 255.0f, 0.0f);

		for (int i = 0; i < m_lives; i++)
		{
			glLoadIdentity();
			glBegin(GL_TRIANGLES);
			glVertex2f(-m_position.x + 15 + (gap * i) + m_initialLivePanelPoint, m_position.y - 10);
			glVertex2f(-m_position.x + 20 + (gap * i) + m_initialLivePanelPoint, m_position.y - 20);
			glVertex2f(-m_position.x + 10 + (gap * i) + m_initialLivePanelPoint, m_position.y - 20);
			glEnd();
		}
	}

	void Panel::DrawLine()
	{
		glLoadIdentity();
		glColor3f(255.0f, 255.0f, 255.0f);

		glBegin(GL_LINE_LOOP);
		glVertex2f(-m_position.x, m_position.y);
		glVertex2f(m_position.x, m_position.y);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glVertex2f(-m_position.x + m_initialLivePanelPoint, m_position.y);
		glVertex2f(-m_position.x + m_initialLivePanelPoint, -m_worldHeight);
		glEnd();
	}

	void Panel::DrawLevel()
	{
		glLoadIdentity();
		glColor3f(255.0f, 255.0f, 255.0f);

		switch (m_level)
		{
		case 0:
			glBegin(GL_LINE_LOOP);
			glVertex2f(-m_position.x + 10.0, m_position.y - 15.0);
			glVertex2f(-m_position.x + 12.5, m_position.y - 12.5);
			glVertex2f(-m_position.x + 15.0, m_position.y - 10.0);
			glVertex2f(-m_position.x + 17.5, m_position.y - 12.5);
			glVertex2f(-m_position.x + 20.0, m_position.y - 15.0);
			glVertex2f(-m_position.x + 17.5, m_position.y - 17.5);
			glVertex2f(-m_position.x + 15.0, m_position.y - 20.0);
			glVertex2f(-m_position.x + 12.5, m_position.y - 17.5);
			break;
		case 1:
			glBegin(GL_LINE_STRIP);
			glVertex2f(-m_position.x + 10.0, m_position.y - 15.0);
			glVertex2f(-m_position.x + 15.0, m_position.y - 10.0);
			glVertex2f(-m_position.x + 15.0, m_position.y - 20.0);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		}

		glEnd();
	}

	void Panel::Render()
	{		
		DrawLine();
		DrawLives();
		DrawLevel();
	}
}