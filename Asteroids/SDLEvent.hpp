#pragma once

#ifndef SDL_EVENT_HPP
#define SDL_EVENT_HPP

#include <SDL2/SDL.h>

namespace Engine
{
	class SDLEvent
	{
	public:
		SDLEvent();
		virtual ~SDLEvent();
		virtual void OnEvent(SDL_Event* Event);
		virtual void OnInputFocus() {}
		virtual void OnInputBlur() {}
		virtual void OnKeyDown(SDL_KeyboardEvent keyBoardEvent) {}
		virtual void OnKeyUp(SDL_KeyboardEvent keyBoardEvent) {}
		virtual void OnMouseFocus() {}
		virtual void OnMouseBlur() {}
		virtual void OnMouseMove(int x, int y, int relx, int rely, bool left, bool right, bool middle) {}
		virtual void OnMouseWheel(bool up, bool down) {}
		virtual void OnLButtonDown(int x, int y) {}
		virtual void OnLButtonUp(int x, int y) {}
		virtual void OnRButtonDown(int x, int y) {}
		virtual void OnRButtonUp(int x, int y) {}
		virtual void OnMButtonDown(int x, int y) {}
		virtual void OnMButtonUp(int x, int y) {}
		virtual void OnMinimize() {}
		virtual void OnRestore() {}
		virtual void OnResize(int width, int height) {}
		virtual void OnExpose() {}
		virtual void OnExit() {}
		virtual void OnUser(Uint8 type, int code, void* data1, void* data2) {}
	private:
		void HandleWindowEvents(SDL_Event* event);
		void HandleMouseButtonDownEvents(SDL_Event* event);
		void HandleMouseButtonUpEvents(SDL_Event* event);
	};
}

#endif