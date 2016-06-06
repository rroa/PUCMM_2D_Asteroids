#include "GameObject.hpp"

// STL
#include <algorithm>

// 
#include "Component.hpp"

namespace Engine
{ 
	GameObject::GameObject()
	{}

	GameObject::~GameObject()
	{
		// Delete all attached components
		//
		while (!m_components.empty()) delete m_components.back(), m_components.pop_back();

		// Delete all attached children
		//
		while (!m_children.empty()) delete m_children.back(), m_children.pop_back();
	}
	
	void GameObject::AttachComponent(Component* component)
	{
		component->SetOwner(this);
		m_components.push_back(component);
	}

	void GameObject::RemoveComponent(Component* component)
	{
		m_components.erase(
			std::remove(m_components.begin(), m_components.end(), component), m_components.end()
		);

		delete component;
	}

	void GameObject::AddChild(GameObject* child)
	{
		m_children.push_back(child);
	}

	void GameObject::RemoveChild(GameObject* child)
	{
		m_children.erase(
			std::remove(m_children.begin(), m_children.end(), child), m_children.end()
		);

		delete child;
	}

	void GameObject::Update(float deltaTime)
	{
		// Update components
		//
		std::vector< Component* >::iterator comp = m_components.begin();
		for (;comp != m_components.end(); ++comp)
		{
			(*comp)->Update(deltaTime);
		}

		// Update children
		//
		std::vector< GameObject* >::iterator child = m_children.begin();
		for (; child != m_children.end(); ++child)
		{
			(*child)->Update(deltaTime);
		}

		// Base class function call
		//
		IUpdate::Update(deltaTime);
	}

	void GameObject::Render()
	{
		// Render children
		//
		std::vector< GameObject* >::iterator child = m_children.begin();
		for (; child != m_children.end(); ++child)
		{
			(*child)->Render();
		}
	}
}