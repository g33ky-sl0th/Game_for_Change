#include "raylib.h"
#include <iostream>

using namespace std;

int main() {
    const int screenWidth = 800;
    const int screenHeight = 640;

    InitWindow(screenWidth, screenHeight, "Camera Focus Example");
    Image mapImage = LoadImage("damn2.png");
    Texture2D mapTexture = LoadTextureFromImage(mapImage);

    Vector2 characterPosition = { 50.0f, 50.0f};
    Camera2D camera = { 0 };
    camera.target = characterPosition;
    camera.offset = (Vector2){ screenWidth / 2.0f, screenHeight / 2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_RIGHT)) {
            Color c1= GetImageColor(mapImage,characterPosition.x+100.0f*GetFrameTime(),characterPosition.y);
            if (c1.r == 35 && c1.g == 35 && c1.b ==45 && c1.a ==255) {
            characterPosition.x += 100.0f * GetFrameTime(); 
        }
        }
        if (IsKeyDown(KEY_LEFT)) {
            Color c2= GetImageColor(mapImage,characterPosition.x-100.0f*GetFrameTime(),characterPosition.y);
            if (c2.r == 35 && c2.g == 35 && c2.b ==45 && c2.a ==255) {
            characterPosition.x -= 100.0f * GetFrameTime(); 
        }
        }
        if (IsKeyDown(KEY_UP)) {
            Color c3= GetImageColor(mapImage,characterPosition.x,characterPosition.y -100.0f*GetFrameTime());
                if (c3.r == 35 && c3.g == 35 && c3.b ==45 && c3.a ==255) {
            characterPosition.y -= 100.0f * GetFrameTime(); 
        }
        }
        if (IsKeyDown(KEY_DOWN)) {
            Color c4= GetImageColor(mapImage,characterPosition.x,characterPosition.y +100.0f*GetFrameTime());
                if (c4.r == 35 && c4.g == 35 && c4.b ==45 && c4.a ==255) {
            characterPosition.y += 100.0f * GetFrameTime(); 
        }
        }

        camera.offset.x = screenWidth /2.0f - characterPosition.x;
        camera.offset.y = screenHeight / 2.0f - characterPosition.y;

        BeginDrawing();
        BeginMode2D(camera);

        ClearBackground(RAYWHITE);

        DrawTexture(mapTexture, 0, 0, WHITE);
        DrawCircleV(characterPosition, 3, RED);

        EndMode2D();
        EndDrawing();
    }

    UnloadTexture(mapTexture);
    CloseWindow();

    return 0;
}