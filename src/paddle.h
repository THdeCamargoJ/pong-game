#ifndef PADDLE_H
#define PADDLE_H

class Paddle {
    public:
        float x, y;
        float width, height;
        int speed;

        void Draw();

        void Move();

    protected:
        void KeepMoveInsideBoundaries();
};

#endif