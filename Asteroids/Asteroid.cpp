#include "Asteroid.hpp"

#include <SDL2/SDL_opengl.h>
#include <cmath>

namespace Asteroids
{
	const size_t NUM_POINTS = 16;
	const float MIN_SIZE = 25.0f;
	const float MAX_SIZE = 45.0f;

	// TODO: RR: Move this to an utility class
	//
	const float PI = 3.141592653f;

	Asteroid::Asteroid(AsteroidSize::Size size)
		: m_size(size)
		, m_angle(0.0f)
		, m_rotation(120)
	{
		m_sizeFactor = (int)size + 1;

		// Calculating the MIN/MAX size of the asteroid based on the size enum value
		//
		float min = MIN_SIZE / m_sizeFactor;
		float max = MAX_SIZE / m_sizeFactor;

		//type = ASTEROID_PLAYERTYPE;

		for (size_t i = 0; i < NUM_POINTS; ++i)
		{
			const float radians = (i / (float)NUM_POINTS) * 2.0f * PI;
			// TODO: RR: Move this to a rand in range function
			const float randDist = min + (max - min) * (rand() / (float)RAND_MAX);

			m_points.push_back(Engine::Vector2(std::sinf(radians) * randDist, std::cosf(radians) * randDist));
		}

		m_radius = (min + max) * 0.5f;
	}

	void Asteroid::Update(float deltaTime, int worldWidth, int worldHeight)
	{
		// Rotate the asteroid.
		//
		m_angle += m_rotation * deltaTime;

		Entity::Update(deltaTime, worldWidth, worldHeight);
	}

	void Asteroid::ApplyImpulse(Engine::Vector2 impulse)
	{
		if (m_mass > 0)
		{
			m_velocity.x += (impulse.x / m_mass) * cosf(m_rotation * (PI / 180)) + m_sizeFactor;
			m_velocity.y += (impulse.y / m_mass) * sinf(m_rotation * (PI / 180)) + m_sizeFactor;
		}
	}

	Asteroid::AsteroidSize::Size Asteroid::GetSize()
	{
		return m_size;
	}

	void Asteroid::Render()
	{
		glLoadIdentity();
		glTranslatef(m_position.x, m_position.y, 0.0f);
		glRotatef(m_angle, 0.0f, 0.0f, 1.0f);

		glBegin(GL_LINE_LOOP);

		std::vector<Engine::Vector2>::iterator it = m_points.begin();
		for (; it != m_points.end(); ++it)
		{
			glVertex2f((*it).x, (*it).y);
		}

		glEnd();

		glLoadIdentity();
		DrawCircle(m_position.x, m_position.y, m_radius, 16);
	}

	void Asteroid::DrawCircle(float cx, float cy, float r, int num_segments)
	{
		float theta = 2 * 3.1415926 / float(num_segments);
		float tangetial_factor = tanf(theta);//calculate the tangential factor 

		float radial_factor = cosf(theta);//calculate the radial factor 

		float x = r;//we start at angle = 0 

		float y = 0;

		glBegin(GL_LINE_LOOP);
		for (int ii = 0; ii < num_segments; ii++)
		{
			glVertex2f(x + cx, y + cy);//output vertex 

									   //calculate the tangential vector 
									   //remember, the radial vector is (x, y) 
									   //to get the tangential vector we flip those coordinates and negate one of them 

			float tx = -y;
			float ty = x;

			//add the tangential vector 

			x += tx * tangetial_factor;
			y += ty * tangetial_factor;

			//correct using the radial factor 

			x *= radial_factor;
			y *= radial_factor;
		}
		glEnd();
	}
}