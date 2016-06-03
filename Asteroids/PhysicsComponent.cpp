#include "PhysicsComponent.h"

namespace Engine
{
	PhysicsComponent::PhysicsComponent()
		: Component("PHYSICS_COMPONENT")
		, m_gravity(1.0f)
		, m_mass(1.0f)
		, m_dragFactor(1.0f)
	{}

	PhysicsComponent::PhysicsComponent(float gravity, float mass, float dragFactor)
		: Component("PHYSICS_COMPONENT")
		, m_gravity(gravity)
		, m_mass(gravity)
		, m_dragFactor(dragFactor)
	{}

	PhysicsComponent::~PhysicsComponent()
	{}

	void PhysicsComponent::Update(float deltaTime)
	{


		// Base class function call
		//
		Component::Update(deltaTime);
	}
}