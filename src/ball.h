#ifndef BALL_H
#define BALL_H

class Ball {
    public:
        float x, y;
        int x_speed, y_speed;
        int radius;

        void Draw();

        void Move();
        
        void ResetBall();
};

#endif