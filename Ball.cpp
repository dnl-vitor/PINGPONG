#include "Ball.h"
#include "Globals.h"

void Ball::Draw() {
    DrawCircle(x, y, radius, yellow);
}

void Ball::Update() {
    x += speed_x;
    y += speed_y;

    if (y + radius >= GetScreenHeight() || y - radius <= 0) {
        speed_y *= -1;
    }
    if (x + radius >= GetScreenWidth()) {
        player2_score++;
        ResetBall();
    }
    if (x - radius <= 0) {
        player1_score++;
        ResetBall();
    }
}

void Ball::ResetBall() {
    x = GetScreenWidth() / 2.0f;
    y = GetScreenHeight() / 2.0f;

    int speed_choices[2] = {-1, 1};
    speed_x *= speed_choices[GetRandomValue(0, 1)];
    speed_y *= speed_choices[GetRandomValue(0, 1)];
}
