#pragma once
#include <string>
#include <SDL2\SDL.h>

namespace Asteroids
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
				RUNNING = 1,
				PAUSED = 2,
				QUIT = 4
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
		int				m_width;
		int				m_height;
		SDL_Window*			m_mainWindow;
		SDL_GLContext		m_context;
		GameState::State	m_state;
	};
}