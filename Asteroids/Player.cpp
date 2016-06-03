#include "Player.hpp"
#include <SDL2/SDL_opengl.h>
#include <cmath>

namespace Asteroids
{
	const float DRAG_FORCE = 0.999f;
	const float MAX_VELOCITY = 350.0f;
	const float THRUST = 3.0f;
	const float ANGLE_OFFSET = 90.f;
	const float PI = 3.141592653f;

	/*
	 * const float DRAG_FORCE = 0.999f;
     * const float MAX_VELOCITY = 350.0f;
     * const float THRUST = 3.0f;
     * const float ANGLE_OFFSET = 90.f;
     * const float BULLET_SPEED = 250.f;
	 */

	Player::Player()
		: m_angle(0.0f)
		, m_rotation(250)
		, m_currentShip(-1)
	{
		m_mass = 0.5f;
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
			m_velocity.x += (impulse.x / m_mass) * cosf((m_angle + ANGLE_OFFSET) * (PI / 180));
			m_velocity.y += (impulse.y / m_mass) * sinf((m_angle + ANGLE_OFFSET) * (PI / 180));
		}
	}	

	void Player::MoveUp()
	{
		ApplyImpulse(Engine::Vector2(THRUST, THRUST));
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
			m_points.push_back(Engine::Vector2(0.0f, 46.0f));
			m_points.push_back(Engine::Vector2(6.0f, 46.0f));
			m_points.push_back(Engine::Vector2(6.0f, 2.0f));
			m_points.push_back(Engine::Vector2(8.0f, 2.0f));
			m_points.push_back(Engine::Vector2(8.0f, 46.0f));
			m_points.push_back(Engine::Vector2(6.0f, 50.0f));
			m_points.push_back(Engine::Vector2(6.0f, 62.0f));
			m_points.push_back(Engine::Vector2(8.0f, 64.0f));
			m_points.push_back(Engine::Vector2(8.0f, 70.0f));
			m_points.push_back(Engine::Vector2(12.0f, 70.0f));
			m_points.push_back(Engine::Vector2(34.0f, 24.0f));
			m_points.push_back(Engine::Vector2(36.0f, 18.0f));
			m_points.push_back(Engine::Vector2(14.0f, 2.0f));
			m_points.push_back(Engine::Vector2(16.0f, 0.0f));
			m_points.push_back(Engine::Vector2(38.0f, 16.0f));
			m_points.push_back(Engine::Vector2(38.0f, 24.0f));
			m_points.push_back(Engine::Vector2(41.0f, 32.0f));
			m_points.push_back(Engine::Vector2(48.0f, 32.0f));
			m_points.push_back(Engine::Vector2(52.0f, 24.0f));
			m_points.push_back(Engine::Vector2(52.0f, 10.0f));
			m_points.push_back(Engine::Vector2(46.0f, 6.0f));
			m_points.push_back(Engine::Vector2(48.0f, 2.0f));
			m_points.push_back(Engine::Vector2(50.0f, -2.0f));
			m_points.push_back(Engine::Vector2(50.0f, -6.0f));
			m_points.push_back(Engine::Vector2(44.0f, -10.0f));
			m_points.push_back(Engine::Vector2(16.0f, -10.0f));
			m_points.push_back(Engine::Vector2(14.0f, -6.0f));
			m_points.push_back(Engine::Vector2(10.0f, -2.0f));
			m_points.push_back(Engine::Vector2(8.0f, -4.0f));
			m_points.push_back(Engine::Vector2(12.0f, -8.0f));
			m_points.push_back(Engine::Vector2(14.0f, -12.0f));
			m_points.push_back(Engine::Vector2(44.0f, -12.0f));
			m_points.push_back(Engine::Vector2(50.0f, -14.0f));
			m_points.push_back(Engine::Vector2(50.0f, -18.0f));
			m_points.push_back(Engine::Vector2(44.0f, -22.0f));
			m_points.push_back(Engine::Vector2(14.0f, -22.0f));
			m_points.push_back(Engine::Vector2(10.0f, -26.0f));
			m_points.push_back(Engine::Vector2(6.0f, -28.0f));
			m_points.push_back(Engine::Vector2(8.0f, -30.0f));
			m_points.push_back(Engine::Vector2(12.0f, -28.0f));
			m_points.push_back(Engine::Vector2(16.0f, -24.0f));
			m_points.push_back(Engine::Vector2(44.0f, -24.0f));
			m_points.push_back(Engine::Vector2(52.0f, -28.0f));
			m_points.push_back(Engine::Vector2(50.0f, -34.0f));
			m_points.push_back(Engine::Vector2(43.0f, -42.0f));
			m_points.push_back(Engine::Vector2(38.0f, -54.0f));
			m_points.push_back(Engine::Vector2(36.0f, -50.0f));
			m_points.push_back(Engine::Vector2(18.0f, -34.0f));
			m_points.push_back(Engine::Vector2(16.0f, -36.0f));
			m_points.push_back(Engine::Vector2(34.0f, -52.0f));
			m_points.push_back(Engine::Vector2(34.0f, -58.0f));
			m_points.push_back(Engine::Vector2(30.0f, -62.0f));
			m_points.push_back(Engine::Vector2(24.0f, -66.0f));
			m_points.push_back(Engine::Vector2(12.0f, -70.0f));
			m_points.push_back(Engine::Vector2(0.0f, -72.0f));
			m_points.push_back(Engine::Vector2(-12.0f, -70.0f));
			m_points.push_back(Engine::Vector2(-24.0f, -66.0f));
			m_points.push_back(Engine::Vector2(-30.0f, -62.0f));
			m_points.push_back(Engine::Vector2(-34.0f, -58.0f));
			m_points.push_back(Engine::Vector2(-34.0f, -52.0f));
			m_points.push_back(Engine::Vector2(-16.0f, -36.0f));
			m_points.push_back(Engine::Vector2(-18.0f, -34.0f));
			m_points.push_back(Engine::Vector2(-36.0f, -50.0f));
			m_points.push_back(Engine::Vector2(-38.0f, -54.0f));
			m_points.push_back(Engine::Vector2(-43.0f, -42.0f));
			m_points.push_back(Engine::Vector2(-50.0f, -34.0f));
			m_points.push_back(Engine::Vector2(-52.0f, -28.0f));
			m_points.push_back(Engine::Vector2(-44.0f, -24.0f));
			m_points.push_back(Engine::Vector2(-16.0f, -24.0f));
			m_points.push_back(Engine::Vector2(-12.0f, -28.0f));
			m_points.push_back(Engine::Vector2(-8.0f, -30.0f));
			m_points.push_back(Engine::Vector2(-6.0f, -28.0f));
			m_points.push_back(Engine::Vector2(-10.0f, -26.0f));
			m_points.push_back(Engine::Vector2(-14.0f, -22.0f));
			m_points.push_back(Engine::Vector2(-44.0f, -22.0f));
			m_points.push_back(Engine::Vector2(-50.0f, -18.0f));
			m_points.push_back(Engine::Vector2(-50.0f, -14.0f));
			m_points.push_back(Engine::Vector2(-44.0f, -12.0f));
			m_points.push_back(Engine::Vector2(-14.0f, -12.0f));
			m_points.push_back(Engine::Vector2(-12.0f, -8.0f));
			m_points.push_back(Engine::Vector2(-8.0f, -4.0f));
			m_points.push_back(Engine::Vector2(-10.0f, -2.0f));
			m_points.push_back(Engine::Vector2(-14.0f, -6.0f));
			m_points.push_back(Engine::Vector2(-16.0f, -10.0f));
			m_points.push_back(Engine::Vector2(-44.0f, -10.0f));
			m_points.push_back(Engine::Vector2(-50.0f, -6.0f));
			m_points.push_back(Engine::Vector2(-50.0f, -2.0f));
			m_points.push_back(Engine::Vector2(-48.0f, 2.0f));
			m_points.push_back(Engine::Vector2(-46.0f, 6.0f));
			m_points.push_back(Engine::Vector2(-38.0f, 16.0f));
			m_points.push_back(Engine::Vector2(-16.0f, 0.0f));
			m_points.push_back(Engine::Vector2(-14.0f, 2.0f));
			m_points.push_back(Engine::Vector2(-36.0f, 18.0f));
			m_points.push_back(Engine::Vector2(-34.0f, 24.0f));
			m_points.push_back(Engine::Vector2(-12.0f, 70.0f));
			m_points.push_back(Engine::Vector2(-8.0f, 70.0f));
			m_points.push_back(Engine::Vector2(-8.0f, 64.0f));
			m_points.push_back(Engine::Vector2(-6.0f, 62.0f));
			m_points.push_back(Engine::Vector2(-6.0f, 50.0f));
			m_points.push_back(Engine::Vector2(-8.0f, 46.0f));
			m_points.push_back(Engine::Vector2(-8.0f, 2.0f));
			m_points.push_back(Engine::Vector2(-6.0f, 2.0f));
			m_points.push_back(Engine::Vector2(-6.0f, 46.0f));
			break;
		case 2:
			// USS Enterprise
			//
			m_points.push_back(Engine::Vector2(0.0f, 70.0f));
			m_points.push_back(Engine::Vector2(10.0f, 68.0f));
			m_points.push_back(Engine::Vector2(18.0f, 62.0f));
			m_points.push_back(Engine::Vector2(26.0f, 46.0f));
			m_points.push_back(Engine::Vector2(24.0f, 36.0f));
			m_points.push_back(Engine::Vector2(18.0f, 26.0f));
			m_points.push_back(Engine::Vector2(18.0f, 32.0f));
			m_points.push_back(Engine::Vector2(16.0f, 32.0f));
			m_points.push_back(Engine::Vector2(16.0f, 20.0f));
			m_points.push_back(Engine::Vector2(10.0f, 18.0f));
			m_points.push_back(Engine::Vector2(10.0f, 26.0f));
			m_points.push_back(Engine::Vector2(8.0f, 26.0f));
			m_points.push_back(Engine::Vector2(8.0f, 42.0f));
			m_points.push_back(Engine::Vector2(8.0f, 44.0f));
			m_points.push_back(Engine::Vector2(6.0f, 46.0f));
			m_points.push_back(Engine::Vector2(4.0f, 48.0f));
			m_points.push_back(Engine::Vector2(4.0f, 46.0f));
			m_points.push_back(Engine::Vector2(6.0f, 44.0f));
			m_points.push_back(Engine::Vector2(6.0f, 42.0f));
			m_points.push_back(Engine::Vector2(6.0f, 20.0f));
			m_points.push_back(Engine::Vector2(8.0f, 20.0f));
			m_points.push_back(Engine::Vector2(10.0f, 14.0f));
			m_points.push_back(Engine::Vector2(8.0f, 4.0f));
			m_points.push_back(Engine::Vector2(8.0f, -6.0f));
			m_points.push_back(Engine::Vector2(4.0f, -6.0f));
			m_points.push_back(Engine::Vector2(4.0f, -8.0f));
			m_points.push_back(Engine::Vector2(14.0f, -8.0f));
			m_points.push_back(Engine::Vector2(14.0f, 4.0f));
			m_points.push_back(Engine::Vector2(18.0f, 8.0f));
			m_points.push_back(Engine::Vector2(22.0f, 4.0f));
			m_points.push_back(Engine::Vector2(22.0f, -46.0f));
			m_points.push_back(Engine::Vector2(18.0f, -68.0f));
			m_points.push_back(Engine::Vector2(14.0f, -46.0f));
			m_points.push_back(Engine::Vector2(14.0f, -14.0f));
			m_points.push_back(Engine::Vector2(4.0f, -14.0f));
			m_points.push_back(Engine::Vector2(4.0f, -16.0f));
			m_points.push_back(Engine::Vector2(8.0f, -16.0f));
			m_points.push_back(Engine::Vector2(6.0f, -28.0f));
			m_points.push_back(Engine::Vector2(0.0f, -40.0f));
			m_points.push_back(Engine::Vector2(-6.0f, -28.0f));
			m_points.push_back(Engine::Vector2(-8.0f, -16.0f));
			m_points.push_back(Engine::Vector2(-4.0f, -16.0f));
			m_points.push_back(Engine::Vector2(-4.0f, -14.0f));
			m_points.push_back(Engine::Vector2(-14.0f, -14.0f));
			m_points.push_back(Engine::Vector2(-14.0f, -46.0f));
			m_points.push_back(Engine::Vector2(-18.0f, -68.0f));
			m_points.push_back(Engine::Vector2(-22.0f, -46.0f));
			m_points.push_back(Engine::Vector2(-22.0f, 4.0f));
			m_points.push_back(Engine::Vector2(-18.0f, 8.0f));
			m_points.push_back(Engine::Vector2(-14.0f, 4.0f));
			m_points.push_back(Engine::Vector2(-14.0f, -8.0f));
			m_points.push_back(Engine::Vector2(-4.0f, -8.0f));
			m_points.push_back(Engine::Vector2(-4.0f, -6.0f));
			m_points.push_back(Engine::Vector2(-8.0f, -6.0f));
			m_points.push_back(Engine::Vector2(-8.0f, 4.0f));
			m_points.push_back(Engine::Vector2(-10.0f, 14.0f));
			m_points.push_back(Engine::Vector2(-8.0f, 20.0f));
			m_points.push_back(Engine::Vector2(-6.0f, 20.0f));
			m_points.push_back(Engine::Vector2(-6.0f, 42.0f));
			m_points.push_back(Engine::Vector2(-6.0f, 44.0f));
			m_points.push_back(Engine::Vector2(-4.0f, 46.0f));
			m_points.push_back(Engine::Vector2(-4.0f, 48.0f));
			m_points.push_back(Engine::Vector2(-6.0f, 46.0f));
			m_points.push_back(Engine::Vector2(-8.0f, 44.0f));
			m_points.push_back(Engine::Vector2(-8.0f, 42.0f));
			m_points.push_back(Engine::Vector2(-8.0f, 26.0f));
			m_points.push_back(Engine::Vector2(-10.0f, 26.0f));
			m_points.push_back(Engine::Vector2(-10.0f, 18.0f));
			m_points.push_back(Engine::Vector2(-16.0f, 20.0f));
			m_points.push_back(Engine::Vector2(-16.0f, 32.0f));
			m_points.push_back(Engine::Vector2(-18.0f, 32.0f));
			m_points.push_back(Engine::Vector2(-18.0f, 26.0f));
			m_points.push_back(Engine::Vector2(-24.0f, 36.0f));
			m_points.push_back(Engine::Vector2(-26.0f, 46.0f));
			m_points.push_back(Engine::Vector2(-18.0f, 62.0f));
			m_points.push_back(Engine::Vector2(-10.0f, 68.0f));
			break;
		default:
			// Original
			//
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

		if (speed > MAX_VELOCITY)
		{
			m_velocity.x = (m_velocity.x / speed) * MAX_VELOCITY;
			m_velocity.y = (m_velocity.y / speed) * MAX_VELOCITY;
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
}