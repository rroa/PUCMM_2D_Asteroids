#pragma once
#ifndef SCENE_HPP
#define SCENE_HPP

#include "Vector3.hpp"

namespace Engine
{
	class Scene
	{
	public:
		Scene(Vector3 background);
	private:
		Vector3 m_background;
	};
}

#endif // !SCENE_HPP