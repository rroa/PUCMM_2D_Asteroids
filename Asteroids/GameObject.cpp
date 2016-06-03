#include "GameObject.hpp"

// STL
#include <algorithm>

//s
#include "Component.hpp"

namespace Engine
{ 
	GameObject::GameObject()
	{}

	GameObject::~GameObject()
	{}
	
	void GameObject::AttachComponent(Component* component)
	{
		component->SetOwner(this);
		m_components.push_back(component);
	}

	void GameObject::RemoveComponent(Component*)
	{
		/*
		Maybe delete instance after?
		...
		vec.erase(std::remove(vec.begin(), vec.end(), 8), vec.end());
		*/
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

		// Base class function call
		//
		IUpdate::Update(deltaTime);
	}
}