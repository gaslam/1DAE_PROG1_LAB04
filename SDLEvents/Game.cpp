#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	SetColor(1, 0, 0);
	Rectf redSquare(g_MousePosition.x - 5, g_MousePosition.y - 5.f, 10.f, 10.f);
	FillRect(redSquare);

}

void Update(float elapsedSec)
{
	// process input, do physics 

	// e.g. Check keyboard state
	//const Uint8* pStates = SDL_GetKeyboardState(nullptr);
	//if (pStates[SDL_SCANCODE_RIGHT])
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if (pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
}

void End()
{
	// free game resources here
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{
	switch (key) {
	case SDLK_LEFT:
		std::cout << "Left arrow key was pressed\n";
		break;
	case SDLK_RIGHT:
		std::cout << "Right arrow key was pressed\n";
		break;
	case SDLK_UP:
		std::cout << "Up arrow key was pressed\n";
		break;
	case SDLK_DOWN:
		std::cout << "Down arrow key was pressed\n";
	}
}

void OnKeyUpEvent(SDL_Keycode key)
{
	switch (key)
	{
	case SDLK_LEFT:
		std::cout << "Left arrow key released\n";
		break;
	case SDLK_RIGHT:
		std::cout << "Right arrow key released\n";
		break;
	case SDLK_1:
	case SDLK_KP_1:
		std::cout << "Key 1 released\n";
		break;
	}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	g_MousePosition.x = float(e.x);
	g_MousePosition.y = float( g_WindowHeight - e.y);
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	//std::string button{};

	//switch (e.button)
	//{
	//case SDL_BUTTON_LEFT:
	//	button = "left";
	//	std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	button = "middle";
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	button = "right";
	//	break;
	//default:
	//	button = "other";
	//	break;
	//}

	//std::cout << button << " mouse button clicked\n";
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//switch (e.button)
	//{
	//case SDL_BUTTON_LEFT:
	//{
	//	std::cout << "Left mouse button released\n";
	//	Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	//	break;
	//}
	//case SDL_BUTTON_RIGHT:
	//	std::cout << "Right mouse button released\n";
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << "Middle mouse button released\n";
	//	break;
	//}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

#pragma endregion ownDefinitions