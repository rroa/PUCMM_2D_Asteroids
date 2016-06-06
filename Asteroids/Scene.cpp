#include "Scene.hpp"

#include <SDL2/SDL_opengl.h>
#include <algorithm>

namespace Engine
{
	Scene::Scene(Vector3 background)
		: m_background(background)
	{}

	void Scene::Update(float deltaTime)
	{
		// Update children
		//
		std::vector< GameObject* >::iterator child = m_gameObjects.begin();
		for (; child != m_gameObjects.end(); ++child)
		{
			(*child)->Update(deltaTime);
		}

		IUpdate::Update(deltaTime);
	}

	void Scene::Render()
	{
		// TODO: RR: Move this to renderer class
		glClearColor(m_background.x, 
					 m_background.y, 
					 m_background.z, 
				 	 1.0f);

		glClear(GL_COLOR_BUFFER_BIT);

		// Render children
		//
		std::vector< GameObject* >::iterator child = m_gameObjects.begin();
		for (; child != m_gameObjects.end(); ++child)
		{
			(*child)->Render();
		}
	}

	void Scene::AddGameObject(GameObject* go)
	{
		m_gameObjects.push_back(go);
	}

	void Scene::RemoveGameObject(GameObject* go)
	{
		m_gameObjects.erase(
			std::remove(m_gameObjects.begin(), m_gameObjects.end(), go), m_gameObjects.end()
		);

		delete go;
	}
}