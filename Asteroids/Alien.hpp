#pragma once
#ifndef ALIEN_HPP
#define ALIEN_HPP

// STL
#include <vector>

// Asteroids
#include "Vector2.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "Bullet.hpp"

namespace Asteroids
{
	class Alien : public Entity
	{
	public:
		/* =============================================================
		* PUBLIC FUNCTIONS
		* ============================================================= */
		Alien();
		void Update							( float deltaTime, int worldWidth, 
											   int worldHeight, float player_x, float player_y);
		void Render							( );
		void ApplyImpulse					(Engine::Vector2 impulse);
		float AimPlayerPosX					( float player_x);
		float AimPlayerPosY					( float player_y);
		Asteroids::Bullet* Shoot			( float player_x, float player_y);
	private:
		/* =============================================================
		* MEMBERS
		* ============================================================= */
		std::vector<Engine::Vector2>        m_points;
		float								m_angle;
		float								m_rotation;
	};

}

#endif // !ALIEN_HPP