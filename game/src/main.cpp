#include "raylib.h"
#include "raymath.h"
#include "raygui.h"
#include "game.h"
#include "lib.h"
#include <cstdio>

static bool checkboxChecked = false;
static float sliderValue = 50.0f;
static char textBoxValue[64] = "Type here...";
static bool textBoxEditMode = false;

void GameInit()
{
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
    InitWindow(InitialWidth, InitialHeight, "Example with Raygui");
    SetTargetFPS(144);
}

void GameCleanup()
{
    CloseWindow();
}

bool GameUpdate()
{
    return true;
}

void GameDraw()
{
    BeginDrawing();
    ClearBackground(DARKGRAY);

    DrawText("Hello Raylib!", 10, 10, 20, GetTextColor());

    if (GuiButton((Rectangle){ 20, 50, 120, 30 }, "Click Me"))
    {
        std::printf("Button clicked!\n");
    }

    GuiCheckBox((Rectangle){ 20, 100, 20, 20 }, "Enable Feature", &checkboxChecked);

    GuiSliderBar((Rectangle){ 20, 140, 200, 20 }, "Volume", NULL, &sliderValue, 0, 100);

    if (GuiTextBox((Rectangle){ 20, 180, 200, 30 }, textBoxValue, 64, textBoxEditMode))
    {
        textBoxEditMode = !textBoxEditMode;
    }

    EndDrawing();
}

int main()
{
    GameInit();

    while (!WindowShouldClose())
    {
        if (!GameUpdate())
            break;

        GameDraw();
    }
    GameCleanup();

    return 0;
}
