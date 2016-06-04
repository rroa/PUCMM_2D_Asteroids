#pragma once
#ifndef  ENTITY_HPP
#define ENTITY_HPP

#include "Vector2.hpp"

namespace Asteroids
{
	class Entity
	{
	public:
		/* =============================================================
		* ENUMERATORS
		* ============================================================= */
		struct EntityState
		{
			enum State
			{
				NORMAL = 0,
				COLLIDED = 1,
				DELETED = 2,
			};
		};

		/* =============================================================
		* PUBLIC FUNCTIONS
		* ============================================================= */
		Entity						( );
		virtual ~Entity				( );
		virtual void ApplyImpulse	( Engine::Vector2 impulse ) = 0;
		virtual void Update			( float deltaTime, int worldWidth, int worldHeight );
		virtual void Render			( ) = 0;
		void Teleport				( float newX, float newY );
		bool DetectCollision		( Entity* entity );
		inline bool CouldCollide    ( ) { return m_state == EntityState::State::NORMAL; }
		inline bool IsDisappearing  ( ) { return m_state == EntityState::State::DELETED;  }
		inline bool IsColliding		( ) { return m_state == EntityState::State::COLLIDED; }
		inline float GetX			( ) { return m_position.x; }
		inline float GetY			( ) { return m_position.y; }
	protected:
		/* =============================================================
		* MEMBERS
		* ============================================================= */
		Engine::Vector2				m_position;
		Engine::Vector2				m_velocity;
		float						m_mass;
		EntityState::State			m_state;
		float						m_radius;
	};
}

#endif // ! ENTITY_HPP
