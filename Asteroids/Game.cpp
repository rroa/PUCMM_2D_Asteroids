#include "Game.hpp"
#include <iostream>
#include <algorithm>

// OpenGL includes
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>

//
#include "Player.hpp"

namespace Engine
{
	inline float randInRange(float min, float max)
	{
		return min + (max - min) * (rand() / (float)RAND_MAX);
	}

	const float DESIRED_FRAME_RATE = 60.0f;
	const float DESIRED_FRAME_TIME = 1.0f / DESIRED_FRAME_RATE;
	bool up = false;
	bool left = false;
	bool right = false;
	float m_dimensions[2];

	Game::Game(const std::string& title, const int width, const int height)
		: m_title(title),
		m_width(width),
		m_height(height),
		m_nUpdates(0)
	{
		m_mainWindow = nullptr;
		m_state = GameState::UNINITIALIZED;
		m_player = new Asteroids::Player();
		m_dimensions[0] = width;
		m_dimensions[1] = height;
	}

	Game::~Game()
	{
		delete m_player;
		CleanupSDL();
	}

	void Game::OnExecute()
	{
		if (m_state != GameState::INIT_SUCCESSFUL)
		{
			std::cerr << "Game INIT was not successful." << std::endl;
			return;
		}

		m_state = GameState::RUNNING;
		CreateAsteroid(Asteroids::Asteroid::AsteroidSize::BIG, 10);

		SDL_Event event;
		while (m_state == GameState::RUNNING)
		{
			// Input polling
			//
			while (SDL_PollEvent(&event))
			{
				OnEvent(&event);
			}

			//
			OnUpdate();
			OnRender();
		}
	}

	bool Game::OnInit()
	{
		// Init the external dependencies
		//
		bool success = SDLInit() && GlewInit();
		if (!success)
		{
			m_state = GameState::INIT_FAILED;
			return false;
		}

		// Setup the viewport
		//
		SetupViewport();

		// Change game state
		//
		m_state = GameState::INIT_SUCCESSFUL;

		return true;
	}	

	void Game::CreateAsteroid(Asteroids::Asteroid::AsteroidSize::Size size, int amount, float x, float y)
	{
		for (int i = 0; i < amount; ++i)
		{
			Asteroids::Asteroid* pAsteroid = new Asteroids::Asteroid(size);
			m_asteroids.push_back(pAsteroid);

			if (x == 0 && y == 0)
			{
				const int sideAxis = rand() & 1;
				const float sideDir = (rand() & 1) ? 1.0f : -1.0f;

				const int otherSideAxis = (sideAxis + 1) & 1;

				float point[2];
				point[sideAxis] = sideDir * m_dimensions[sideAxis] * 0.5f;
				point[otherSideAxis] = randInRange(m_dimensions[otherSideAxis] * -0.5f, m_dimensions[otherSideAxis] * 0.5f);

				pAsteroid->Teleport(point[0], point[1]);
			}
			else
			{
				pAsteroid->Teleport(x, y);
			}

			// Applying impulse to the asteroid
			//
			float x = randInRange(-150.0f, 150.0f);
			float y = randInRange(-150.0f, 150.0f);

			pAsteroid->ApplyImpulse(Engine::Vector2(x, y));
		}
	}

	void Game::CreateBullet()
	{
		Asteroids::Bullet* pBullet = m_player->Shoot();		
		m_bullets.push_back(pBullet);
	}

	void Game::OnKeyDown(SDL_KeyboardEvent keyBoardEvent)
	{		
		switch (keyBoardEvent.keysym.scancode)
		{
		case SDL_SCANCODE_W:
			//
			//m_player->MoveUp();
			up = true;
			break;
		case SDL_SCANCODE_A:
			//
			//m_player->RotateLeft(DESIRED_FRAME_TIME);
			left = true;
			break;		
		case SDL_SCANCODE_D:
			//
			//m_player->RotateRight(DESIRED_FRAME_TIME);
			right = true;
			break;
		case SDL_SCANCODE_SPACE:
			//
			CreateBullet();
			break;
		}
	}

	void Game::OnKeyUp(SDL_KeyboardEvent keyBoardEvent)
	{
		switch (keyBoardEvent.keysym.scancode)
		{
		case SDL_SCANCODE_W:
			up = false;
			break;
		case SDL_SCANCODE_A:
			left = false;
			break;
		case SDL_SCANCODE_D:
			right = false;
			break;
		case SDL_SCANCODE_TAB:
			m_player->ChangeShip();
			break;
		case SDL_SCANCODE_SPACE:
			break;
		case SDL_SCANCODE_ESCAPE:
			OnExit();
			break;
		}
	}

