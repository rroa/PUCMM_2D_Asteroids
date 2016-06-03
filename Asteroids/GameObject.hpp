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
		void AttachComponent						( Component* );
		void RemoveComponent						( Component* );
		void Update									( float deltaTime );

		/* =============================================================
		* INLINE FUNCTIONS
		* ============================================================= */
		inline std::vector<Component*>GetComponents	( ) { return m_components; }
	protected:
		/* =============================================================
		* MEMBERS
		* ============================================================= */
		std::vector<Component*>						m_components;
		Scene*										m_scene;
	};
}

#endif // !COMPONENT_HPP