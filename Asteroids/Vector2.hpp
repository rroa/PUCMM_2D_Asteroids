#pragma once

#ifndef VECTOR2_HPP
#define VECTOR2_HPP

namespace Engine
{
	class Vector2
	{
	public:
		// operators
		Vector2& operator=(const Vector2& rhs);
		Vector2& operator+=(const Vector2& rhs);
		Vector2& operator-=(const Vector2& rhs);
		Vector2& operator*=(const Vector2& rhs);
		Vector2& operator/=(const Vector2& rhs);
		Vector2 operator+(const Vector2& rhs);
		Vector2 operator-(const Vector2& rhs);
		Vector2 operator-();
		Vector2 operator*(const Vector2& rhs);
		Vector2 operator/(const Vector2& rhs);
		bool operator==(const Vector2& rhs);
		bool operator!=(const Vector2& rhs);
		friend Vector2 operator*(float scaleUnit, const Vector2& rhs);
		friend Vector2 operator*(const Vector2& lhs, float scaleUnit);

		explicit Vector2();
		explicit Vector2(float x, float y);
		float x;
		float y;
	};
}
 
#endif // !VECTOR2_HPP
