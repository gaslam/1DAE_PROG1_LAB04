#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Events And Drawing - Lammertyn, Gaspard - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 1200 };
float g_WindowHeight{ 1000 };
const float g_Border{ 50 };
const float g_MinWidth{ 60 };
const float g_MinHeight{ 40 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
Color4f g_RectColor(0.5f, 0.5f, 0.5f, 1);
Color4f g_Green(0, 1, 0, 1);

Rectf g_Rect1(g_Border, g_WindowHeight - 60 - g_Border, g_MinWidth, g_MinHeight);
Rectf g_Rect2DefaultSize(g_WindowWidth, g_WindowHeight - 60 - g_Border, 0, g_Rect1.height);
Rectf g_Rect2(g_Rect2DefaultSize);

Point2f g_LineP1(114, 147);
Point2f g_LineP2(321, 47);

const enum class PointDirection {
	downOrLeft,
	upOrRight,
};

const enum class Colors {
	gray,
	green
};

PointDirection g_XDirectionP1(PointDirection::upOrRight);
PointDirection g_XDirectionP2(PointDirection::downOrLeft);
PointDirection g_YDirectionP1(PointDirection::downOrLeft);
PointDirection g_YDirectionP2(PointDirection::upOrRight);
Colors g_Color{Colors::green};

const float g_Speed{1};

float g_XDirectionValueP1{ g_Speed };
float g_XDirectionValueP2{ -g_Speed };
float g_YDirectionValueP1{ -g_Speed };
float g_YDirectionValueP2{ g_Speed };

bool g_CanMoveRect{false};
// Declare your own functions here
void DrawRect();
void SetRandomRectPos();
void UpdateRect();
void DrawLine();
void MoveRectangle();
void CheckLineDirectionX();
void CheckLineDirectionY();
#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void Draw();
void Update(float elapsedSec);
void End();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
