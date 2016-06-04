#pragma once
#ifndef BULLET_HPP
#define BULLET_HPP

#include "Entity.hpp"

namespace Asteroids
{
	class Bullet : public Entity
	{
	public:
		/* =============================================================
		* PUBLIC FUNCTIONS
		* ============================================================= */
		Bullet					( );
		void ApplyImpulse		( Engine::Vector2 impulse ) override;
		void Update				( float deltaTime, int worldWidth, int worldHeight );
		void Render				( ) override;
	private:
		/* =============================================================
		* MEMBERS
		* ============================================================= */
		float					m_currentLifespan;
		float					m_lifespan;
	};
}

#endif // !BULLET_HPP
