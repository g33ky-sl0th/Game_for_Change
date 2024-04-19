#include "Scarfy.h"
#include "raymath.h"

// #include "pugixml.hpp"
// #include "pugiconfig.hpp"

#define RAYLIB_TILESON_IMPLEMENTATION
#include "raylib-tileson.h"


#include<iostream>

// static const int jumpUpFrame = 3;
// static const int jumpDownFrame = 4;
// static const int footstepFrame1 = 1;
// static const int footstepFrame2 = 4;

// static bool isFootstepFrame(int frameIndex) {
	
// 	if(frameIndex == footstepFrame1 || frameIndex == footstepFrame2) {
// 		return true;
// 	} else {
// 		return false;
// 	}
// }

Scarfy::Scarfy() 

        // : 

		// footstepSound("Single-footstep-in-grass-A-www.fesliyanstudios.com.mp3"),
		// landingSound("Single-footstep-in-grass-B-www.fesliyanstudios.com.mp3") 
        
    {

	int sceneWidth = GetScreenWidth();
	int sceneHeight = GetScreenHeight();

	screen_camera.target = {position.x, position.y};
	screen_camera.offset = { sceneWidth / 2.0f, sceneHeight / 2.0f };
    screen_camera.rotation = 0.0f;
    screen_camera.zoom = 1.5f;

	isMain = true;
	isFpressed = false;
	
    main_hero = LoadTexture("main_hero_movt.png");
	// car = LoadTexture("Car_1_01.png");

	mapImage = LoadImage("IITD-map2.png");
	mapTexture = LoadTextureFromImage(mapImage);


	// map = LoadTiled("desert.json"); 

	// LoadTMXMap("resources/desert.tmx");

	// numFrames = 6;

	main_hero_hori_frames = 9;
    main_hero_vert_frames = 4;

	// frameWidth = texture.width / numFrames;

	main_hero_frame_width = main_hero.width / main_hero_hori_frames;
    main_hero_frame_height = main_hero.height / main_hero_vert_frames;
	// std::cout << main_hero_frame_width << " " << main_hero_frame_height << "allah \n";

	// frameRect = {0.0f, 0.0f, (float)frameWidth, (float)texture.height};
    main_hero_frame = {0.0f, 0.0f, (float)main_hero_frame_width, (float)main_hero_frame_height};


	frameDelay = 5;
	frameDelayCounter = 0;

	// frameIndex = 0;
	frame_counter_hori = 0;
    frame_counter_vert = 0;

	walkSpeed = 6;

	// jumpSpeed = 2 * walkSpeed;
	
	// isOnGround = true;

	InitAudioDevice();
    backgroundMusic = LoadMusicStream("bgm-game2.mp3");
    PlayMusicStream(backgroundMusic);
}
	
Scarfy::~Scarfy() {

	UnloadTexture(main_hero);
	UnloadTexture(mapTexture);

	UnloadMusicStream(backgroundMusic);
    CloseAudioDevice();

	// UnloadMap(map);
	// UnloadTexture(car);
	// UnloadTMX(map);
}
	
bool Scarfy::update() {

	UpdateMusicStream(backgroundMusic);

	bool b1 = velocity.x == 0.0f;
	bool b2 = velocity.y == 0.0f;

	bool scarfyMoving = !(b1 && b2);
			
	// bool wasOnGround = isOnGround;
	// isOnGround = onGround;
	
	// if(isOnGround && !wasOnGround) {
	// 	PlaySound(landingSound);
	// }
	
	++frameDelayCounter;

	if(frameDelayCounter > frameDelay) {

		frameDelayCounter = 0;
		
		if(scarfyMoving) {

			// std::cout << "hi84";

			screen_camera.target = position;

			++frame_counter_hori;
			frame_counter_hori %= main_hero_hori_frames;
			main_hero_frame.x = (float)main_hero_frame_width * frame_counter_hori;

			if (velocity.y < 0){

				// std::cout << "up\n";

				frame_counter_vert = 0;
                main_hero_frame.y = (float)frame_counter_vert * main_hero_frame_height;
			}

			else if (velocity.y > 0){

				// std::cout << "down\n";

				frame_counter_vert = 2;
                main_hero_frame.y = (float)frame_counter_vert * main_hero_frame_height;
			}

			else if (velocity.x < 0){	// left

				// std::cout << "left\n";

				frame_counter_vert = 1; 
                main_hero_frame.y = (float)frame_counter_vert * main_hero_frame_height;
			}

			else if (velocity.x > 0){	// right

				// std::cout << "right\n";

				frame_counter_vert = 3;             
                main_hero_frame.y = (float)frame_counter_vert * main_hero_frame_height;
			}

		}
	}
	
	return true;
}
	
