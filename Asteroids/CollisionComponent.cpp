#include "CollisionComponent.hpp"

namespace Engine
{ 
	const std::string COMP_NAME = "COLLISION_COMPONENT";

	CollisionComponent::CollisionComponent()
		: Component(COMP_NAME)
	{}

	CollisionComponent::~CollisionComponent()
	{}
}