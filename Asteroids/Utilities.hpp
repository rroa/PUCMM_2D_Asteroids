#pragma once
#ifndef MATH_UTILITIES_HPP
#define MATH_UTILITIES_HPP

#include <cstdlib>

namespace Engine
{
	const float PI = 3.141592653f;

	/* =============================================================
	* INLINE OVERLOADS
	* ============================================================= */
	inline int RandInRange(int min, int max)
	{
		return min + rand() % (max - min + 1);
	}

	inline float RandInRange(float min, float max)
	{
		return min + (max - min) * (rand() / (float)RAND_MAX);
	}

	inline double RandInRange(double min, double max)
	{
		return min + (max - min) * (rand() / (double)RAND_MAX);
	}

	inline float ConvertToRad(float degrees)
	{
		return degrees * (PI / 180);
	}

	inline float ConvertToDegrees(float radians)
	{
		return radians * (180 / PI);
	}
}

#endif // !MATH_UTILITIES_HPP