#include "Player.hpp"
#include <SDL2/SDL_opengl.h>
#include <cmath>

namespace Asteroids
{
	const float DRAG_FORCE = 0.999f;
	const float MAX_VELOCITY = 0.2f;
	const float THRUST = 0.05f;
	const float PI = 3.141592653f;

	Player::Player()
		: m_angle(90.0f)
		, m_rotation(0.5)
	{
		// Set model render vertices
		//
		m_points.push_back(Engine::Vector2(20.0f, 0.0f));
		m_points.push_back(Engine::Vector2(-10.0f, -12.0f));
		m_points.push_back(Engine::Vector2(-4.0f, -6.0f));
		m_points.push_back(Engine::Vector2(-4.0f, 6.0f));
		m_points.push_back(Engine::Vector2(-10.0f, 12.0f));
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
			float cos = cosf(m_angle * (PI / 180));
			float sin = sinf(m_angle * (PI / 180));

			m_velocity.x += (impulse.x / m_mass) * cos;
			m_velocity.y += (impulse.y / m_mass) * sin;
		}
	}

	void Player::MoveDown()
	{
		ApplyImpulse(Engine::Vector2(-THRUST, (m_angle == 0 ? 0 : -THRUST)));
	}

	void Player::MoveLeft()
	{
		ApplyImpulse(Engine::Vector2((m_angle == 0 ? 0 : -THRUST), -THRUST));
	}
	void Player::MoveRight()
	{
		ApplyImpulse(Engine::Vector2((m_angle == 0 ? 0 : THRUST), THRUST));
	}

	void Player::MoveUp()
	{
		ApplyImpulse(Engine::Vector2(THRUST, (m_angle == 0 ? 0 : THRUST)));
	}

	void Player::RotateRight(float deltaTime)
	{
		m_angle -= m_rotation * (deltaTime);
	}

	void Player::RotateLeft(float deltaTime)
	{
		m_angle += m_rotation * (deltaTime);
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
		for (; it != m_points.end(); ++it)
		{
			glVertex2f((*it).x, (*it).y);
		}

		glEnd();
	}
}