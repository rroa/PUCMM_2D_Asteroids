#pragma once
#ifndef PLAYER_HPP
#define PLAYER_HPP

// STL
#include <vector>

// Asteroids
#include "Vector2.hpp"
#include "Entity.hpp"

namespace Asteroids
{
	class Player : public Entity
	{
	public:
		/* =============================================================
		* PUBLIC FUNCTIONS
		* ============================================================= */
		Player();
		void Update						( );
		void Render						( );
	private:
		/* =============================================================
		* MEMBERS
		* ============================================================= */
		std::vector<Engine::Vector2>    m_points;
		float							m_angle;
	};
}

#endif // !PLAYER_HPP