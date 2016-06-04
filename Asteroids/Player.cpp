#define _USE_MATH_DEFINES

#include "Player.hpp"
#include <SDL2/SDL_opengl.h>
#include <cmath>

namespace Asteroids
{
	const float DRAG_FORCE = 0.999f;
	const float ANGLE_OFFSET = 90.f;
	const float BULLET_SPEED = 250.f;

	Player::Player()
		: m_angle(0.0f)
		, m_rotation(250)
		, m_currentShip(-1)
	{
		// Set model render vertices (default ship)
		//
		ChangeShip();
	}

	void Player::ApplyDrag()
	{
		m_velocity.x *= DRAG_FORCE;
		m_velocity.y *= DRAG_FORCE;
	}

	void Player::ApplyImpulse(Engine::Vector2 impulse)
	{
		if (m_mass > 0)
		{
			m_velocity.x += (impulse.x / m_mass) * cosf((m_angle + ANGLE_OFFSET) * (M_PI / 180));
			m_velocity.y += (impulse.y / m_mass) * sinf((m_angle + ANGLE_OFFSET) * (M_PI / 180));
		}
	}	

	void Player::MoveUp()
	{
		ApplyImpulse(Engine::Vector2(m_thrust, m_thrust));
	}

	void Player::RotateRight(float deltaTime)
	{
		m_angle -= m_rotation * (deltaTime);
	}

	void Player::RotateLeft(float deltaTime)
	{
		m_angle += m_rotation * (deltaTime);
	}

