#include <iostream>
#include <raylib.h>

using namespace std;

int main () {
    const int screen_width = 1280;
    const int screen_height = 800;

    InitWindow(screen_width, screen_height, "My Pong Game");
    
    SetTargetFPS(60); // 60 fps - draws 60 frames per second

    while(WindowShouldClose() == false) {
        BeginDrawing();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}