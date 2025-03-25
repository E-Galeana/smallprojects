#include "raylib.h"
#include "player.h"

#define GRAVITY 3

struct Player player;

void initPlayer() {
    player.x = 400;
    player.y = 900;
    player.radius = 30;
    player.jumpSpeed = 0;
    player.isJumping = false;
}

void userMoves(int *keyX, int *keyY, int *gravity) {
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
        *keyX += 3;
    }
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
        *keyX -= 3;
    }
    if (IsKeyPressed(KEY_SPACE) && !player.isJumping) {
        player.jumpSpeed = -15.0f;
        player.isJumping = true;
    }
    if (IsKeyDown(KEY_SPACE) && player.isJumping && player.jumpSpeed > -15.0f) {
        player.jumpSpeed -= 1.0f;
    }
    player.y += (int)player.jumpSpeed;
}

void ballGravityBehavior(int *ball_bottom, int *height, int *gravity) {
    *ball_bottom = player.y + player.radius;
    
    // Ground collision
    if (*ball_bottom >= *height) {
        *gravity = 0;
        player.y = *height - player.radius;
        player.jumpSpeed = 0;
        player.isJumping = false;  // Reset jump state when landing
    } else {
        *gravity = GRAVITY;
        player.jumpSpeed += 0.5f;  // Gradually increase fall speed
    }
    
    player.y += *gravity;
}

int main() {

    initPlayer();
    int windowWidth = 800;
    int windowHeight = 1000;
    InitWindow(windowWidth, windowHeight, "My Window");
    SetTargetFPS(60);

    int ballHitBox;
    int gravity = GRAVITY;

    while (!WindowShouldClose()) {

        // Event Handling
        userMoves(&player.x, &player.y, &gravity);
        // Updating Positions

        // Draw to screen
        BeginDrawing();
        { 
            ballGravityBehavior(&ballHitBox, &windowHeight, &gravity);
            ClearBackground(WHITE);
            DrawCircle(player.x, player.y, player.radius, BLACK);
        }
        EndDrawing();        
    }

    CloseWindow();
    return 0;
}