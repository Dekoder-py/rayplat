//
// Created by Kyle B on 01/03/2026.
//

#include "Player.h"

Player::Player(const Vector2 &position, const Texture2D &sprite)
    : position(position),
      sprite(sprite) {
}

void Player::input(const float dt) {
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

void Player::update(const float dt) {
    input(dt);
}

void Player::draw() const {
    DrawTexture(sprite, position.x, position.y, WHITE);
}

float Player::movement_speed() const {
    return movementSpeed;
}
