#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	//Color blue
	float r{ 1.f / 19.62f }, g{ 1.f / 42.5f }, b{ 1.f / 3.75f };
	ClearBackground(r, g, b);

	// Put your own draw statements here
	DrawRect();
	DrawLine();
}

void DrawRect() {
	SetColor(g_RectColor);
	FillRect(g_Rect1);
	if (g_Rect1.left == 0) {
		FillRect(g_Rect2);
	}
}

void Update(float elapsedSec)
{
	g_LineP1.x += g_XDirectionValueP1;
	g_LineP1.y += g_YDirectionValueP1;
	g_LineP2.x += g_XDirectionValueP2;
	g_LineP2.y += g_YDirectionValueP2;

	CheckLineDirectionX();
	CheckLineDirectionY();
	if (g_CanMoveRect) {
		MoveRectangle();
	}

}

void MoveRectangle() {
	g_Rect1.left -= g_Speed;

	//Fixes issue where the default Rect2Size would appear on screen for a split second
	if (g_Rect1.left < 1) {
		float posNumber{ -g_Rect1.left };
		g_Rect1.left = 0;
		g_Rect1.width -= posNumber;
		g_Rect2.left -= posNumber;
		g_Rect2.width += posNumber;
		g_Rect2.height = g_Rect1.height;
		g_Rect2.bottom = g_Rect1.bottom;
	}
	if (g_Rect1.width == 0) {
		g_Rect1 = g_Rect2;
		g_Rect2 = g_Rect2DefaultSize;
	}
}

void CheckLineDirectionX() {
	if (g_LineP1.x == 0 || g_LineP1.x == g_WindowWidth) {
		if (g_XDirectionP1 == PointDirection::upOrRight) {
			g_XDirectionP1 = PointDirection::downOrLeft;
			g_XDirectionValueP1 = -g_Speed;
		}
		else {
			g_XDirectionP1 = PointDirection::upOrRight;
			g_XDirectionValueP1 = g_Speed;
		}
	}

	if (g_LineP2.x == 0 || g_LineP2.x == g_WindowWidth) {
		if (g_XDirectionP2 == PointDirection::upOrRight) {
			g_XDirectionP2 = PointDirection::downOrLeft;
			g_XDirectionValueP2 = -g_Speed;
		}
		else {
			g_XDirectionP2 = PointDirection::upOrRight;
			g_XDirectionValueP2 = g_Speed;
		}
	}
}

void CheckLineDirectionY() {
	if (g_LineP1.y == 0 || g_LineP1.y == g_WindowHeight) {
		if (g_YDirectionP1 == PointDirection::upOrRight) {
			g_YDirectionP1 = PointDirection::downOrLeft;
			g_YDirectionValueP1 = -1;
		}
		else {
			g_YDirectionP1 = PointDirection::upOrRight;
			g_YDirectionValueP1 = 1;
		}
	}

	if (g_LineP2.y == 0 || g_LineP2.y == g_WindowHeight) {
		if (g_YDirectionP2 == PointDirection::upOrRight) {
			g_YDirectionP2 = PointDirection::downOrLeft;
			g_YDirectionValueP2 = -1;
		}
		else {
			g_YDirectionP2 = PointDirection::upOrRight;
			g_YDirectionValueP2 = 1;
		}
	}
}

void End()
{
	// free game resources here
}

void SetRandomRectPos() {
	const float maxHeight{ g_WindowHeight - (g_Border * 2) }, maxWidth{ g_WindowWidth - (g_Border * 2) };
	float randomHeight{ float(rand() % int(maxHeight - g_Border) + g_MinHeight) }, randomWidth{ float(rand() % int(maxWidth - g_Border) + g_MinWidth) };
	float xPos{ rand() % int(maxWidth - randomWidth) + g_Border };
	float yPos{ rand() % int(maxHeight - randomHeight) + g_Border };

	g_Rect1.width = randomWidth;
	g_Rect1.height = randomHeight;
	g_Rect1.left = xPos;
	g_Rect1.bottom = yPos;

	if (g_CanMoveRect) {
		g_Rect2 = g_Rect2DefaultSize;
	}
}

void UpdateRect() {
	switch (g_Color)
	{
	case Colors::gray:
		g_RectColor = Color4f(0.5f, 0.5f, 0.5f, 1);
		g_Color = Colors::green;
		break;
	case Colors::green:
		g_RectColor = g_Green;
		g_Color = Colors::gray;
		break;
	default:
		break;
	}
	SetRandomRectPos();
}

void DrawLine() {
	SetColor(g_Green);
	DrawLine(g_LineP1, g_LineP2);
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	if (key == SDLK_r && !g_CanMoveRect) {
		g_CanMoveRect = true;
	}
	else if (key == SDLK_r && g_CanMoveRect) {
		g_CanMoveRect = false;
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
	if (e.button == SDL_BUTTON_LEFT) {
		float yPos{ g_WindowHeight - e.y };
		bool isInYRange{ yPos >= g_Rect1.bottom && yPos <= (g_Rect1.bottom + g_Rect1.height) };
		bool isInXRange{ e.x >= g_Rect1.left && e.x <= (g_Rect1.left + g_Rect1.width) };
		if (isInYRange && isInXRange) {
			UpdateRect();
		}

		if (g_Rect2.width > 0) {
			isInYRange = yPos >= g_Rect2.bottom && yPos <= (g_Rect2.bottom + g_Rect2.height);
			isInXRange = e.x >= g_Rect2.left && e.x <= (g_Rect2.left + g_Rect2.width);
			if (isInYRange && isInXRange) {
				UpdateRect();
			}
		}


	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

#pragma endregion ownDefinitions