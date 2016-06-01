#pragma once
#ifndef GAME_HPP
#define GAME_HPP

// C++ STL
#include <string>

// Asteroids
#include "SDLEvent.hpp"

namespace Engine
{
	class Game : public SDLEvent
	{
	public:
		/* =============================================================
		* ENUMERATORS
		* ============================================================= */
		struct GameState
		{
			enum State
			{
				UNINITIALIZED = 0,
				INIT_FAILED = 1,
				INIT_SUCCESSFUL = 2,
				RUNNING = 4,
				PAUSED = 8,
				QUIT = 16
			};
		};

		/* =============================================================
		 * PUBLIC FUNCTIONS
		 * ============================================================= */
		Game				( const std::string& title, const int width, const int height );
		void OnExecute		( );
		bool OnInit			( );
		void OnUpdate		( );
		void OnRender		( );
		void OnKeyDown	    ( SDL_KeyboardEvent keyBoardEvent );
		void OnKeyUp		( SDL_KeyboardEvent keyBoardEvent );
	private:
		/* =============================================================
		 * PRIVATE FUNCTIONS
		 * ============================================================= */
		bool SDLInit		( );
		bool GlewInit		( );
		void SetupViewport	( );
		void CleanupSDL		( );

		/* =============================================================
		 * MEMBERS
		 * ============================================================= */
		std::string			m_title;
		int					m_width;
		int					m_height;
		SDL_Window*			m_mainWindow;
		SDL_GLContext		m_context;
		GameState::State	m_state;
		int					m_nUpdates;
	};
}
#endif /* GAME_HPP */
