#include "cpu-paddle.h"


void CpuPaddle::Move(int ball_y) {
    if (y + height / 2 > ball_y) {
        y -= speed;
    } else if (y + height / 2 <= ball_y) {
        y += speed;
    }

    KeepMoveInsideBoundaries();
}