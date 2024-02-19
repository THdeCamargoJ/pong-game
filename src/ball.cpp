#include <raylib.h>
#include "ball.h"

void Ball::Draw() {
    DrawCircle(Ball::x, Ball::y, Ball::radius, WHITE);
}

void Ball::Move() {
    Ball::x += Ball::x_speed;
    Ball::y += Ball::y_speed;
}
