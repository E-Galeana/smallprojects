#include "raylib.h"

int main() {
    InitWindow(800, 600, "My Window");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        { 
            ClearBackground(WHITE);

            DrawText("Hello World", 10, 10, 10, BLACK);

        }
        EndDrawing();        
    }

    CloseWindow();
    return 0;
}