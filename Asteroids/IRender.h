#pragma once
#ifndef IRENDER_HPP
#define IRENDER_HPP

namespace Engine
{
	class IRender
	{
	public:
		/* =============================================================
		* PUBLIC FUNCTIONS
		* ============================================================= */
		void virtual Render		( ) = 0;
	};
}

#endif // !IUPDATABLE_HPP