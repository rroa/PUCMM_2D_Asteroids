#pragma once
#ifndef TRANSFORMATION_COMPONENT_HPP
#define TRANSFORMATION_COMPONENT_HPP

#include "Vector2.hpp"
#include "Vector3.hpp"

#include "Component.hpp"

namespace Engine
{
	class TransformationComponent : public Component
	{
	public:
		/* =============================================================
		* PUBLIC FUNCTIONS
		* ============================================================= */
		TransformationComponent			( );
		~TransformationComponent		( );
		void Teleport					( float x, float y );
		void Teleport					( Vector2 newPosition );
		inline Vector2 GetPosition		( ) { return m_position; }
	protected:
		/* =============================================================
		* MEMBERS
		* ============================================================= */
		Vector2							m_position;
		Vector3							m_rotation;
		float							m_angle;
	};
}

#endif // !TRANSFORMATION_COMPONENT_HPP