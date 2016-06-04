#pragma once
#ifndef GAME_HPP
#define GAME_HPP

// C++ STL
#include <string>
#include <list>

// Asteroids
#include "SDLEvent.hpp"
#include "Player.hpp"
#include "Asteroid.hpp"
#include "Bullet.hpp"
#include "TimeManager.hpp"

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
		Game								( const std::string& title, const int width, const int height );
		~Game								( );
		void OnExecute						( );
		bool OnInit							( );
		void OnUpdate						( );
		void OnRender						( );
		void OnKeyDown						( SDL_KeyboardEvent keyBoardEvent ) override;
		void OnKeyUp						( SDL_KeyboardEvent keyBoardEvent ) override;
	private:
		/* =============================================================
		 * PRIVATE FUNCTIONS
		 * ============================================================= */
		bool SDLInit						( );
		bool GlewInit						( );
		void SetupViewport					( );
		void CleanupSDL						( );
		void OnResize						( int width, int height ) override;
		void OnExit							( ) override;
		void CreateAsteroid					( Asteroids::Asteroid::AsteroidSize::Size size, int amount, float x = 0.0f, float y = 0.0f );
		void CreateDebris					( Asteroids::Entity* entity );
		void CheckCollision					( );
		void CleanEntities					( );
		void CreateBullet					( );
		void DestroyEntity					( Asteroids::Entity* entity );
		void RespawnPlayer					( );
		void UpdateScore				( int delta );

		/* =============================================================
		 * MEMBERS
		 * ============================================================= */
		int									m_width;
		int									m_height;
		int									m_nUpdates;
		int									m_score;
		double								m_lastFrameTime;
		std::string							m_title;
		SDL_Window*							m_mainWindow;
		SDL_GLContext						m_context;
		GameState::State					m_state;
		Asteroids::Player*					m_player;
		std::list< Asteroids::Asteroid* >	m_asteroids;
		std::list< Asteroids::Bullet* >		m_bullets;
		std::list< Asteroids::Entity* >     m_entities;
		Engine::TimeManager*				m_timer;
	};
}
#endif /* GAME_HPP */
