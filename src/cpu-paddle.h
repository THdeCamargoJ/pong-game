#ifndef CPU_PADDLE_H
#define CPU_PADDLE_H

#include "paddle.h"

class CpuPaddle: public Paddle{
    public:
        void Move(int ball_y);
};

#endif