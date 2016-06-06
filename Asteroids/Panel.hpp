#pragma once
#ifndef PANEL_HPP
#define PANEL_HPP

#include "Entity.hpp"

namespace Asteroids
{
	class Panel : public Entity
	{
	public:
		/* =============================================================
		* PUBLIC FUNCTIONS
		* ============================================================= */
		Panel(float heightPercent);
		void ApplyImpulse(Engine::Vector2 impulse) override;
		void Update(float deltaTime, int worldWidth, int worldHeight) override;
		void Update(float deltaTime, int worldWidth, int worldHeight, int lives, int level);
		void Render() override;
	private:
		/* =============================================================
		* MEMBERS
		* ============================================================= */
		int									m_lives;
		int									m_level;
		int									m_worldHeight;
		int									m_initialLivePanelPoint;
		void								DrawLives();
		void								DrawLine();
		void								DrawLevel();
	};
}

#endif // !PANEL_HPP