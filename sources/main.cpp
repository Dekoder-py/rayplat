#include "raylib.h"

#include <iostream>

#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (450)

#define WINDOW_TITLE "RayPlat"

struct Player {
    Vector2 position;
    Texture2D sprite;

    void input() {
        // TODO: Read input for WASD and move player
        if (IsKeyPressed(KEY_SPACE)) {
            std::cout << "SPACE\n";
        }
    }

    void update() {
        input();
    }

    void draw() const {
        DrawTexture(sprite, position.x, position.y, WHITE);
    }
};

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(60);

    const Texture2D playerSprite = LoadTexture(ASSETS_PATH"player.png");

   Player player{};
    player.sprite = playerSprite;
    player.position.x = 100;
    player.position.y = 50;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        player.update();
        player.draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
