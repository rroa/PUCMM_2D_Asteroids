#pragma once

#ifndef VECTOR2_HPP
#define VECTOR2_HPP

namespace Engine
{
	class Vector2
	{
	public:
		/* =============================================================
		* PUBLIC FUNCTIONS
		* ============================================================= */
		explicit Vector2			( );
		explicit Vector2			( float x, float y );
		Vector2						( const Vector2& other );

		float Normalize				( );
		float CalcLength			( );
		float CalcLengthSquared		( );
		void Scale					( float scaleUnit );
		float SetLength				( float newLength );

		/* =============================================================
		* OPERATOR OVERLOADS
		* ============================================================= */
		Vector2& operator=			( const Vector2& rhs );
		Vector2& operator+=			( const Vector2& rhs );
		Vector2& operator-=			( const Vector2& rhs );
		Vector2& operator*=			( const Vector2& rhs );
		Vector2& operator/=			( const Vector2& rhs );
		Vector2 operator+			( const Vector2& rhs );
		Vector2 operator-			( const Vector2& rhs );
		Vector2 operator-			();
		Vector2 operator*			( const Vector2& rhs );
		Vector2 operator/			( const Vector2& rhs );
		bool operator==				( const Vector2& rhs );
		bool operator!=				( const Vector2& rhs );

		/* =============================================================
		* FRIENDS
		* ============================================================= */
		friend Vector2 operator*	( float scaleUnit, const Vector2& rhs );
		friend Vector2 operator*	( const Vector2& lhs, float scaleUnit );

		/* =============================================================
		* MEMBERS
		* ============================================================= */
		float						x;
		float						y;
		float						length;
	};
}
 
#endif // !VECTOR2_HPP