	void Game::OnUpdate()
	{
		if (up)
			m_player->MoveUp();
		if (left)
			m_player->RotateLeft(DESIRED_FRAME_TIME);
		if (right)
			m_player->RotateRight(DESIRED_FRAME_TIME);

		m_player->Update(DESIRED_FRAME_TIME, m_width, m_height);

		std::list< Asteroids::Asteroid* >::iterator ait = m_asteroids.begin();
		while (ait != m_asteroids.end())
		{
			(*ait)->Update(DESIRED_FRAME_TIME, m_width, m_height);
			++ait;
		}

		std::list< Asteroids::Bullet* >::iterator bul = m_bullets.begin();
		while (bul != m_bullets.end())
		{
			(*bul)->Update(DESIRED_FRAME_TIME, m_width, m_height);
			++bul;
		}

		auto iter = std::find_if(m_bullets.begin(), m_bullets.end(),
			[&](Asteroids::Entity* actor) { return actor->IsColliding() || actor->IsDisappearing(); });
		if (iter != m_bullets.end())
		{
			DestroyEntity(*iter);
		}

		m_nUpdates++;
	}

	void Game::OnRender()
	{
		glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Render player
		//
		m_player->Render();

		std::list< Asteroids::Asteroid* >::iterator ait = m_asteroids.begin();
		while (ait != m_asteroids.end())
		{
			(*ait)->Render();
			++ait;
		}

		std::list< Asteroids::Bullet* >::iterator bul = m_bullets.begin();
		while (bul != m_bullets.end())
		{
			(*bul)->Render();
			++bul;
		}

		SDL_GL_SwapWindow(m_mainWindow);
	}

	void Game::DestroyEntity(Asteroids::Entity* entity)
	{		
		// Retrieve actor from m_asteroids list
		//
		auto asteroidsResult = std::find(m_asteroids.begin(), m_asteroids.end(), entity);

		// Retrieve actor from m_bullets list
		//
		auto bulletsResult = std::find(m_bullets.begin(), m_bullets.end(), entity);

		// Removing the allocated pointer
		//
		delete entity;

		// Deleting actor iterator from lists
		//
		if (m_asteroids.size() > 0 && asteroidsResult != m_asteroids.end())
		{
			m_asteroids.erase(asteroidsResult);
		}

		if (m_bullets.size() > 0 && bulletsResult != m_bullets.end())
		{
			m_bullets.erase(bulletsResult);
		}
	}

	bool Game::SDLInit()
	{
		// Initialize SDL's Video subsystem
		//
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			std::cerr << "Failed to init SDL" << std::endl;
			return false;
		}

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

		Uint32 flags =  SDL_WINDOW_OPENGL     | 
						SDL_WINDOW_SHOWN      | 
						SDL_WINDOW_RESIZABLE;

		m_mainWindow = SDL_CreateWindow(
			m_title.c_str(),
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			m_width,
			m_height,
			flags
		);

		if (!m_mainWindow)
		{
			std::cerr << "Failed to create window!" << std::endl;
			SDL_Quit();
			return false;
		}

		m_context = SDL_GL_CreateContext(m_mainWindow);
		SDL_GL_MakeCurrent(m_mainWindow, m_context);

		// Make double buffer interval synced with vertical scanline refresh
		SDL_GL_SetSwapInterval(1);

		return true;
	}

	void Game::SetupViewport()
	{
		// Defining ortho values
		//
		float halfWidth = m_width * 0.5f;
		float halfHeight = m_height * 0.5f;

		// Set viewport to match window
		//
		glViewport(0, 0, m_width, m_height);

		// Set Mode to GL_PROJECTION
		//
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		// Set projection MATRIX to ORTHO
		//
		glOrtho(-halfWidth, halfWidth, -halfHeight, halfHeight, -1, 1);

		// Setting Mode to GL_MODELVIEW
		//
		glMatrixMode(GL_MODELVIEW);
	}

	bool Game::GlewInit()
	{
		GLenum err = glewInit();
		if (GLEW_OK != err)
		{
			std::cerr << "Error: " << glewGetErrorString(err) << std::endl;
			return false;
		}

		return true;
	}

	void Game::CleanupSDL()
	{
		// Cleanup
		//
		SDL_GL_DeleteContext(m_context);
		SDL_DestroyWindow(m_mainWindow);

		SDL_Quit();
	}

	void Game::OnResize(int width, int height)
	{
		// TODO: Add resize functionality
		//
		m_width = width;
		m_height = height;

		SetupViewport();
	}

	void Game::OnExit()
	{
		// Exit main for loop
		//
		m_state = GameState::QUIT;

		// Cleanup SDL pointers
		//
		CleanupSDL();
	}
}
