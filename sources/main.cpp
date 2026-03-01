#include "raylib.h"

#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (450)

#define WINDOW_TITLE "RayPlat"

struct Player {
    Vector2 position{};
    Texture2D sprite{};
    float movementSpeed = 250.0f;

    void input(const float dt) {
        if (IsKeyDown(KEY_W)) {
            position.y -= movementSpeed * dt;
        }
        if (IsKeyDown(KEY_S)) {
            position.y += movementSpeed * dt;
        }
        if (IsKeyDown(KEY_A)) {
            position.x -= movementSpeed * dt;
        }
        if (IsKeyDown(KEY_D)) {
            position.x += movementSpeed * dt;
        }
    }

     void update(const float dt) {
        input(dt);
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
        const float dt = GetFrameTime();

        BeginDrawing();


        ClearBackground(RAYWHITE);
        player.update(dt);
        player.draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
