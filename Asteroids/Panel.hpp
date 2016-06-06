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
		void Update(float deltaTime, int worldWidth, int worldHeight, int lives);
		void Render() override;
	private:
		/* =============================================================
		* MEMBERS
		* ============================================================= */
		int									m_lives;
		void								DrawLives();
		void								DrawLine();
	};
}

#endif // !PANEL_HPP