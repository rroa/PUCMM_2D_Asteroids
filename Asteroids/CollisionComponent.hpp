#pragma once
#ifndef COLLISION_COMPONENT_HPP
#define COLLISION_COMPONENT_HPP

#include "Component.hpp"

namespace Engine
{
	class CollisionComponent : public Component
	{
	public:
		CollisionComponent();
		~CollisionComponent();
	};
}

#endif // !COLLISION_COMPONENT_HPP