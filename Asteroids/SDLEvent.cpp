#include "SDLEvent.hpp"

namespace Engine
{
	SDLEvent::SDLEvent()
	{}

	SDLEvent::~SDLEvent()
	{}

	void SDLEvent::OnEvent(SDL_Event* event)
	{
		switch (event->type)
		{
		case SDL_WINDOWEVENT:
			HandleWindowEvents(event);
			break;
		case SDL_KEYDOWN:
			OnKeyDown(event->key);
			break;
		case SDL_KEYUP:
			OnKeyUp(event->key);
			break;
		case SDL_MOUSEMOTION:
			OnMouseMove(event->motion.x,
				event->motion.y,
				event->motion.xrel,
				event->motion.yrel,
				(event->motion.state & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0,
				(event->motion.state & SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0,
				(event->motion.state & SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0);
			break;
		case SDL_MOUSEBUTTONDOWN:
			HandleMouseButtonDownEvents(event);
			break;
		case SDL_MOUSEBUTTONUP:
			HandleMouseButtonUpEvents(event);
			break;
		case SDL_QUIT:
			OnExit();
			break;
		case SDL_SYSWMEVENT:
			//Ignore
			break;
		default:
			OnUser(event->user.type, event->user.code, event->user.data1, event->user.data2);
			break;
		}
	}

	void SDLEvent::HandleWindowEvents(SDL_Event* event)
	{
		switch (event->window.event)
		{
		case SDL_WINDOWEVENT_ENTER:
			OnMouseFocus();
			break;
		case SDL_WINDOWEVENT_LEAVE:
			OnMouseBlur();
			break;
		case SDL_WINDOWEVENT_FOCUS_GAINED:
			OnInputFocus();
			break;
		case SDL_WINDOWEVENT_FOCUS_LOST:
			OnInputBlur();
			break;
		case SDL_WINDOWEVENT_RESTORED:
			OnRestore();
			break;
		case SDL_WINDOWEVENT_MINIMIZED:
			OnMinimize();
			break;
		case SDL_WINDOWEVENT_RESIZED:
			OnResize(event->window.data1, event->window.data2);
			break;
		case SDL_WINDOWEVENT_CLOSE:
			OnExit();
			break;
		case SDL_WINDOWEVENT_EXPOSED:
			OnExpose();
			break;
		default:
			break;
		}
	}

	void SDLEvent::HandleMouseButtonDownEvents(SDL_Event* event)
	{
		switch (event->button.button)
		{
		case SDL_BUTTON_LEFT:
			OnLButtonDown(event->button.x, event->button.y);
			break;
		case SDL_BUTTON_RIGHT:
			OnRButtonDown(event->button.x, event->button.y);
			break;
		case SDL_BUTTON_MIDDLE:
			OnMButtonDown(event->button.x, event->button.y);
			break;
		}
	}

	void SDLEvent::HandleMouseButtonUpEvents(SDL_Event* event)
	{
		switch (event->button.button)
		{
		case SDL_BUTTON_LEFT:
			OnLButtonUp(event->button.x, event->button.y);
			break;
		case SDL_BUTTON_RIGHT:
			OnRButtonUp(event->button.x, event->button.y);
			break;
		case SDL_BUTTON_MIDDLE:
			OnMButtonUp(event->button.x, event->button.y);
			break;
		}
	}
}