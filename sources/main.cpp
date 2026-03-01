#include "raylib.h"
#include "Player.h"

#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (450)

#define WINDOW_TITLE "RayPlat"

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(60);

    const Texture2D playerSprite = LoadTexture(ASSETS_PATH"player.png");

   Player player{{100, 50}, playerSprite};

    while (!WindowShouldClose())
    {
        const float dt = GetFrameTime();

        BeginDrawing();

        ClearBackground(GREEN);
        player.update(dt);
        player.draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
