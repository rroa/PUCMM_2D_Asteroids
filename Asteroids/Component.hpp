#pragma once
#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <string>

//
#include "IUpdate.h"

namespace Engine
{
	class GameObject;
	class Component : IUpdate
	{
	public:
		/* =============================================================
		* PUBLIC FUNCTIONS
		* ============================================================= */
		Component						(const std::string& name );
		~Component						( );
		void virtual Update 			( float deltaTime );

		/* =============================================================
		* INLINE FUNCTIONS
		* ============================================================= */
		inline void SetOwner			( GameObject* owner ) { m_owner = owner; }
		inline GameObject* GetOwner		( ) { return m_owner; }
		inline std::string GetName		( ) { return m_name; }
	protected:
		/* =============================================================
		* MEMBERS
		* ============================================================= */
		GameObject*						m_owner;
		std::string						m_name;
	};
}


#endif // !COMPONENT_HPP