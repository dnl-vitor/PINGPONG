#include "Paddle.h"

void Paddle::LimitMovement() {
    if (y <= 0) y = 0;
    if (y + height >= GetScreenHeight()) {
        y = GetScreenHeight() - height;
    }
}

void Paddle::Draw() {
    DrawRectangleRounded(Rectangle{x, y, width, height}, 0.8, 0, WHITE);
}

void Paddle::Update() {
    if (IsKeyDown(KEY_UP)) {
        y -= speed;
    } else if (IsKeyDown(KEY_DOWN)) {
        y += speed;
    }
    LimitMovement();
}

void Player2::Update() {
    if (IsKeyDown(KEY_W)) {
        y -= speed;
    } else if (IsKeyDown(KEY_S)) {
        y += speed;
    }
    LimitMovement();
}
