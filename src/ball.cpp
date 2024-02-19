#include <raylib.h>
#include "ball.h"

void Ball::Draw() {
    DrawCircle(x, y, radius, WHITE);
}

void Ball::Move() {
    x += x_speed;
    y += y_speed;

    if (y + radius >= GetScreenHeight() || y - radius <= 0) {
        y_speed *= -1;
    } else if (x + Ball::radius >= GetScreenWidth() || x - radius <= 0) {
        x_speed *= -1;
    }
}

void Ball::ResetBall() {
    x = GetScreenWidth() / 2;
    y = GetScreenHeight() / 2;

    int speed_choices[2] = {1, -1};

    x_speed *= speed_choices[GetRandomValue(0, 1)];
    y_speed *= speed_choices[GetRandomValue(0, 1)];
}
