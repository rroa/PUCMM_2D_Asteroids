#pragma once
#ifndef BULLET_HPP
#define BULLET_HPP

#include "Entity.hpp"

namespace Asteroids
{
	class Bullet : public Entity
	{
	public:
		Bullet					( );
		void ApplyImpulse		( Engine::Vector2 impulse ) override;
		void Update				( float deltaTime, int worldWidth, int worldHeight );
		void Render				( ) override;
	private:
		float					m_lifespan;
		float					m_currentLifespan;
	};
}

#endif // !BULLET_HPP