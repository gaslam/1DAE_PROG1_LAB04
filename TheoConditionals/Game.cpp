#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	int number{ rand() % 11 };
	if (number < 5) {
		std::cout << "number is smaller than 5\n";
	}
	else {
		std::cout << "number is larger than or equal to 5\n";
	}

	std::cout << "Number is " << ((number < 5) ? "smaller than 5\n" : "larger than or equal to 5\n");

	g_Position.x = g_WindowWidth / 2;
	g_Position.y = g_WindowHeight / 2;
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	SetColor(1, 0, 0, 1);
	FillEllipse(g_Position, 10, 10);

}

void Update(float elapsedSec)
{
	// process input, do physics 
	float speed{ 2 };

	switch (g_DirectionState) {
	case DirectionState::right:
		g_Position.x += speed;
		break;
	case DirectionState::left:
		g_Position.x -= speed;
		break;
	case DirectionState::up:
		g_Position.y += speed;
		break;
	case DirectionState::down:
		g_Position.y -= speed;
		break;
	}

	if (g_Position.x >= g_WindowWidth) {
		g_DirectionState = DirectionState::right;
	}
	else if (g_Position.x <= 0) {
		g_DirectionState = DirectionState::left;
	}

	if (g_Position.y >= g_WindowHeight) {
		g_DirectionState = DirectionState::down;
	}
	else if (g_Position.y <= 0) {
		g_DirectionState = DirectionState::up;
	}

	// e.g. Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
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

}

void OnKeyUpEvent(SDL_Keycode key)
{
	switch (key)
	{
	case SDLK_LEFT:
		g_DirectionState = DirectionState::left;
		break;
	case SDLK_RIGHT:
		g_DirectionState = DirectionState::right;
		break;
	case SDLK_UP:
		g_DirectionState = DirectionState::up;
		break;
	case SDLK_DOWN:
		g_DirectionState = DirectionState::down;
		break;
	case SDLK_1:
	case SDLK_KP_1:
		std::cout << "Key 1 released\n";
		break;
	}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	////std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//switch (e.button)
	//{
	//case SDL_BUTTON_LEFT:
	//{
	//	//std::cout << "Left mouse button released\n";
	//	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	//	break;
	//}
	//case SDL_BUTTON_RIGHT:
	//	//std::cout << "Right mouse button released\n";
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	//std::cout << "Middle mouse button released\n";
	//	break;
	//}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

#pragma endregion ownDefinitions