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
	if (g_canDrawExplosion) {
		DrawExplosion();
	}

	SetColor(g_middleRectColor);
	FillRect(g_WindowWidthDivBy2 - g_RectSizeDivBy2, g_WindowHeightDivBy2 - g_RectSizeDivBy2, g_RectSize, g_RectSize);



}

void DrawExplosion() {
	float currentXBasePos{ g_WindowHeightDivBy2 - g_RectSizeDivBy2 };
	float currentYBasePos{ g_WindowHeightDivBy2 - g_RectSizeDivBy2 };

	SetColor(g_Red);
	Rectf Rect1(currentXBasePos - g_CurrentRadius, currentYBasePos + g_CurrentRadius, g_RectSize, g_RectSize);
	Rectf Rect2(currentXBasePos - g_CurrentRadius, currentYBasePos - g_CurrentRadius, g_RectSize, g_RectSize);
	Rectf Rect3(currentXBasePos + g_CurrentRadius, currentYBasePos + g_CurrentRadius, g_RectSize, g_RectSize);
	Rectf Rect4(currentXBasePos + g_CurrentRadius, currentYBasePos - g_CurrentRadius, g_RectSize, g_RectSize);

	FillRect(Rect1);
	FillRect(Rect2);
	FillRect(Rect3);
	FillRect(Rect4);
}

void UpdateExplosion() {
	++g_CurrentRadius;
	if (g_CurrentRadius == (g_WindowHeightDivBy2 + g_RectSizeDivBy2)) {
		g_canDrawExplosion = false;
		g_middleRectColor.a = 1.f;
		g_CurrentRadius = 0;
	}
}

void Update(float elapsedSec)
{
	if (g_canDrawExplosion) {
		UpdateExplosion();
	}

	// process input, do physics 

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
	//switch (key)
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
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
	std::cout << "  [" << e.x << ", " << e.y << "]\n";
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		std::cout << "Left mouse button released\n";
		Point2f mousePos{ float(e.x), float(g_WindowHeight - e.y) };
		ProcessMouseClick(mousePos);
		break;
	}
	case SDL_BUTTON_RIGHT:
		std::cout << "Right mouse button released\n";
		break;
	case SDL_BUTTON_MIDDLE:
		std::cout << "Middle mouse button released\n";
		break;
	}
}

void ProcessMouseClick(Point2f mousePos) {
	bool isInValidXArea{ mousePos.x >= g_WindowWidthDivBy2 - g_RectSizeDivBy2 && mousePos.x <= g_WindowWidthDivBy2 + g_RectSizeDivBy2 };
	bool isInValidYArea{ mousePos.y >= g_WindowHeightDivBy2 - g_RectSizeDivBy2 && mousePos.y <= g_WindowHeightDivBy2 + g_RectSizeDivBy2 };

	if (isInValidXArea && isInValidYArea) {
		g_middleRectColor.a = 0.5f;
		g_canDrawExplosion = true;
	}

}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

#pragma endregion ownDefinitions