	void Player::ChangeShip()
	{
		m_currentShip = ++m_currentShip % 3;
		m_points.clear();

		switch (m_currentShip)
		{
		case 1:
			// Millennium Falcon
			//
			m_mass = 1.0f;
			m_radius = 44.0f;
			m_thrust = 4.0f;
			m_max_velocity = 466.67;

			m_points.push_back(Engine::Vector2(0.0f, 20.0f));
			m_points.push_back(Engine::Vector2(4.0f, 20.0f));
			m_points.push_back(Engine::Vector2(4.0f, 44.0f));
			m_points.push_back(Engine::Vector2(10.0f, 44.0f));
			m_points.push_back(Engine::Vector2(12.0f, 40.0f));
			m_points.push_back(Engine::Vector2(16.0f, 32.0f));
			m_points.push_back(Engine::Vector2(20.0f, 24.0f));
			m_points.push_back(Engine::Vector2(20.0f, 20.0f));
			m_points.push_back(Engine::Vector2(22.0f, 24.0f));
			m_points.push_back(Engine::Vector2(24.0f, 28.0f));
			m_points.push_back(Engine::Vector2(28.0f, 28.0f));
			m_points.push_back(Engine::Vector2(28.0f, 12.0f));
			m_points.push_back(Engine::Vector2(24.0f, 12.0f));
			m_points.push_back(Engine::Vector2(28.0f, 4.0f));
			m_points.push_back(Engine::Vector2(28.0f, -8.0f));
			m_points.push_back(Engine::Vector2(24.0f, -16.0f));
			m_points.push_back(Engine::Vector2(20.0f, -20.0f));
			m_points.push_back(Engine::Vector2(20.0f, -24.0f));
			m_points.push_back(Engine::Vector2(12.0f, -28.0f));
			m_points.push_back(Engine::Vector2(4.0f, -32.0f));
			m_points.push_back(Engine::Vector2(-4.0f, -32.0f));
			m_points.push_back(Engine::Vector2(-12.0f, -28.0f));
			m_points.push_back(Engine::Vector2(-20.0f, -24.0f));
			m_points.push_back(Engine::Vector2(-20.0f, -20.0f));
			m_points.push_back(Engine::Vector2(-24.0f, -16.0f));
			m_points.push_back(Engine::Vector2(-28.0f, -8.0f));
			m_points.push_back(Engine::Vector2(-28.0f, 4.0f));
			m_points.push_back(Engine::Vector2(-24.0f, 12.0f));
			m_points.push_back(Engine::Vector2(-20.0f, 20.0f));
			m_points.push_back(Engine::Vector2(-20.0f, 24.0f));
			m_points.push_back(Engine::Vector2(-16.0f, 32.0f));
			m_points.push_back(Engine::Vector2(-12.0f, 40.0f));
			m_points.push_back(Engine::Vector2(-10.0f, 44.0f));
			m_points.push_back(Engine::Vector2(-4.0f, 44.0f));
			m_points.push_back(Engine::Vector2(-4.0f, 20.0f));
			break;
		case 2:
			// USS Enterprise
			//
			m_mass = 2.0f;
			m_radius = 40.0f;
			m_thrust = 2.0f;
			m_max_velocity = 233.33;

			m_points.push_back(Engine::Vector2(0.0f, 40.0f));
			m_points.push_back(Engine::Vector2(8.0f, 40.0f));
			m_points.push_back(Engine::Vector2(12.0f, 36.0f));
			m_points.push_back(Engine::Vector2(20.0f, 28.0f));
			m_points.push_back(Engine::Vector2(22.0f, 24.0f));
			m_points.push_back(Engine::Vector2(24.0f, 20.0f));
			m_points.push_back(Engine::Vector2(24.0f, 16.0f));
			m_points.push_back(Engine::Vector2(20.0f, 8.0f));
			m_points.push_back(Engine::Vector2(16.0f, 0.0f));
			m_points.push_back(Engine::Vector2(12.0f, -4.0f));
			m_points.push_back(Engine::Vector2(12.0f, -12.0f));
			m_points.push_back(Engine::Vector2(18.0f, -16.0f));
			m_points.push_back(Engine::Vector2(18.0f, -4.0f));
			m_points.push_back(Engine::Vector2(24.0f, -4.0f));
			m_points.push_back(Engine::Vector2(24.0f, -40.0f));
			m_points.push_back(Engine::Vector2(18.0f, -40.0f));
			m_points.push_back(Engine::Vector2(18.0f, -24.0f));
			m_points.push_back(Engine::Vector2(12.0f, -20.0f));
			m_points.push_back(Engine::Vector2(4.0f, -14.0f));
			m_points.push_back(Engine::Vector2(-4.0f, -14.0f));
			m_points.push_back(Engine::Vector2(-12.0f, -20.0f));
			m_points.push_back(Engine::Vector2(-18.0f, -24.0f));
			m_points.push_back(Engine::Vector2(-18.0f, -40.0f));
			m_points.push_back(Engine::Vector2(-24.0f, -40.0f));
			m_points.push_back(Engine::Vector2(-24.0f, -4.0f));
			m_points.push_back(Engine::Vector2(-18.0f, -4.0f));
			m_points.push_back(Engine::Vector2(-18.0f, -16.0f));
			m_points.push_back(Engine::Vector2(-12.0f, -12.0f));
			m_points.push_back(Engine::Vector2(-12.0f, -4.0f));
			m_points.push_back(Engine::Vector2(-16.0f, 0.0f));
			m_points.push_back(Engine::Vector2(-20.0f, 8.0f));
			m_points.push_back(Engine::Vector2(-24.0f, 16.0f));
			m_points.push_back(Engine::Vector2(-24.0f, 20.0f));
			m_points.push_back(Engine::Vector2(-22.0f, 24.0f));
			m_points.push_back(Engine::Vector2(-20.0f, 28.0f));
			m_points.push_back(Engine::Vector2(-12.0f, 36.0f));
			m_points.push_back(Engine::Vector2(-8.0f, 40.0f));
			break;
		default:
			// Original
			//
			m_mass = 0.5f;
			m_radius = 20.0f;
			m_thrust = 3.0f;
			m_max_velocity = 350.0f;

			m_points.push_back(Engine::Vector2(0.0f, 20.0f));
			m_points.push_back(Engine::Vector2(12.0f, -10.0f));
			m_points.push_back(Engine::Vector2(6.0f, -4.0f));
			m_points.push_back(Engine::Vector2(-6.0f, -4.0f));
			m_points.push_back(Engine::Vector2(-12.0f, -10.0f));
			break;
		}
	}

	void Player::Update(float deltaTime, int worldWidth, int worldHeight)
	{
		float speed = 
			fabs(sqrtf(m_velocity.x * m_velocity.x + m_velocity.y * m_velocity.y));

		if (speed > m_max_velocity)
		{
			m_velocity.x = (m_velocity.x / speed) * m_max_velocity;
			m_velocity.y = (m_velocity.y / speed) * m_max_velocity;
		}

		m_currentSpeed = speed;

		ApplyDrag();

		Entity::Update(deltaTime, worldWidth, worldHeight);
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

	Asteroids::Bullet* Player::Shoot()
	{
		float shootingAngle = m_angle + ANGLE_OFFSET;
		float bulletX = m_points[1].x * cosf(shootingAngle * (M_PI / 180 ));
		float bulletY = m_points[1].y * sinf(shootingAngle * (M_PI / 180 ));

		float vx = (m_currentSpeed + BULLET_SPEED) * cosf(shootingAngle * (M_PI / 180));
		float vy = (m_currentSpeed + BULLET_SPEED) * sinf(shootingAngle * (M_PI / 180));

		Bullet* bullet = new Bullet();

		bullet->Teleport(m_position.x + bulletX, m_position.y + bulletY);
		bullet->ApplyImpulse(Engine::Vector2(vx, vy));

		return bullet;
	}
}