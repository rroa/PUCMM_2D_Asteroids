#include "Player.hpp"
#include <SDL2/SDL_opengl.h>
#include <cmath>

namespace Asteroids
{
	const float DRAG_FORCE = 0.999f;
	const float MAX_VELOCITY = 350.0f;
	const float THRUST = 3.0f;
	const float ANGLE_OFFSET = 90.f;
	const float BULLET_SPEED = 250.f;
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
		m_radius = 10.0f;

		// Set model render vertices (default ship)
		//
		RenderShip();
	}

	Player::~Player()
	{

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

	void Player::RenderShip()
	{
		m_currentShip++;
		m_currentShip = m_currentShip % 3;
		m_points.clear();

		switch (m_currentShip)
		{
		case 1:
			// Millennium Falcon
			m_points.push_back(Engine::Vector2(0.0f, 23.0f));
			m_points.push_back(Engine::Vector2(3.0f, 23.0f));
			m_points.push_back(Engine::Vector2(3.0f, 1.0f));
			m_points.push_back(Engine::Vector2(4.0f, 1.0f));
			m_points.push_back(Engine::Vector2(4.0f, 23.0f));
			m_points.push_back(Engine::Vector2(3.0f, 25.0f));
			m_points.push_back(Engine::Vector2(3.0f, 31.0f));
			m_points.push_back(Engine::Vector2(4.0f, 32.0f));
			m_points.push_back(Engine::Vector2(4.0f, 35.0f));
			m_points.push_back(Engine::Vector2(6.0f, 35.0f));
			m_points.push_back(Engine::Vector2(17.0f, 12.0f));
			m_points.push_back(Engine::Vector2(18.0f, 9.0f));
			m_points.push_back(Engine::Vector2(7.0f, 1.0f));
			m_points.push_back(Engine::Vector2(8.0f, 0.0f));
			m_points.push_back(Engine::Vector2(19.0f, 8.0f));
			m_points.push_back(Engine::Vector2(19.0f, 12.0f));
			m_points.push_back(Engine::Vector2(21.0f, 16.0f));
			m_points.push_back(Engine::Vector2(24.0f, 16.0f));
			m_points.push_back(Engine::Vector2(26.0f, 12.0f));
			m_points.push_back(Engine::Vector2(26.0f, 5.0f));
			m_points.push_back(Engine::Vector2(23.0f, 3.0f));
			m_points.push_back(Engine::Vector2(24.0f, 1.0f));
			m_points.push_back(Engine::Vector2(25.0f, -1.0f));
			m_points.push_back(Engine::Vector2(25.0f, -3.0f));
			m_points.push_back(Engine::Vector2(22.0f, -5.0f));
			m_points.push_back(Engine::Vector2(8.0f, -5.0f));
			m_points.push_back(Engine::Vector2(7.0f, -3.0f));
			m_points.push_back(Engine::Vector2(5.0f, -1.0f));
			m_points.push_back(Engine::Vector2(4.0f, -2.0f));
			m_points.push_back(Engine::Vector2(6.0f, -4.0f));
			m_points.push_back(Engine::Vector2(7.0f, -6.0f));
			m_points.push_back(Engine::Vector2(22.0f, -6.0f));
			m_points.push_back(Engine::Vector2(25.0f, -7.0f));
			m_points.push_back(Engine::Vector2(25.0f, -9.0f));
			m_points.push_back(Engine::Vector2(22.0f, -11.0f));
			m_points.push_back(Engine::Vector2(7.0f, -11.0f));
			m_points.push_back(Engine::Vector2(5.0f, -13.0f));
			m_points.push_back(Engine::Vector2(3.0f, -14.0f));
			m_points.push_back(Engine::Vector2(4.0f, -15.0f));
			m_points.push_back(Engine::Vector2(6.0f, -14.0f));
			m_points.push_back(Engine::Vector2(8.0f, -12.0f));
			m_points.push_back(Engine::Vector2(22.0f, -12.0f));
			m_points.push_back(Engine::Vector2(26.0f, -14.0f));
			m_points.push_back(Engine::Vector2(25.0f, -17.0f));
			m_points.push_back(Engine::Vector2(23.0f, -21.0f));
			m_points.push_back(Engine::Vector2(21.0f, -24.0f));
			m_points.push_back(Engine::Vector2(19.0f, -27.0f));
			m_points.push_back(Engine::Vector2(18.0f, -25.0f));
			m_points.push_back(Engine::Vector2(9.0f, -17.0f));
			m_points.push_back(Engine::Vector2(8.0f, -18.0f));
			m_points.push_back(Engine::Vector2(17.0f, -26.0f));
			m_points.push_back(Engine::Vector2(17.0f, -29.0f));
			m_points.push_back(Engine::Vector2(15.0f, -31.0f));
			m_points.push_back(Engine::Vector2(12.0f, -33.0f));
			m_points.push_back(Engine::Vector2(6.0f, -35.0f));
			m_points.push_back(Engine::Vector2(0.0f, -36.0f));
			m_points.push_back(Engine::Vector2(-6.0f, -35.0f));
			m_points.push_back(Engine::Vector2(-12.0f, -33.0f));
			m_points.push_back(Engine::Vector2(-15.0f, -31.0f));
			m_points.push_back(Engine::Vector2(-17.0f, -29.0f));
			m_points.push_back(Engine::Vector2(-17.0f, -26.0f));
			m_points.push_back(Engine::Vector2(-8.0f, -18.0f));
			m_points.push_back(Engine::Vector2(-9.0f, -17.0f));
			m_points.push_back(Engine::Vector2(-18.0f, -25.0f));
			m_points.push_back(Engine::Vector2(-19.0f, -27.0f));
			m_points.push_back(Engine::Vector2(-21.0f, -24.0f));
			m_points.push_back(Engine::Vector2(-23.0f, -21.0f));
			m_points.push_back(Engine::Vector2(-25.0f, -17.0f));
			m_points.push_back(Engine::Vector2(-26.0f, -14.0f));
			m_points.push_back(Engine::Vector2(-22.0f, -12.0f));
			m_points.push_back(Engine::Vector2(-8.0f, -12.0f));
			m_points.push_back(Engine::Vector2(-6.0f, -14.0f));
			m_points.push_back(Engine::Vector2(-4.0f, -15.0f));
			m_points.push_back(Engine::Vector2(-3.0f, -14.0f));
			m_points.push_back(Engine::Vector2(-5.0f, -13.0f));
			m_points.push_back(Engine::Vector2(-7.0f, -11.0f));
			m_points.push_back(Engine::Vector2(-22.0f, -11.0f));
			m_points.push_back(Engine::Vector2(-25.0f, -9.0f));
			m_points.push_back(Engine::Vector2(-25.0f, -7.0f));
			m_points.push_back(Engine::Vector2(-22.0f, -6.0f));
			m_points.push_back(Engine::Vector2(-7.0f, -6.0f));
			m_points.push_back(Engine::Vector2(-6.0f, -4.0f));
			m_points.push_back(Engine::Vector2(-4.0f, -2.0f));
			m_points.push_back(Engine::Vector2(-5.0f, -1.0f));
			m_points.push_back(Engine::Vector2(-7.0f, -3.0f));
			m_points.push_back(Engine::Vector2(-8.0f, -5.0f));
			m_points.push_back(Engine::Vector2(-22.0f, -5.0f));
			m_points.push_back(Engine::Vector2(-25.0f, -3.0f));
			m_points.push_back(Engine::Vector2(-25.0f, -1.0f));
			m_points.push_back(Engine::Vector2(-24.0f, 1.0f));
			m_points.push_back(Engine::Vector2(-23.0f, 3.0f));
			m_points.push_back(Engine::Vector2(-19.0f, 8.0f));
			m_points.push_back(Engine::Vector2(-8.0f, 0.0f));
			m_points.push_back(Engine::Vector2(-7.0f, 1.0f));
			m_points.push_back(Engine::Vector2(-18.0f, 9.0f));
			m_points.push_back(Engine::Vector2(-17.0f, 12.0f));
			m_points.push_back(Engine::Vector2(-6.0f, 35.0f));
			m_points.push_back(Engine::Vector2(-4.0f, 35.0f));
			m_points.push_back(Engine::Vector2(-4.0f, 32.0f));
			m_points.push_back(Engine::Vector2(-3.0f, 31.0f));
			m_points.push_back(Engine::Vector2(-3.0f, 25.0f));
			m_points.push_back(Engine::Vector2(-4.0f, 23.0f));
			m_points.push_back(Engine::Vector2(-4.0f, 1.0f));
			m_points.push_back(Engine::Vector2(-3.0f, 1.0f));
			m_points.push_back(Engine::Vector2(-3.0f, 23.0f));
			break;
		case 2:
			// USS Enterprise

			m_points.push_back(Engine::Vector2(0.0f, 35.0f));
			m_points.push_back(Engine::Vector2(5.0f, 34.0f));
			m_points.push_back(Engine::Vector2(9.0f, 31.0f));
			m_points.push_back(Engine::Vector2(12.0f, 27.0f));
			m_points.push_back(Engine::Vector2(13.0f, 23.0f));
			m_points.push_back(Engine::Vector2(12.0f, 18.0f));
			m_points.push_back(Engine::Vector2(9.0f, 13.0f));
			m_points.push_back(Engine::Vector2(9.0f, 16.0f));
			m_points.push_back(Engine::Vector2(8.0f, 16.0f));
			m_points.push_back(Engine::Vector2(8.0f, 10.0f));
			m_points.push_back(Engine::Vector2(5.0f, 9.0f));
			m_points.push_back(Engine::Vector2(5.0f, 13.0f));
			m_points.push_back(Engine::Vector2(4.0f, 13.0f));
			m_points.push_back(Engine::Vector2(4.0f, 21.0f));
			m_points.push_back(Engine::Vector2(4.0f, 22.0f));
			m_points.push_back(Engine::Vector2(3.0f, 23.0f));
			m_points.push_back(Engine::Vector2(2.0f, 24.0f));
			m_points.push_back(Engine::Vector2(2.0f, 23.0f));
			m_points.push_back(Engine::Vector2(3.0f, 22.0f));
			m_points.push_back(Engine::Vector2(3.0f, 21.0f));
			m_points.push_back(Engine::Vector2(3.0f, 10.0f));
			m_points.push_back(Engine::Vector2(4.0f, 10.0f));
			m_points.push_back(Engine::Vector2(5.0f, 7.0f));
			m_points.push_back(Engine::Vector2(4.0f, 2.0f));
			m_points.push_back(Engine::Vector2(4.0f, -3.0f));
			m_points.push_back(Engine::Vector2(2.0f, -3.0f));
			m_points.push_back(Engine::Vector2(2.0f, -4.0f));
			m_points.push_back(Engine::Vector2(7.0f, -4.0f));
			m_points.push_back(Engine::Vector2(7.0f, 2.0f));
			m_points.push_back(Engine::Vector2(9.0f, 4.0f));
			m_points.push_back(Engine::Vector2(11.0f, 2.0f));
			m_points.push_back(Engine::Vector2(11.0f, -23.0f));
			m_points.push_back(Engine::Vector2(9.0f, -29.0f));
			m_points.push_back(Engine::Vector2(7.0f, -23.0f));
			m_points.push_back(Engine::Vector2(7.0f, -7.0f));
			m_points.push_back(Engine::Vector2(2.0f, -7.0f));
			m_points.push_back(Engine::Vector2(2.0f, -8.0f));
			m_points.push_back(Engine::Vector2(4.0f, -8.0f));
			m_points.push_back(Engine::Vector2(3.0f, -14.0f));
			m_points.push_back(Engine::Vector2(0.0f, -20.0f));
			m_points.push_back(Engine::Vector2(-3.0f, -14.0f));
			m_points.push_back(Engine::Vector2(-4.0f, -8.0f));
			m_points.push_back(Engine::Vector2(-2.0f, -8.0f));
			m_points.push_back(Engine::Vector2(-2.0f, -7.0f));
			m_points.push_back(Engine::Vector2(-7.0f, -7.0f));
			m_points.push_back(Engine::Vector2(-7.0f, -23.0f));
			m_points.push_back(Engine::Vector2(-9.0f, -29.0f));
			m_points.push_back(Engine::Vector2(-11.0f, -23.0f));
			m_points.push_back(Engine::Vector2(-11.0f, 2.0f));
			m_points.push_back(Engine::Vector2(-9.0f, 4.0f));
			m_points.push_back(Engine::Vector2(-7.0f, 2.0f));
			m_points.push_back(Engine::Vector2(-7.0f, -4.0f));
			m_points.push_back(Engine::Vector2(-2.0f, -4.0f));
			m_points.push_back(Engine::Vector2(-2.0f, -3.0f));
			m_points.push_back(Engine::Vector2(-4.0f, -3.0f));
			m_points.push_back(Engine::Vector2(-4.0f, 2.0f));
			m_points.push_back(Engine::Vector2(-5.0f, 7.0f));
			m_points.push_back(Engine::Vector2(-4.0f, 10.0f));
			m_points.push_back(Engine::Vector2(-3.0f, 10.0f));
			m_points.push_back(Engine::Vector2(-3.0f, 21.0f));
			m_points.push_back(Engine::Vector2(-3.0f, 22.0f));
			m_points.push_back(Engine::Vector2(-2.0f, 23.0f));
			m_points.push_back(Engine::Vector2(-2.0f, 24.0f));
			m_points.push_back(Engine::Vector2(-3.0f, 23.0f));
			m_points.push_back(Engine::Vector2(-4.0f, 22.0f));
			m_points.push_back(Engine::Vector2(-4.0f, 21.0f));
			m_points.push_back(Engine::Vector2(-4.0f, 13.0f));
			m_points.push_back(Engine::Vector2(-5.0f, 13.0f));
			m_points.push_back(Engine::Vector2(-5.0f, 9.0f));
			m_points.push_back(Engine::Vector2(-8.0f, 10.0f));
			m_points.push_back(Engine::Vector2(-8.0f, 16.0f));
			m_points.push_back(Engine::Vector2(-9.0f, 16.0f));
			m_points.push_back(Engine::Vector2(-9.0f, 13.0f));
			m_points.push_back(Engine::Vector2(-12.0f, 18.0f));
			m_points.push_back(Engine::Vector2(-13.0f, 23.0f));
			m_points.push_back(Engine::Vector2(-12.0f, 27.0f));
			m_points.push_back(Engine::Vector2(-9.0f, 31.0f));
			m_points.push_back(Engine::Vector2(-5.0f, 34.0f));
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

	Asteroids::Bullet* Player::Shoot()
	{
		float shootingAngle = m_angle + ANGLE_OFFSET;
		float bulletX = m_points[1].x * cosf(shootingAngle * ( PI / 180 ));
		float bulletY = m_points[1].y * sinf(shootingAngle * ( PI / 180 ));

		float vx = (m_currentSpeed + BULLET_SPEED) * cosf(shootingAngle * (PI / 180));
		float vy = (m_currentSpeed + BULLET_SPEED) * sinf(shootingAngle * (PI / 180));

		Bullet* bullet = new Bullet();

		bullet->Teleport(m_position.x + bulletX, m_position.y + bulletY);
		bullet->ApplyImpulse(Engine::Vector2(vx, vy));

		return bullet;
	}
}
