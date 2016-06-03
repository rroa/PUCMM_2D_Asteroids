#include "TransformationComponent.hpp"

namespace Engine
{ 
	const std::string COMP_NAME = "TRANSFORMATION_COMPONENT";
	
	TransformationComponent::TransformationComponent()
		: Component(COMP_NAME)
	{}

	TransformationComponent::~TransformationComponent()
	{}
}