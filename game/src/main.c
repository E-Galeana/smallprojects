#include "raylib.h"

void userMoves(int *keyX, int *keyY) {
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
        *keyX+= 3;
    }
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
        *keyX-= 3;
    }
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
        *keyY-= 3;
    }
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {
        *keyY+= 3;
    }
}

int main() {

    int circleX = 400, circleY = 400;
    
    InitWindow(800, 800, "My Window");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        // Event Handling
        userMoves(&circleX, &circleY);
        // Updating Positions

        // Draw to screen
        BeginDrawing();
        { 
            ClearBackground(WHITE);
            DrawCircle(circleX, circleY, 50, BLACK);
        }
        EndDrawing();        
    }

    CloseWindow();
    return 0;
}