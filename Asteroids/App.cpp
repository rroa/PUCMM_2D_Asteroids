#include "App.hpp"
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
	int  m_dimensions[2];

	App::App(const std::string& title, const int width, const int height)
		: m_title(title),
		m_width(width),
		m_height(height),
		m_nUpdates(0)
	{
		m_mainWindow = nullptr;
		m_state = AppState::UNINITIALIZED;
		m_player = new Asteroids::Player();
		m_entities.push_back(m_player);
		m_dimensions[0] = width;
		m_dimensions[1] = height;
	}

	App::~App()
	{
		if(m_player)
			delete m_player;

		CleanupSDL();
	}

	void App::OnExecute()
	{
		if (m_state != AppState::INIT_SUCCESSFUL)
		{
			std::cerr << "Game INIT was not successful." << std::endl;
			return;
		}

		m_state = AppState::RUNNING;
		CreateAsteroid(Asteroids::Asteroid::AsteroidSize::BIG, 1);

		SDL_Event event;
		while (m_state == AppState::RUNNING)
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

	bool App::OnInit()
	{
		// Init the external dependencies
		//
		bool success = SDLInit() && GlewInit();
		if (!success)
		{
			m_state = AppState::INIT_FAILED;
			return false;
		}

		// Setup the viewport
		//
		SetupViewport();

		// Change game state
		//
		m_state = AppState::INIT_SUCCESSFUL;

		return true;
	}	

	void App::CreateAsteroid(Asteroids::Asteroid::AsteroidSize::Size size, int amount, float x, float y)
	{
		for (int i = 0; i < amount; ++i)
		{
			Asteroids::Asteroid* pAsteroid = new Asteroids::Asteroid(size);
			m_entities.push_back(pAsteroid);
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

	void App::CreateBullet()
	{
		Asteroids::Bullet* pBullet = m_player->Shoot();	
		m_entities.push_back(pBullet);
		m_bullets.push_back(pBullet);
	}

	void App::CreateDebris(Asteroids::Entity* entity)
	{
		auto currentAsteroid = dynamic_cast < Asteroids::Asteroid* >(entity);
		if (currentAsteroid != nullptr
			&& currentAsteroid->GetSize() != Asteroids::Asteroid::AsteroidSize::SMALL)
		{
			auto newSize = 
				(currentAsteroid->GetSize() == Asteroids::Asteroid::AsteroidSize::BIG) ? 
					Asteroids::Asteroid::AsteroidSize::MEDIUM : 
					Asteroids::Asteroid::AsteroidSize::SMALL;

			CreateAsteroid(newSize, 2, currentAsteroid->GetX(), currentAsteroid->GetY());
		}
	}

	void App::CleanEntities()
	{
		auto iter = std::find_if(m_entities.begin(), m_entities.end(),
			[&](Asteroids::Entity* actor) { return actor->IsColliding() || actor->IsDisappearing(); });
		if (iter != m_entities.end())
		{
			DestroyEntity(*iter);
		}
	}

	void App::CheckCollision()
	{
		for (std::list< Asteroids::Asteroid* >::iterator asteroid = m_asteroids.begin(); asteroid != m_asteroids.end(); ++asteroid)
		{
			if ((*asteroid)->CouldCollide() && m_player->CouldCollide())
			{
				if (m_player->DetectCollision((*asteroid)))
				{
					CreateDebris((*asteroid));
				}

				for (std::list< Asteroids::Bullet* >::iterator bullet = m_bullets.begin(); bullet != m_bullets.end(); ++bullet)
				{
					if ((*bullet)->CouldCollide() && (*asteroid)->CouldCollide())
					{
						if ((*asteroid)->DetectCollision((*bullet)))
						{
							CreateDebris((*asteroid));
						}
					}
				}
			}
		}
	}

	void App::RespawnPlayer()
	{
		m_player = new Asteroids::Player();
		m_entities.push_back(m_player);
	}

	void App::OnKeyDown(SDL_KeyboardEvent keyBoardEvent)
	{		
		switch (keyBoardEvent.keysym.scancode)
		{
		case SDL_SCANCODE_W:
			up = true;
			break;
		case SDL_SCANCODE_A:
			left = true;
			break;		
		case SDL_SCANCODE_D:
			right = true;
			break;
		}
	}

	void App::OnKeyUp(SDL_KeyboardEvent keyBoardEvent)
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
		case SDL_SCANCODE_R:
			RespawnPlayer();
			break;
		case SDL_SCANCODE_TAB:
			m_player->ChangeShip();
			break;
		case SDL_SCANCODE_SPACE:
			//
			CreateBullet();
			break;
		case SDL_SCANCODE_ESCAPE:
			OnExit();
			break;
		}
	}

	void App::OnUpdate()
	{
		if (up)
			m_player->MoveUp();
		if (left)
			m_player->RotateLeft(DESIRED_FRAME_TIME);
		if (right)
			m_player->RotateRight(DESIRED_FRAME_TIME);

		// Updating the entities
		//
		std::list< Asteroids::Entity* >::iterator ait = m_entities.begin();
		while (ait != m_entities.end())
		{
			(*ait)->Update(DESIRED_FRAME_TIME, m_width, m_height);
			++ait;
		}

		if(m_player)
		{
			m_player->Update(DESIRED_FRAME_TIME, m_width, m_height);

			// Checking collision between the entities
			//
			CheckCollision();

			// Checking for entities marked as collided or for deletion
			//
			CleanEntities();
		}

		m_nUpdates++;
	}

	void App::OnRender()
	{
		glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Render player
		//
		if (m_player)
			m_player->Render();

		for (std::list< Asteroids::Entity* >::iterator it = m_entities.begin(); it != m_entities.end(); ++it)
		{
			if ((*it)->CouldCollide())
				(*it)->Render();
		}

		SDL_GL_SwapWindow(m_mainWindow);
	}

	void App::DestroyEntity(Asteroids::Entity* entity)
	{		
		// Retrieve actor from m_actors list
		//
		auto actorsResult = std::find(m_entities.begin(), m_entities.end(), entity);

		// Retrieve actor from m_asteroids list
		//
		auto asteroidsResult = std::find(m_asteroids.begin(), m_asteroids.end(), entity);

		// Retrieve actor from m_bullets list
		//
		auto bulletsResult = std::find(m_bullets.begin(), m_bullets.end(), entity);

		// Removing the allocated pointer
		//
		delete entity;

		if (m_player == entity)
		{
			//return;
			m_player = nullptr;
		}


		// Deleting actor iterator from lists
		//
		if (m_entities.size() > 0 && actorsResult != m_entities.end())
		{
			m_entities.erase(actorsResult);
		}

		if (m_asteroids.size() > 0 && asteroidsResult != m_asteroids.end())
		{
			m_asteroids.erase(asteroidsResult);
		}

		if (m_bullets.size() > 0 && bulletsResult != m_bullets.end())
		{
			m_bullets.erase(bulletsResult);
		}
	}

	bool App::SDLInit()
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

	void App::SetupViewport()
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

	bool App::GlewInit()
	{
		GLenum err = glewInit();
		if (GLEW_OK != err)
		{
			std::cerr << "Error: " << glewGetErrorString(err) << std::endl;
			return false;
		}

		return true;
	}

	void App::CleanupSDL()
	{
		// Cleanup
		//
		SDL_GL_DeleteContext(m_context);
		SDL_DestroyWindow(m_mainWindow);

		SDL_Quit();
	}

	void App::OnResize(int width, int height)
	{
		// TODO: Add resize functionality
		//
		m_width = width;
		m_height = height;

		SetupViewport();
	}

	void App::OnExit()
	{
		// Exit main for loop
		//
		m_state = AppState::QUIT;

		// Cleanup SDL pointers
		//
		CleanupSDL();
	}
}
