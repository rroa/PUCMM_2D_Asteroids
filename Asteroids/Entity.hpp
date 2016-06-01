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
		virtual void Update() = 0;
		virtual void Render() = 0;
	protected:
		Engine::Vector2 m_position;
		Engine::Vector2 m_velocity;
	};
}

#endif // ! ENTITY_HPP