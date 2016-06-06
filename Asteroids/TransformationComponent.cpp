#include "TransformationComponent.hpp"

namespace Engine
{ 
	const std::string COMP_NAME = "TRANSFORMATION_COMPONENT";
	
	TransformationComponent::TransformationComponent()
		: Component(COMP_NAME)
	{}

	TransformationComponent::~TransformationComponent()
	{}

	void TransformationComponent::Teleport(float x, float y)
	{
		m_position.x = x;
		m_position.y = y;
	}

	void TransformationComponent::Teleport(Vector2 newPosition)
	{
		m_position = newPosition;
	}
}