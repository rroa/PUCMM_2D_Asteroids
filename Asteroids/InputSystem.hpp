#pragma once
#ifndef INPUT_SYSTEM_HPP
#define INPUT_SYSTEM_HPP

#include <memory>

namespace Engine
{
	class InputSystem
	{
	public:
		/* =============================================================
		* STATIC FUNCTIONS
		* ============================================================= */
		static void Create						( );
		static void Destroy						( );
		static InputSystem& Instance			( );

		/* =============================================================
		* PUBLIC FUNCTIONS
		* ============================================================= */
		bool IsKeyDown							( unsigned char key );
		bool IsKeyUp							( unsigned char key );
		void KeyDown							( unsigned char key );
		void KeyUp								( unsigned char key );
		void ResetInput							( );
	private:
		/* =============================================================
		* PRIVATE FUNCTIONS
		* ============================================================= */
		InputSystem								( );
		InputSystem								( InputSystem const& ) {};
		InputSystem& operator=					( InputSystem const& ) {};

		/* =============================================================
		* MEMBERS FUNCTIONS
		* ============================================================= */
		bool									m_isDown[256];
		bool									m_isUp[256];
		static std::unique_ptr < InputSystem >  s_instance;
	};
}

extern void OnKeyboardDownEvent					( unsigned char key );
extern void OnKeyboardUpEvent					( unsigned char key );

#endif // !INPUT_SYSTEM_HPP