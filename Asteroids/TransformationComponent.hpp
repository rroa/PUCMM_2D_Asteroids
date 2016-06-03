#pragma once
#ifndef TRANSFORMATION_COMPONENT_HPP
#define TRANSFORMATION_COMPONENT_HPP

#include "Vector2.hpp"
#include "Vector3.hpp"

namespace Engine
{
	class TransformationComponent
	{
	public:
		TransformationComponent();
		~TransformationComponent();
	protected:
		Vector2 m_position;
		Vector3 m_rotation;
		float m_angle;
	};
}

#endif // !TRANSFORMATION_COMPONENT_HPP