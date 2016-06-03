#pragma once
#ifndef IUPDATE_HPP
#define IUPDATE_HPP

namespace Engine
{
	class IUpdate
	{
	public:
		/* =============================================================
		* PUBLIC FUNCTIONS
		* ============================================================= */
		void virtual Update		( float deltaTime ) { m_nUpdates++; };
	protected:
		/* =============================================================
		* MEMBERS
		* ============================================================= */
		int						m_nUpdates;
	};
}

#endif // !IUPDATABLE_HPP