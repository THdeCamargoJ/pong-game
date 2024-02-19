#include <iostream>
#include <raylib.h>

using namespace std;

int main () {
    const int screen_width = 1280;
    const int screen_height = 800;

    const int screen_offset = 10;

    const int rectange_height = 120;
    const int rectange_width = 25;

    InitWindow(screen_width, screen_height, "My Pong Game");
    
    SetTargetFPS(60); // 60 fps - draws 60 frames per second

    while(WindowShouldClose() == false) {
        BeginDrawing();

        // ball
        DrawCircle(screen_width / 2, screen_height / 2, 20, WHITE);

        // first pad
        DrawRectangle(
            screen_offset,
            screen_height / 2 - rectange_height / 2,
            rectange_width,
            rectange_height,
            WHITE
        );

        // second pad
        DrawRectangle(
            screen_width - (rectange_width + screen_offset),
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