void Scarfy::draw() {
	// std::cout << "hello";
	Vector2 ulPosition = getUpperLeftPosition();

	BeginMode2D(screen_camera);

	DrawTexture(mapTexture, 0, 0, WHITE);
	// DrawTiled(map, 0, 0, WHITE);

	// DrawCircle(850,500, 15.0f, RED);

	// std::cout << "x - " << position.x << " y : " << position.y << "\n";

	DrawTextureRec(main_hero, main_hero_frame, ulPosition, WHITE);
	// DrawTexture(car, 0, 0, RED);

	EndMode2D();

}
	
Rectangle Scarfy::getBoundingBox() {
	
    Vector2 ulPosition = getUpperLeftPosition();
	return {ulPosition.x, ulPosition.y, (float)main_hero_frame_width, (float)main_hero_frame_height};
}
	
void Scarfy::goUp() {

	Color c1 = GetImageColor(mapImage,position.x , position.y - walkSpeed);

	if ((c1.r == 35 && c1.g == 35 && c1.b ==45 && c1.a ==255) || (c1.r == 255 && c1.g == 255 && c1.b ==255 && c1.a ==255)) {

		velocity.x = 0;
		velocity.y = -walkSpeed;
	}


	else{

		velocity.x = 0;
		velocity.y = 0;
	}
}

void Scarfy::goDown() {

	Color c1 = GetImageColor(mapImage,position.x , position.y + walkSpeed);

	if ((c1.r == 35 && c1.g == 35 && c1.b ==45 && c1.a ==255) || (c1.r == 255 && c1.g == 255 && c1.b ==255 && c1.a ==255)){

		velocity.x = 0;
		velocity.y = +walkSpeed;
	}

	else{

		velocity.x = 0;
		velocity.y = 0;
	}

}
	
void Scarfy::goLeft() {

	Color c1 = GetImageColor(mapImage, position.x - walkSpeed, position.y);

	if ((c1.r == 35 && c1.g == 35 && c1.b ==45 && c1.a ==255) || (c1.r == 255 && c1.g == 255 && c1.b ==255 && c1.a ==255)){

		velocity.y = 0;
		velocity.x = -walkSpeed;
	}

	else{

		velocity.x = 0;
		velocity.y = 0;
	}
}
	
void Scarfy::goRight() {

	Color c1= GetImageColor(mapImage, position.x + walkSpeed, position.y);

	if ((c1.r == 35 && c1.g == 35 && c1.b ==45 && c1.a ==255) || (c1.r == 255 && c1.g == 255 && c1.b ==255 && c1.a ==255)) {

        velocity.y = 0;
		velocity.x = +walkSpeed;
    }

	else{

		velocity.x = 0;
		velocity.y = 0;
	}
}

void Scarfy::goNowhere() {

		velocity.x = 0;
		velocity.y = 0;
}
	
void Scarfy::doInteractWith_1() {
	isFpressed = true;
}

void Scarfy::doInteractWith_2() {
	isFpressed = false;
}

Vector2 Scarfy::getUpperLeftPosition() {
	return {position.x - main_hero_frame_width / 2, position.y};
}