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
		float halfHeight = (worldHeight / 2.0f);

		m_position.x = worldWidth / 2.0f;
		m_position.y = -(halfHeight - (worldHeight * (m_height_percent / 2.0f)));
	}

	void Panel::Render()
	{
		glLoadIdentity();

		glColor3f(255.0f, 255.0f, 255.0f);

		glBegin(GL_LINE_LOOP);

		glVertex2f(-m_position.x, m_position.y);
		glVertex2f(m_position.x, m_position.y);

		glEnd();


		/*glLoadIdentity();

		glBegin(GL_LINE_LOOP);

		glVertex2f(-m_position.x + 10, m_position.y - 9);
		glVertex2f(-m_position.x + 12, m_position.y - 7);
		glVertex2f(-m_position.x + 12, m_position.y - 25);

		glEnd();*/
	}
}