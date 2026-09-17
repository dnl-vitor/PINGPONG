#pragma once
#include <raylib.h>

class Paddle {
protected:
    void LimitMovement();

public:
    float x, y;
    float width, height;
    int speed;

    void Draw();
    void Update();
};

class Player2 : public Paddle {
public:
    void Update();
};
