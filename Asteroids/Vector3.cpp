#include "Vector3.hpp"

#include <cmath>

namespace Engine
{
	Vector3::Vector3()
		: x(0.0f)
		, y(0.0f)
		, z(0.0f)
	{}

	Vector3::Vector3(float _x, float _y, float _z)
		: x(_x)
		, y(_y)
		, z(_z)
	{}

	Vector3::Vector3(const Vector3& other)
		: x(other.x)
		, y(other.y)
		, z(other.z)
		, length(other.length)
	{}

	float Vector3::Normalize()
	{
		// Calculating the length
		CalcLength();

		float inverseScale = 1.0f / length;
		x *= inverseScale;
		y *= inverseScale;

		return length;
	}

	float Vector3::CalcLength()
	{
		float lenSquared = x * x + y * y + z * z;
		if (lenSquared == 0)
		{
			length = 0.0f;
			return length;
		}

		length = std::sqrtf(lenSquared);

		return length;
	}

	float Vector3::CalcLengthSquared()
	{
		float lenSquared = x * x + y * y + z * z;
		if (lenSquared == 0) return 0.0f;

		return lenSquared;
	}

	void Vector3::Scale(float scaleUnit)
	{
		x *= scaleUnit;
		y *= scaleUnit;
		z *= scaleUnit;
	}

	float Vector3::SetLength(float newLength)
	{
		float oldLen = length;
		float lenSquared = x * x + y * y + z * z;
		if (lenSquared == 0) return 0.0f;

		// Calculating new length
		length = std::sqrtf(lenSquared);

		float inverseScale = newLength / length;
		x *= inverseScale;
		y *= inverseScale;
		z *= inverseScale;

		return oldLen;
	}
}