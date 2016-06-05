#pragma once
#ifndef ASTEROID_HPP
#define ASTEROID_HPP

// STL
#include <vector>

// Asteroids
#include "Vector2.hpp"
#include "Entity.hpp"

namespace Asteroids
{
	class Asteroid : public Entity
	{
	public:
		/* =============================================================
		* ENUMERATORS
		* ============================================================= */
		struct AsteroidSize
		{
			enum Size
			{
				BIG = 0,
				MEDIUM = 1,
				SMALL = 2,
			};
		};

		/* =============================================================
		* PUBLIC FUNCTIONS
		* ============================================================= */
		Asteroid						( AsteroidSize::Size size, float heightPercent);
		void ApplyImpulse				( Engine::Vector2 impulse ) override;
		void Update						( float deltaTime, int worldWidth, int worldHeight );
		void Render						( ) override;
		AsteroidSize::Size GetSize		( );
	private:
		std::vector<Engine::Vector2>    m_points;
		AsteroidSize::Size				m_size;
		int								m_sizeFactor;
		float							m_angle;
		float							m_rotation;
	};
}

#endif // !ASTEROID_HPP