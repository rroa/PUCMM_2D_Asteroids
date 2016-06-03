#pragma once
#ifndef PHYSICS_COMPONENT_HPP
#define PHYSICS_COMPONENT_HPP

#include "Component.hpp"
#include "Vector2.hpp"

namespace Engine
{
	class PhysicsComponent : public Component
	{
	public:
		/* =============================================================
		* PUBLIC FUNCTIONS
		* ============================================================= */
		PhysicsComponent			( );
		PhysicsComponent			( float gravity, float mass = 1.0f, float dragFactor = 1.0f );
		~PhysicsComponent			( );
		void Update					( float deltaTime );

		/* =============================================================
		* INLINE FUNCTIONS
		* ============================================================= */
		inline float GetMass		( ) { return m_mass; }
		inline Vector2 GetVelocity	( ) { return m_velocity; }
	protected:
		/* =============================================================
		* MEMBERS
		* ============================================================= */
		float						m_mass;
		float						m_dragFactor;
		float						m_gravity;
		Vector2						m_velocity;
	};
}

#endif // !PHYSICS_COMPONENT_HPP