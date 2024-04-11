#include <raylib.h>
#include <raymath.h>
#include <iostream>

int main() 
{
    int game_window_width = 1600;
    int game_window_height = 900;

    const int main_hero_speed = 4;

    Color green = {20, 160, 133, 200};

    InitWindow(game_window_width, game_window_height, "GTA : IIT-Delhi");

    Texture2D grass_background = LoadTexture("Car_1_01.png");

    int main_hero_hori_frames = 9;
    int main_hero_vert_frames = 4;

    Texture2D main_hero = LoadTexture("characters/main_hero_movt.png");

    int main_hero_frame_width = main_hero.width / main_hero_hori_frames;
    int main_hero_frame_height = main_hero.height / main_hero_vert_frames;

    Rectangle main_hero_frame = {0.0f, 0.0f, (float)main_hero.width/main_hero_hori_frames, (float)main_hero.height/main_hero_vert_frames};

    Vector2 main_hero_init_pos = {game_window_width/2.0f, game_window_height/2.0f}; 

    bool main_hero_moving = false;

    int frame_delay = 3;
    unsigned int frame_delay_counter = 0;

    unsigned int frame_counter_hori = 0;
    unsigned int frame_counter_vert = 0;

    //camera2D
    Camera2D camera = { 0 };
    camera.target = main_hero_init_pos;
    camera.offset = (Vector2){ game_window_width/2.0f, game_window_height/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    SetTargetFPS(60);

    //Game Loop
    while(WindowShouldClose() == false) 
    {

        if (IsKeyDown(KEY_LEFT) == true && IsKeyDown(KEY_UP) == true){

            main_hero_moving = true;
            ++frame_delay_counter;

            if (frame_delay_counter > frame_delay){

                main_hero_init_pos = Vector2Add(main_hero_init_pos, {-3.0f, -3.0f});

                frame_delay_counter = 0;

                if (main_hero_moving){

                    camera.target = main_hero_init_pos;

                    frame_counter_vert = 1;
                    ++frame_counter_hori;
                    frame_counter_hori %= main_hero_hori_frames;
                    main_hero_frame.y = (float)frame_counter_vert * main_hero_frame_height;
                    main_hero_frame.x = (float)main_hero_frame_width * frame_counter_hori;
                }
            }
        }

        else if (IsKeyDown(KEY_LEFT) == true && IsKeyDown(KEY_DOWN) == true){

            main_hero_moving = true;
            ++frame_delay_counter;

            if (frame_delay_counter > frame_delay){

                main_hero_init_pos = Vector2Add(main_hero_init_pos, {-3.0f, 3.0f});

                frame_delay_counter = 0;

                if (main_hero_moving){

                    camera.target = main_hero_init_pos;

                    frame_counter_vert = 1;
                    ++frame_counter_hori;
                    frame_counter_hori %= main_hero_hori_frames;
                    main_hero_frame.y = (float)frame_counter_vert * main_hero_frame_height;
                    main_hero_frame.x = (float)main_hero_frame_width * frame_counter_hori;
                }
            }
        }

         else if (IsKeyDown(KEY_RIGHT) == true && IsKeyDown(KEY_UP) == true){

            main_hero_moving = true;
            ++frame_delay_counter;

            if (frame_delay_counter > frame_delay){

                main_hero_init_pos = Vector2Add(main_hero_init_pos, {3.0f, -3.0f});

                frame_delay_counter = 0;

                if (main_hero_moving){

                    camera.target = main_hero_init_pos;

                    frame_counter_vert = 3;
                    ++frame_counter_hori;
                    frame_counter_hori %= main_hero_hori_frames;
                    main_hero_frame.y = (float)frame_counter_vert * main_hero_frame_height;
                    main_hero_frame.x = (float)main_hero_frame_width * frame_counter_hori;
                }
            }
        }

        else if(IsKeyDown(KEY_RIGHT) == true && IsKeyDown(KEY_DOWN) == true) {

            main_hero_moving = true;
            ++frame_delay_counter;

            if (frame_delay_counter > frame_delay){

                main_hero_init_pos = Vector2Add(main_hero_init_pos, {3.0f, 3.0f});

                frame_delay_counter = 0;

                if (main_hero_moving){

                    camera.target = main_hero_init_pos;

                    frame_counter_vert = 3;
                    ++frame_counter_hori;
                    frame_counter_hori %= main_hero_hori_frames;
                    main_hero_frame.y = (float)frame_counter_vert * main_hero_frame_height;
                    main_hero_frame.x = (float)main_hero_frame_width * frame_counter_hori;
                }
            }
        }
      
        else if (IsKeyDown(KEY_UP) == true){

            main_hero_moving = true;
            ++frame_delay_counter;
            

            if (frame_delay_counter > frame_delay){

                main_hero_init_pos = Vector2Add(main_hero_init_pos, {0.0f, -3.0f});

                frame_delay_counter = 0;

                if (main_hero_moving){

                    camera.target = main_hero_init_pos;

                    frame_counter_vert = 0;
                    ++frame_counter_hori;
                    frame_counter_hori %= main_hero_hori_frames;
                    main_hero_frame.y = (float)frame_counter_vert * main_hero_frame_height;
                    main_hero_frame.x = (float)main_hero_frame_width * frame_counter_hori;
                }
            }

        }

        else if (IsKeyDown(KEY_LEFT) == true ){

            main_hero_moving = true;
            ++frame_delay_counter;

            if (frame_delay_counter > frame_delay){

                main_hero_init_pos = Vector2Add(main_hero_init_pos, {-3.0f, 0.0f});

                frame_delay_counter = 0;

                if (main_hero_moving){

                    camera.target = main_hero_init_pos;

                    frame_counter_vert = 1;
                    ++frame_counter_hori;
                    frame_counter_hori %= main_hero_hori_frames;
                    main_hero_frame.y = (float)frame_counter_vert * main_hero_frame_height;
                    main_hero_frame.x = (float)main_hero_frame_width * frame_counter_hori;
                }
            }
        }

        else if (IsKeyDown(KEY_RIGHT) == true ){

            main_hero_moving = true;
            ++frame_delay_counter;

            if (frame_delay_counter > frame_delay){

                main_hero_init_pos = Vector2Add(main_hero_init_pos, {3.0f, 0.0f});

                frame_delay_counter = 0;

                if (main_hero_moving){

                    camera.target = main_hero_init_pos;

                    frame_counter_vert = 3;
                    ++frame_counter_hori;
                    frame_counter_hori %= main_hero_hori_frames;
                    main_hero_frame.y = (float)frame_counter_vert * main_hero_frame_height;
                    main_hero_frame.x = (float)main_hero_frame_width * frame_counter_hori;
                }
            }
        }

        else if (IsKeyDown(KEY_DOWN) == true){

            main_hero_moving = true;
            ++frame_delay_counter;

            if (frame_delay_counter > frame_delay){

                main_hero_init_pos = Vector2Add(main_hero_init_pos, {0.0f, 3.0f});

                frame_delay_counter = 0;

                if (main_hero_moving){

                    camera.target = main_hero_init_pos;

                    frame_counter_vert = 2;
                    ++frame_counter_hori;
                    frame_counter_hori %= main_hero_hori_frames;
                    main_hero_frame.y = (float)frame_counter_vert * main_hero_frame_height;
                    main_hero_frame.x = (float)main_hero_frame_width * frame_counter_hori;
                }
            }
        }

        else{
            main_hero_moving = false;   
        }


        // 2. Updating Positions

       



        // 3. Drawing
        BeginDrawing();

        ClearBackground(green);

        BeginMode2D(camera);

            DrawTexture(grass_background, 0, 0, WHITE); // Draw the grass background texture at position (0, 0)
            DrawTextureRec(main_hero, main_hero_frame, main_hero_init_pos, WHITE);
        
        EndMode2D();

        EndDrawing();
    }

    UnloadTexture(main_hero);
    UnloadTexture(grass_background);
    CloseWindow();
    return 0;
}