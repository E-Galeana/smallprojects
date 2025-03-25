#include <stdlib.h>
#include <stdio.h>
#include "raylib.h"



#define GRAVITY 3
#define WINWIDTH 1216
#define WINHEIGHT 384

    /*  Structs  */
struct Player player;
struct Window window;

struct Player
{
    int x;
    int y;
    int radius;
    float jumpSpeed;
    bool isJumping;
};   

struct Window {
    int height;
    int width;
};

    /*  Inits  */
void initPlayer() {
    player.x = 400;
    player.y = 900;
    player.radius = 30;
    player.jumpSpeed = 0;
    player.isJumping = false;
}

void setWindowSize() {
    window.width = WINWIDTH;
    window.height = WINHEIGHT;
    InitWindow(window.width, window.height, "My Window");
}

    /*  Object Behavior  */
void userMoves(int *keyX, int *keyY, int *gravity) {

    // Controls right and left movement
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
        *keyX += 3;
    }
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
        *keyX -= 3;
    }
    // Controls jumping behavior
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

    /*  Background  */
void scrollBackground(Texture2D background, float *scrollingBack) {
    *scrollingBack -= 2.0f;

    // Reset the scroll position when first background moves fully off screen
    if (*scrollingBack <= -background.width) { 
        *scrollingBack = 0;
    }

    // Draw the two backgrounds side by side for seamless scrolling
    DrawTextureEx(background, (Vector2){ *scrollingBack, 20 }, 0.0f, 2.0f, WHITE);
    DrawTextureEx(background, (Vector2){ *scrollingBack + background.width, 20 }, 0.0f, 2.0f, WHITE); 
}

int main() {

    initPlayer();
    setWindowSize();
    SetTargetFPS(60);

    int ballHitBox, gravity = GRAVITY, winheight = WINHEIGHT;
    const char* filePath = "game/src/cyberpunk-street.png";
    Texture2D background = LoadTexture(filePath);
    float scrollingBack = 0.0f;

    if(!IsTextureValid(background)) {
        printf("Failed to load background");
        CloseWindow();
        return 1;
    }

    while (!WindowShouldClose()) {

        // Event Handling
        userMoves(&player.x, &player.y, &gravity);
        

        // Draw to screen
        BeginDrawing();
        { 
            ClearBackground(WHITE);
            ballGravityBehavior(&ballHitBox, &winheight, &gravity);
            scrollBackground(background, &scrollingBack);
            DrawCircle(player.x, player.y, player.radius, RED);
        }
        EndDrawing();        
    }
    UnloadTexture(background);
    CloseWindow();
    return 0;
}