#include "raylib.h"

#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (450)

#define WINDOW_TITLE "RayPlat"

struct Player {
    int x, y;
    Texture2D sprite;

    void input() {
        // TODO: Read input for WASD and move player
    }

    void update() {
        input();
    }

    void draw() const {
        DrawTexture(sprite, x, y, WHITE);
    }
};

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(60);

    const Texture2D playerSprite = LoadTexture(ASSETS_PATH"player.png");

   Player player{};
    player.sprite = playerSprite;
    player.x = 100;
    player.y = 50;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        player.draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
