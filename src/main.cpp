#include <iostream>
#include <raylib.h>
#include "ball.h"
#include "paddle.h"
#include "cpu-paddle.h"

using namespace std;

int main () {
    const int screen_width = 1280;
    const int screen_height = 800;

    const int screen_offset = 10;

    int player_score = 0;
    int cpu_score = 0;

    Ball ball;
    Paddle player;
    CpuPaddle cpu;

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

    cpu.width = 25;
    cpu.height = 120;
    cpu.x = screen_offset;
    cpu.y = screen_height / 2 - cpu.height / 2;
    cpu.speed = 6;

    InitWindow(screen_width, screen_height, "My Pong Game");
    
    SetTargetFPS(60); // 60 fps - draws 60 frames per second

    while(WindowShouldClose() == false) {
        BeginDrawing();

        ClearBackground(BLACK);

        ball.Draw();
        ball.Move();

        player.Draw();
        player.Move();

        cpu.Draw();
        cpu.Move(ball.y);

        if (
            CheckCollisionCircleRec(
                Vector2{ball.x, ball.y}, ball.radius,
                Rectangle{
                    player.x,
                    player.y,
                    player.width,
                    player.height
            }) || CheckCollisionCircleRec(
                Vector2{ball.x, ball.y}, ball.radius,
                Rectangle{
                    cpu.x,
                    cpu.y,
                    cpu.width,
                    cpu.height
            })
        ) {
            ball.x_speed *= -1;
        }

        if (ball.x + ball.radius >= screen_width) {
            cpu_score += 1;
            ball.ResetBall();
        } else if (ball.x - ball.radius <= 0) {
            player_score += 1;
            ball.ResetBall();
        }

        DrawText(TextFormat("%i", cpu_score), screen_width / 4 - 20, 20, 80, WHITE);
        DrawText(TextFormat("%i", player_score), 3 * screen_width / 4 - 20, 20, 80, WHITE);

        // middle line: separates left player from right player fields
        DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
