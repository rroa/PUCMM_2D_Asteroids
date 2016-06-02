#pragma once
#ifndef  ENTITY_HPP
#define ENTITY_HPP

#include "Vector2.hpp"

namespace Asteroids
{
	class Entity
	{
	public:
		Entity();
		virtual void ApplyImpulse	( Engine::Vector2 impulse ) = 0;
		virtual void Update			( float deltaTime, int worldWidth, int worldHeight );
		virtual void Render			( ) = 0;
		void Teleport(float newX, float newY);
	protected:
		Engine::Vector2				m_position;
		Engine::Vector2				m_velocity;
		float						m_mass;
	};
}

#endif // ! ENTITY_HPP