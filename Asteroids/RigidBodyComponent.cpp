#include "RigidBodyComponent.hpp"

namespace Engine
{
	const std::string COMP_NAME = "PHYSICS_COMPONENT";
	RigidBodyComponent::RigidBodyComponent()
		: Component(COMP_NAME)
		, m_gravity(0.0f, 0.0f)
		, m_position(0.0f, 0.f)
		, m_mass(1.0f)
		, m_drag(1.0f)
	{}

	RigidBodyComponent::RigidBodyComponent(Vector2 gravity, Vector2 position, float mass, float drag)
		: Component(COMP_NAME)
		, m_gravity(gravity)
		, m_mass(mass)
		, m_position(position)
		, m_drag(drag)
	{}

	RigidBodyComponent::~RigidBodyComponent()
	{}

	void RigidBodyComponent::AddForce( Vector2 force )
	{

	}

	void RigidBodyComponent::Update(float deltaTime)
	{
		m_velocity += m_gravity;

		// Base class function call
		//
		Component::Update(deltaTime);
	}
}