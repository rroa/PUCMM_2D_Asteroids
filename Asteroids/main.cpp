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

int main(int argc, char* argv[])
{
	// https://msdn.microsoft.com/en-us/library/x98tx3cf.aspx
	// This will help you detect leaks when using Visual C++
	// Uncomment this line to start getting reports!
	// _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// Initialize SDL's Video subsystem
	//
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cerr << "Failed to init SDL" << std::endl;
		return false;
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	SDL_Window* mainWindow = SDL_CreateWindow("Asteroids - OpenGL",
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

	SDL_GLContext context = SDL_GL_CreateContext(mainWindow);
	SDL_GL_MakeCurrent(mainWindow, context);

	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		std::cerr << "Error: " << glewGetErrorString(err) << std::endl;
	}

	std::cout << "Everything loaded successfully.\n";

	// Make double buffer interval synced with vertical scanline refresh
	SDL_GL_SetSwapInterval(1);

	// Defining ortho
	float halfWidth = WIDTH * 0.5f;
	float halfHeight = HEIGHT * 0.5f;

	//// Set viewport to match window
	glViewport(0, 0, WIDTH, HEIGHT);

	//// Set Mode to GL_PROJECTION
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Set projection MATRIX to ORTHO
	/*glOrtho(-halfWidth, halfWidth, -halfHeight, halfHeight, -1, 1);*/

	//glMatrixMode(GL_MODELVIEW);

	glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-0.3f, 0.0f, 0.0f);

		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.3f, 0.0f, 0.0f);

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, 0.8f, 0.0f);
	glEnd();

	/*glPointSize(3.0f);
	glBegin(GL_POINTS);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(-0.5f, -0.5f);
	glEnd();*/

	/* Draws a square */
	/*glBegin(GL_LINE_LOOP);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.5f, -0.5f);
	glEnd();*/

	/*glBegin(GL_LINE_STRIP);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.5f, -0.5f);
	glEnd();*/

	/* Draws two horizontal lines */
	/*glBegin(GL_LINES);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.5f, -0.5f);
	glEnd();*/

	//glBegin(GL_QUADS);
	//	glVertex2f(-0.25f, 0.25f); // vertex 1
	//	glVertex2f(-0.5f, -0.25f); // vertex 2
	//	glVertex2f(0.5f, -0.25f); // vertex 3
	//	glVertex2f(0.25f, 0.25f); // vertex 4
	//glEnd();

	//glBegin(GL_TRIANGLE_STRIP); // draw in triangle strips
	//	glVertex2f(0.0f, 0.75f); // top of the roof
	//	glVertex2f(-0.5f, 0.25f); // left corner of the roof
	//	glVertex2f(0.5f, 0.25f); // right corner of the roof
	//	glVertex2f(-0.5f, -0.5f); // bottom left corner of the house
	//	glVertex2f(0.5f, -0.5f); //bottom right corner of the house
	//glEnd();

	/*glBegin(GL_TRIANGLE_FAN);
		glColor3f(1, 0, 0);
		glVertex2f(0, 0.5);
		glVertex2f(-0.4, 0);
		glVertex2f(0.4, 0);
		glColor3f(0, 1, 0);
		glVertex2f(0, -0.5);
	glEnd();*/

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	SDL_GL_SwapWindow(mainWindow);

	std::cin.get();

	// Cleanup
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(mainWindow);

	SDL_Quit();
	return 0;
}