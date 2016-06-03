#pragma once
#ifndef PLAYER_HPP
#define PLAYER_HPP

// STL
#include <vector>

// Asteroids
#include "Vector2.hpp"
#include "Entity.hpp"
#include "Bullet.hpp"

namespace Asteroids
{
	class Player : public Entity
	{
	public:
		/* =============================================================
		* PUBLIC FUNCTIONS
		* ============================================================= */
		Player							( );
		void Update						( float deltaTime, int worldWidth, int worldHeight );
		void Render						( );

		//
		void ApplyImpulse				( Engine::Vector2 impulse ) override;
		void ApplyDrag					( );
		void MoveUp						( );
		void RotateRight				( float deltaTime );
		void RotateLeft					( float deltaTime );
		void ChangeShip					( );
		Asteroids::Bullet* Shoot();
	private:
		/* =============================================================
		* MEMBERS
		* ============================================================= */
		std::vector<Engine::Vector2>    m_points;
		float							m_angle;
		float							m_rotation;
		float							m_currentSpeed;
		int							    m_currentShip;
	};
}

#endif // !PLAYER_HPP