#include <raylib.h>
#include "ball.h"

void Ball::Draw() {
    DrawCircle(Ball::x, Ball::y, Ball::radius, WHITE);
}

void Ball::Move() {
    Ball::x += Ball::x_speed;
    Ball::y += Ball::y_speed;

    if (Ball::y + Ball::radius >= GetScreenHeight() || Ball::y - Ball::radius <= 0) {
        Ball::y_speed *= -1;
    } else if (Ball::x + Ball::radius >= GetScreenWidth() || Ball::x - Ball::radius <= 0) {
        Ball::x_speed *= -1;
    }
}
