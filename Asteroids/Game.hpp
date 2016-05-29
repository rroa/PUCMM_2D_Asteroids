#pragma once
#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <SDL2\SDL.h>

namespace Engine
{
	class Game
	{
	public:
		/* =============================================================
		* ENUMERATORS
		* ============================================================= */
		struct GameState
		{
			enum State
			{
				STARTING = 0,
				START_FAILED = 1,
				RUNNING = 2,
				PAUSED = 4,
				QUIT = 8
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
	};
}
#endif /* GAME_HPP */
