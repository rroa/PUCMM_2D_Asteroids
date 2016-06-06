#pragma once
#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>

//
#include "Vector3.hpp"
#include "IUpdate.h"
#include "IRender.h"
#include "GameObject.hpp"

namespace Engine
{
	class Scene: public IUpdate, public IRender
	{
	public:
		/* =============================================================
		* PUBLIC FUNCTIONS
		* ============================================================= */
		Scene						( Vector3 background );
		void virtual Update			( float deltaTime );
		void virtual Render			( );
		void AddGameObject			( GameObject* go );
		void RemoveGameObject		( GameObject* go );
	private:
		/* =============================================================
		* MEMBERS
		* ============================================================= */
		Vector3						m_background;
		std::vector<GameObject*>	m_gameObjects;

	};
}

#endif // !SCENE_HPP