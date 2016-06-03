#pragma once
#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <vector>

//
#include "IUpdate.h"

namespace Engine
{
	class Component;
	class Scene;
	class GameObject : public IUpdate
	{
	public:
		/* =============================================================
		* PUBLIC FUNCTIONS
		* ============================================================= */
		GameObject									( );
		~GameObject									( );
		void AttachComponent						( Component*  );
		void RemoveComponent						( Component*  );
		void AddChild								( GameObject* );
		void RemoveChild							( GameObject* );
		void Update									( float deltaTime );

		/* =============================================================
		* INLINE FUNCTIONS
		* ============================================================= */
		inline std::vector<Component*>GetComponents	( ) { return m_components; }

		template<typename T>
		T* GetComponent()
		{
			std::vector< Component* >::iterator comp = m_components.begin();
			for (; comp != m_components.end(); ++comp)
			{
				T* theComponent = dynamic_cast<T*>(*comp);
				if (theComponent)
				{
					return theComponent;
				}
			}

			return nullptr;
		}
	protected:
		/* =============================================================
		* MEMBERS
		* ============================================================= */
		std::vector<Component*>						m_components;
		Scene*										m_scene;
		std::vector<GameObject*>					m_children;
	};
}

#endif // !COMPONENT_HPP