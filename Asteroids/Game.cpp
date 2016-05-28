#include "Game.hpp"

#include <iostream>

//
#include <GL\glew.h>

//
#include <SDL2\SDL_opengl.h>

namespace Asteroids
{
	Game::Game(const std::string& title, const float width, const float height)
		: m_title(title),
		m_width(width),
		m_height(height)
	{
		m_mainWindow = nullptr;
		m_state = GameState::RUNNING;
	}

	void Game::OnExecute()
	{
		if (!OnInit())
		{
			std::cout << "Game Init error!\n";
			return;
		}

		SDL_Event event;
		while (m_state == GameState::RUNNING)
		{
			//double startTime = GetAbsoluteTimeSeconds();

			while (SDL_PollEvent(&event))
			{
				//OnEvent(&event);
			}

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
			return false;
		}

		// Setup the viewport
		//
		SetupViewport();

		return true;
	}

	void Game::OnKeyDown(SDL_KeyboardEvent keyBoardEvent)
	{}

	void Game::OnKeyUp(SDL_KeyboardEvent keyBoardEvent)
	{}

	void Game::OnUpdate()
	{}

	void Game::OnRender()
	{
		glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

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

		m_mainWindow = SDL_CreateWindow("Asteroids - OpenGL",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			m_width,
			m_height,
			SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

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
		// Defining ortho
		float halfWidth = m_width * 0.5f;
		float halfHeight = m_height * 0.5f;

		// Set viewport to match window
		glViewport(0, 0, m_width, m_height);

		// Set Mode to GL_PROJECTION
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		// Set projection MATRIX to ORTHO
		glOrtho(-halfWidth, halfWidth, -halfHeight, halfHeight, -1, 1);

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