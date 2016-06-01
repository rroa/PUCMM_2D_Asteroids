#include "Game.hpp"
#include <iostream>

// OpenGL includes
#include <GL\glew.h>
#include <SDL2\SDL_opengl.h>

namespace Engine
{
	const float PI = 3.141592653f;
	static float x = 0;
	static float y = 0;
	static float angle = 0;

	Game::Game(const std::string& title, const int width, const int height)
		: m_title(title),
		m_width(width),
		m_height(height),
		m_nUpdates(0)
	{
		m_mainWindow = nullptr;
		m_state = GameState::UNINITIALIZED;
	}

	void Game::OnExecute()
	{
		if (m_state != GameState::INIT_SUCCESSFUL)
		{
			std::cerr << "Game INIT was not successful." << std::endl;
			return;
		}

		m_state = GameState::RUNNING;

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

	//void Game::HandleKeyboardEvent(SDL_Event* event)
	//{
	//	switch (event->key.keysym.scancode)
	//	{
	//	case SDL_SCANCODE_W:
	//		x += 1 + std::cosf(angle * (PI / 180));
	//		y += 1 + std::sinf(angle * (PI / 180));
	//		break;
	//	case SDL_SCANCODE_A:
	//		angle += 1.0f;
	//		break;
	//	case SDL_SCANCODE_D:
	//		angle -= 1.0f;
	//		break;
	//	default:
	//		break;
	//	}
	//	/*if (event->key.keysym.scancode != SDL_GetScancodeFromKey(event->key.keysym.sym))*/
	//	std::cout << "Physical "
	//		<< SDL_GetScancodeName(event->key.keysym.scancode)
	//		<< " key acting as "
	//		<< SDL_GetKeyName(event->key.keysym.sym)
	//		<< " key\n";
	//}

	void Game::OnKeyDown(SDL_KeyboardEvent keyBoardEvent)
	{}

	void Game::OnKeyUp(SDL_KeyboardEvent keyBoardEvent)
	{}

	void Game::OnUpdate()
	{
		/*m_nUpdates++;*/
	}

	void Game::OnRender()
	{
		glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glLoadIdentity();
		glTranslatef(x, y, 0.0f);
		glRotatef(angle, 0.0f, 0.0f, 1.0f);

		glBegin(GL_LINE_LOOP);
			glVertex2f(0.0f, 20.0f);
			glVertex2f(12.0f, -10.0f);
			glVertex2f(6.0f, -4.0f);
			glVertex2f(-6.0f, -4.0f);
			glVertex2f(-12.0f, -10.0f);
		glEnd();

		SDL_GL_SwapWindow(m_mainWindow);
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
}