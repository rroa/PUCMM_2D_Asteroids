#include "Alien.hpp"

#include <SDL2\SDL_opengl.h>
#include <cmath>

#include <iostream>

namespace Asteroids
{
	const float PI = 3.141592653f;
	const float ANGLE_OFFSET = 1.f;
	const float BULLET_SPEED = 150.f;

	Alien::Alien()
		: m_angle(1.0f),
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

	Asteroids::Bullet* Alien::Shoot(float player_x, float player_y)
	{
		float shootingAngle = m_angle + ANGLE_OFFSET;
		// std::cout << shootingAngle << " | " << m_angle << " | " << ANGLE_OFFSET << std::endl;
		// m_currentSpeed
		// shootingAngle
		float bulletX = m_points[0]. x * cosf(shootingAngle * (PI / 180));
		float bulletY = m_points[0].y * sinf(shootingAngle * (PI / 180));

		float vx = (250 + BULLET_SPEED) * cosf(player_x * (PI / 180));
		float vy = (250 + BULLET_SPEED) * sinf(player_y * (PI / 180));

		Bullet* bullet = new Bullet();

		bullet->Teleport(m_position.x + bulletX, m_position.y + bulletY);
		bullet->ApplyImpulse(Engine::Vector2(vx, vy));

		return bullet;
	}

	void Alien::ApplyImpulse(Engine::Vector2 impulse)
	{
		if (m_mass > 0)
		{
			m_velocity.x += (impulse.x / m_mass) * cosf(m_angle + ANGLE_OFFSET * (PI / 180));
			m_velocity.y += (impulse.y / m_mass) * sinf(m_angle + ANGLE_OFFSET * (PI / 180));
		}
	}

	float Alien::AimPlayerPosX(float player_x)
	{
		if (m_position.x >= player_x)
		{
			return m_position.x - 2;
		}
		if (m_position.x <= player_x)
		{
			return m_position.x + 1;
		}
	}

	float Alien::AimPlayerPosY(float player_y)
	{
		if (m_position.y <= player_y)
		{
			return m_position.y + 1;
		}
		if (m_position.y >= player_y)
		{
			return m_position.y - 2;
		}
	}

	void Alien::Update(float deltaTime, int worldWidth, int worldHeight, float player_x, float player_y)
	{
		m_position.x = AimPlayerPosX(player_x);
		m_position.y = AimPlayerPosY(player_y);
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
