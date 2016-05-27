// C++ STL
#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

// GLEW Deps
#include <GL\glew.h>

// SDL Deps
#include <SDL2\SDL.h>
#include <SDL2\SDL_opengl.h>

const int WIDTH = 1136;
const int HEIGHT = 640;

bool Init();
bool InitSDL();
bool InitGlew();
void CleanupSDL();
void SetupViewport();
void OnRender();

SDL_GLContext context;
SDL_Window* mainWindow;

int main(int argc, char* argv[])
{
#if _MSC_VER
	// https://msdn.microsoft.com/en-us/library/x98tx3cf.aspx
	// This will help you detect leaks when using Visual C++
	// Uncomment this line to start getting reports!
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	if (!Init())
	{
		return false;
	}

	// Set viewport settings
	//
	SetupViewport();

	// Render call
	//
	OnRender();

	std::cin.get();

	CleanupSDL();
	return 0;
}

void SetupViewport()
{
	// Defining ortho
	float halfWidth = WIDTH * 0.5f;
	float halfHeight = HEIGHT * 0.5f;

	//// Set viewport to match window
	glViewport(0, 0, WIDTH, HEIGHT);

	//// Set Mode to GL_PROJECTION
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Set projection MATRIX to ORTHO
	glOrtho(-halfWidth, halfWidth, -halfHeight, halfHeight, -1, 1);

	glMatrixMode(GL_MODELVIEW);
}

void OnRender()
{
	glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	
	/*glTranslatef(-100.f, -100.f, 0.f);*/
	glRotatef(45, 0.0f, 0.0f, 1.0f);

	glBegin(GL_TRIANGLES);
		glVertex2i(-250, 0);
		glVertex2i(250, 0);
		glVertex2i(0, 250);
	glEnd();

	SDL_GL_SwapWindow(mainWindow);
}

bool Init()
{
	return InitSDL() && InitGlew();
}

bool InitSDL()
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

	mainWindow = SDL_CreateWindow("Asteroids - OpenGL",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WIDTH,
		HEIGHT,
		SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

	if (!mainWindow)
	{
		std::cerr << "Failed to create window!" << std::endl;
		SDL_Quit();
		return false;
	}

	context = SDL_GL_CreateContext(mainWindow);
	SDL_GL_MakeCurrent(mainWindow, context);

	// Make double buffer interval synced with vertical scanline refresh
	SDL_GL_SetSwapInterval(1);

	return true;
}

bool InitGlew()
{
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		std::cerr << "Error: " << glewGetErrorString(err) << std::endl;
		return false;
	}

	return true;
}

void CleanupSDL()
{
	// Cleanup
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(mainWindow);

	SDL_Quit();
}