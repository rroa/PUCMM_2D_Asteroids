#pragma once
#ifndef VECTOR3_HPP
#define VECTOR3_HPP

namespace Engine
{
	class Vector3
	{
	public:
		/* =============================================================
		* PUBLIC FUNCTIONS
		* ============================================================= */
		explicit Vector3			( );
		explicit Vector3			( float x, float y, float z );
		Vector3						( const Vector3& other );

		float Normalize				( );
		float CalcLength			( );
		float CalcLengthSquared		( );
		void Scale					( float scaleUnit );
		float SetLength				( float newLength );

		/* =============================================================
		* MEMBERS
		* ============================================================= */
		float						x;
		float						y;
		float						z;
		float						length;
	};
}

#endif // !VECTOR3_HPP