#include "Matrix2.hpp"

namespace Engine
{
	Matrix2::Matrix2()
	{}

	Matrix2::Matrix2(float radians)
	{
		float c = std::cos(radians);
		float s = std::sin(radians);

		m00 = c; m01 = -s;
		m10 = s; m11 = c;
	}

	Matrix2::Matrix2(float a, float b, float c, float d)
		: m00(a), m01(b)
		, m10(c), m11(d)
	{}

	void Matrix2::Set(float radians)
	{
		float c = std::cos(radians);
		float s = std::sin(radians);

		m00 = c; m01 = -s;
		m10 = s; m11 = c;
	}

	Matrix2 Matrix2::Abs(void) const
	{
		return Matrix2(std::abs(m00), std::abs(m01), std::abs(m10), std::abs(m11));
	}

	Vector2 Matrix2::AxisX(void) const
	{
		return Vector2(m00, m10);
	}

	Vector2 Matrix2::AxisY(void) const
	{
		return Vector2(m01, m11);
	}

	Matrix2 Matrix2::Transpose(void) const
	{
		return Matrix2(m00, m10, m01, m11);
	}

	const Vector2 Matrix2::operator*(const Vector2& rhs) const
	{
		return Vector2(m00 * rhs.x + m01 * rhs.y, m10 * rhs.x + m11 * rhs.y);
	}

	const Matrix2 Matrix2::operator*(const Matrix2& rhs) const
	{
		// [00 01]  [00 01]
		// [10 11]  [10 11]

		return Matrix2(
			m[0][0] * rhs.m[0][0] + m[0][1] * rhs.m[1][0],
			m[0][0] * rhs.m[0][1] + m[0][1] * rhs.m[1][1],
			m[1][0] * rhs.m[0][0] + m[1][1] * rhs.m[1][0],
			m[1][0] * rhs.m[0][1] + m[1][1] * rhs.m[1][1]
		);
	}
}