#include "Vector2.hpp"

#include <cmath>

namespace Engine
{
	Vector2::Vector2()
		: x(0.0f)
		, y(0.0f)
	{}

	Vector2::Vector2(float _x, float _y)
		: x( _x )
		, y( _y )
	{}

	Vector2::Vector2(const Vector2& other)
		: x(other.x)
		, y(other.y)
		, length(other.length)
	{}

	float Vector2::Normalize()
	{
		// Calculating the length
		CalcLength();

		float inverseScale = 1.0f / length;
		x *= inverseScale;
		y *= inverseScale;

		return length;
	}

	float Vector2::CalcLength()
	{
		float lenSquared = x * x + y * y;
		if (lenSquared == 0)
		{
			length = 0.0f;
			return length;
		}

		length = std::sqrtf(lenSquared);

		return length;
	}

	float Vector2::CalcLengthSquared()
	{
		float lenSquared = x * x + y * y;
		if (lenSquared == 0) return 0.0f;

		return lenSquared;
	}

	void Vector2::Scale(float scaleUnit)
	{
		x *= scaleUnit;
		y *= scaleUnit;
	}

	float Vector2::SetLength(float newLength)
	{
		float oldLen = length;
		float lenSquared = x * x + y * y;
		if (lenSquared == 0) return 0.0f;

		// Calculating new length
		length = std::sqrtf(lenSquared);

		float inverseScale = newLength / length;
		x *= inverseScale;
		y *= inverseScale;

		return oldLen;
	}

	Vector2& Vector2::operator=(const Vector2& rhs)
	{
		// Prevent self assignment. Two objects
		// are equal if their memory address are equal.
		if (this == &rhs)
		{
			return *this;
		}

		this->x = rhs.x;
		this->y = rhs.y;

		return *this;
	}

	Vector2& Vector2::operator+=(const Vector2& rhs)
	{
		x = x + rhs.x;
		y = y + rhs.y;

		return *this;
	}

	Vector2& Vector2::operator-=(const Vector2& rhs)
	{
		x = x - rhs.x;
		y = y - rhs.y;

		return *this;
	}

	Vector2& Vector2::operator*=(const Vector2& rhs)
	{
		x = x * rhs.x;
		y = y * rhs.y;

		return *this;
	}

	Vector2& Vector2::operator/=(const Vector2& rhs)
	{
		x = x / rhs.x;
		y = y / rhs.y;

		return *this;
	}

	Vector2 Vector2::operator+(const Vector2& rhs)
	{
		Vector2 sum;

		sum.x = x + rhs.x;
		sum.y = y + rhs.y;

		return sum;
	}

	Vector2 Vector2::operator-(const Vector2& rhs)
	{
		Vector2 sub;
		sub.x = x - rhs.x;
		sub.y = y - rhs.y;

		return sub;
	}

	Vector2 Vector2::operator-()
	{
		return Vector2(-x, -y);
	}

	Vector2 Vector2::operator*(const Vector2& rhs)
	{
		Vector2 scaled;

		scaled.x = x * rhs.x;
		scaled.y = y * rhs.y;

		return scaled;
	}

	Vector2 Vector2::operator/(const Vector2& rhs)
	{
		Vector2 inverseScaled;

		inverseScaled.x = x / rhs.x;
		inverseScaled.y = y / rhs.y;

		return inverseScaled;
	}

	bool Vector2::operator==(const Vector2& rhs)
	{
		return
			x == rhs.x &&
			y == rhs.y;
	}

	bool Vector2::operator!=(const Vector2& rhs)
	{
		return
			x != rhs.x ||
			y != rhs.y;
	}

	// friend functions
	Vector2 operator*(float scaleUnit, const Vector2& rhs)
	{
		Vector2 scaled;
		scaled.x = scaleUnit * rhs.x;
		scaled.y = scaleUnit * rhs.y;

		return scaled;
	}

	Vector2 operator*(const Vector2& lhs, float scaleUnit)
	{
		Vector2 scaled;
		scaled.x = scaleUnit * lhs.x;
		scaled.y = scaleUnit * lhs.y;

		return scaled;
	}
}