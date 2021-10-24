#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Explosion - Lammertyn, Gaspard - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
float g_WindowWidthDivBy2{ g_WindowWidth / 2 };
float g_WindowHeightDivBy2{ g_WindowHeight / 2 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
bool g_canDrawExplosion{ false };

const float g_RectSize{ 100 };
const float g_RectSizeDivBy2{ g_RectSize / 2 };

const float g_xRedRectDistance{ g_WindowHeight - g_RectSizeDivBy2};
const float g_yRedRectDistance{ g_WindowWidth - g_RectSizeDivBy2};

float g_CurrentRadius{ 0 };

Color4f g_middleRectColor(0, 0, 0, 1);
const Color4f g_Red(1, 0, 0, 1);
// Declare your own functions here

#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void Draw();
void Update(float elapsedSec);
void End();
void ProcessMouseClick(Point2f mousePos);
void DrawExplosion();
void UpdateExplosion();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
