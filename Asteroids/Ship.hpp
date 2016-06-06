#pragma once
#ifndef SHIP_HPP
#define SHIP_HPP

#include "GameObject.hpp"

namespace Asteroids
{
	class Ship : public Engine::GameObject
	{
	public:
		Ship();
		void Render() override;
	};
}

#endif // !SHIP_HPP