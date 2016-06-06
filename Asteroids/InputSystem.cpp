#include "InputSystem.hpp"

#include <algorithm>

namespace Engine
{
	std::unique_ptr< InputSystem > InputSystem::s_instance = nullptr;
	InputSystem::InputSystem()
	{
		std::generate(m_isDown, m_isDown + 256, []() { return false; });
		ResetInput();
	}

	void InputSystem::Create()
	{
		if (!s_instance)
		{
			s_instance.reset(new InputSystem);
		}
	}

	void InputSystem::Destroy()
	{
		if (s_instance)
		{
			s_instance.reset();
		}
	}

	InputSystem& InputSystem::Instance()
	{
		if (!s_instance)
		{
			Create();
		}

		return *s_instance.get();
	}

	bool InputSystem::IsKeyDown(unsigned char key)
	{
		return m_isDown[key];
	}

	bool InputSystem::IsKeyUp(unsigned char key)
	{
		return m_isUp[key];
	}

	void InputSystem::KeyDown(unsigned char key)
	{
		m_isDown[key] = true;
	}

	void InputSystem::KeyUp(unsigned char key)
	{
		m_isDown[key] = false;
		m_isUp[key] = true;
	}

	void InputSystem::ResetInput()
	{
		std::generate(m_isUp, m_isUp + 256, []() { return false; });
	}
}

void OnKeyboardDownEvent(unsigned char key)
{
	Engine::InputSystem::Instance().KeyDown(key);
}

void OnKeyboardUpEvent(unsigned char key)
{
	Engine::InputSystem::Instance().KeyUp(key);
}