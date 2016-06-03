#include "PhysicsComponent.h"

namespace Engine
{
	const std::string COMP_NAME = "PHYSICS_COMPONENT";
	PhysicsComponent::PhysicsComponent()
		: Component(COMP_NAME)
		, m_gravity(0.0f, 0.0f)
		, m_mass(1.0f)
		, m_dragFactor(1.0f)
	{}

	PhysicsComponent::PhysicsComponent(Vector2 gravity, float mass, float dragFactor)
		: Component(COMP_NAME)
		, m_gravity(gravity)
		, m_mass(mass)
		, m_dragFactor(dragFactor)
	{}

	PhysicsComponent::~PhysicsComponent()
	{}

	void PhysicsComponent::Update(float deltaTime)
	{
		m_velocity += m_gravity;

		// Base class function call
		//
		Component::Update(deltaTime);
	}
}