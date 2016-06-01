#pragma once

#ifndef VECTOR2_HPP
#define VECTOR2_HPP

namespace Engine
{
	class Vector2
	{
	public:
		explicit Vector2();
		explicit Vector2(float x, float y);
		float x;
		float y;
	};
}
 
#endif // !VECTOR2_HPP