#include "Drug5.h"
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

Drug5::Drug5() 

        // : 

		// footstepSound("Single-footstep-in-grass-A-www.fesliyanstudios.com.mp3"),
		// landingSound("Single-footstep-in-grass-B-www.fesliyanstudios.com.mp3") 
        
    {

    screen_camera = CommandListener::screen_camera;

	isRevived = false;

	isMain = false;
	
    drug_5 = LoadTexture("characters/drug5_revive.png");
	// car = LoadTexture("Car_1_01.png");

	// map = LoadTiled("desert.json"); 

	// LoadTMXMap("resources/desert.tmx");

	// numFrames = 6;

	drug_5_hori_frames = 6;
    drug_5_vert_frames = 1;

	// frameWidth = texture.width / numFrames;

	drug_5_frame_width = drug_5.width / drug_5_hori_frames;
    drug_5_frame_height = drug_5.height / drug_5_vert_frames;
	// std::cout << main_hero_frame_width << " " << main_hero_frame_height << "allah \n";
	
	// frameIndex = 0;
	frame_counter_hori = 5;
    frame_counter_vert = 0;

	float init_width_loc = 5.0f * drug_5_frame_width;

	// frameRect = {0.0f, 0.0f, (float)frameWidth, (float)texture.height};
    drug_5_frame = {320.0f , 0.0f, (float)drug_5_frame_width, (float)drug_5_frame_height};

	frameDelay = 8;
	frameDelayCounter = 0;

	walkSpeed = 2;

	// jumpSpeed = 2 * walkSpeed;
	
	// isOnGround = true;
}
	
Drug5::~Drug5() {
	UnloadTexture(drug_5);

	// UnloadMap(map);
	// UnloadTexture(car);

	// UnloadTMX(map);
}
	
bool Drug5::update() {
			
	// bool wasOnGround = isOnGround;
	// isOnGround = onGround;
	
	// if(isOnGround && !wasOnGround) {
	// 	PlaySound(landingSound);
	// }
	
	++frameDelayCounter;

	if(frameDelayCounter > frameDelay) {

		frameDelayCounter = 0;

		// std::cout << "hi84";

		if (isRevived == false){

			--frame_counter_hori;
			frame_counter_hori %= drug_5_hori_frames;
			drug_5_frame.x = (float)drug_5_frame_width * frame_counter_hori;

			if (frame_counter_hori == 0){
				isRevived = true;
			}
		}

		else if (isRevived == true){

			DrawText("Already revived sirji", 50, 50, 20, GREEN);
		}

	}
	
	return true;
}
	
void Drug5::draw() {
	// std::cout << "hello";
	Vector2 ulPosition = getUpperLeftPosition();

    BeginMode2D(screen_camera);

	// std::cout << "here - " << map.height << " " << map.width << " " << map.tileWidth << " " << map.tileHeight << "\n";
	

	// DrawTiled(map, 0, 0, WHITE);

	drug_5_frame.width = drug_5_frame_width;
	drug_5_frame.height = drug_5_frame_height;

	if (isRevived == false){
		DrawTextureRec(drug_5, drug_5_frame, ulPosition, RED);
	}

	else if (isRevived == true){
		DrawTextureRec(drug_5, drug_5_frame, ulPosition, WHITE);
	}

	else {
		DrawText("error bhai for Drug5", 50, 50, 40, RED);
	}

	// DrawTexture(car, 0, 0, RED);

    EndMode2D();

}
	
Rectangle Drug5::getBoundingBox() {
	
    Vector2 ulPosition = getUpperLeftPosition();
	return {ulPosition.x, ulPosition.y, (float)drug_5_frame_width, (float)drug_5_frame_height};
}
	
void Drug5::goUp() {

	velocity.x = 0;
	velocity.y = -walkSpeed;
}

void Drug5::goDown() {

	velocity.x = 0;
	velocity.y = +walkSpeed;
}
	
void Drug5::goLeft() {

	velocity.y = 0;
	velocity.x = -walkSpeed;
}
	
void Drug5::goRight() {

	velocity.y = 0;
	velocity.x = +walkSpeed;
}

void Drug5::goNowhere() {

		velocity.x = 0;
		velocity.y = 0;
}
	
void Drug5::doInteractWith() {
}

Vector2 Drug5::getUpperLeftPosition() {
	return {position.x - drug_5_frame_width / 2, position.y};
}

