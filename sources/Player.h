//
// Created by Kyle B on 01/03/2026.
//

#ifndef RAYPLAT_PLAYER_H
#define RAYPLAT_PLAYER_H
#include "raylib.h"


class Player {
public:
    Player(const Vector2 &position, const Texture2D &sprite);

    Vector2 position{};
    Texture2D sprite{};

    void input(float dt);

    void update(float dt);

    void draw() const;

    float movement_speed() const;

private:
    float movementSpeed = 250.0f;
};


#endif //RAYPLAT_PLAYER_H
