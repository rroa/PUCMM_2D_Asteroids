#pragma once
#ifndef PHYSICS_COMPONENT_HPP
#define PHYSICS_COMPONENT_HPP

#include "Component.hpp"
#include "Vector2.hpp"

namespace Engine
{
	class RigidBodyComponent : public Component
	{
	public:
		/* =============================================================
		* PUBLIC FUNCTIONS
		* ============================================================= */
		RigidBodyComponent			( );
		RigidBodyComponent			( Vector2 gravity, Vector2 position, float mass = 1.0f, float dragFactor = 1.0f );
		~RigidBodyComponent			( );
		void Update					( float deltaTime ) override;
		void AddForce				( Vector2 force );

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
		float						m_drag;
		Vector2						m_position;
		Vector2						m_force;
		Vector2						m_gravity;
		Vector2						m_velocity;
	};
}

#endif // !PHYSICS_COMPONENT_HPP