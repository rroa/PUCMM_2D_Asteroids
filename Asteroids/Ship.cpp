#include "Ship.hpp"

#include "TransformationComponent.hpp"
#include "RigidBodyComponent.hpp"

#include <SDL2/SDL_opengl.h>

namespace Asteroids
{
	Ship::Ship()
	{
		this->AttachComponent(new Engine::TransformationComponent());
		this->AttachComponent(new Engine::RigidBodyComponent());
	}

	void Ship::Render()
	{
		Engine::TransformationComponent* tc = this->GetComponent<Engine::TransformationComponent>();
		glLoadIdentity();
		glTranslatef(tc->GetPosition().x, tc->GetPosition().y, 0.0f);
		//glRotatef(m_angle, 0.0f, 0.0f, 1.0f);

		glBegin(GL_LINE_LOOP);
			glColor3f(1.0f, 1.0f, 1.0f);
			glVertex2f(0, 200);
			glVertex2f(-200, 0);
			glVertex2f(200, 0);
		glEnd();

		Engine::GameObject::Render();
	}
}