#include <iostream>
#include <raylib.h>
#include "ball.h"
#include "paddle.h"

using namespace std;

int main () {
    const int screen_width = 1280;
    const int screen_height = 800;

    const int screen_offset = 10;

    const int rectange_height = 120;
    const int rectange_width = 25;

    Ball ball;
    Paddle player;

    ball.radius = 20;
    ball.x = screen_width/2;
    ball.y = screen_height/2;
    ball.x_speed = 7;
    ball.y_speed = 7;

    player.width = 25;
    player.height = 120;
    player.x = screen_width - (player.width + screen_offset);
    player.y = screen_height / 2 - player.height / 2;
    player.speed = 6;

    InitWindow(screen_width, screen_height, "My Pong Game");
    
    SetTargetFPS(60); // 60 fps - draws 60 frames per second

    while(WindowShouldClose() == false) {
        BeginDrawing();

        ClearBackground(BLACK);

        ball.Draw();
        ball.Move();

        player.Draw();
        player.Move();

        // first pad
        DrawRectangle(
            screen_offset,
            screen_height / 2 - rectange_height / 2,
            rectange_width,
            rectange_height,
            WHITE
        );

        // middle line: separates left player from right player fields
        DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}