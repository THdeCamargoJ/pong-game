#include <raylib.h>
#include "paddle.h"

void Paddle::Draw() {
    DrawRectangle(x, y, width, height, WHITE);
}

void Paddle::Move() {
    if (IsKeyDown(KEY_UP)) {
        y -= speed;
    } else if (IsKeyDown(KEY_DOWN)) {
        y += speed;
    }

    if (y <= 0) {
        y = 0;
    } else if (y + height >= GetScreenHeight()) {
        y = GetScreenHeight() - height;
    }
}