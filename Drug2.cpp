#include "Drug2.h"
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

Drug2::Drug2() 

        // : 

		// footstepSound("Single-footstep-in-grass-A-www.fesliyanstudios.com.mp3"),
		// landingSound("Single-footstep-in-grass-B-www.fesliyanstudios.com.mp3") 
        
    {

	isRevived = false;

	isMain = false;
	
    drug_2 = LoadTexture("characters/drug2_revive.png");
	// car = LoadTexture("Car_1_01.png");

	// map = LoadTiled("desert.json"); 

	// LoadTMXMap("resources/desert.tmx");

	// numFrames = 6;

	drug_2_hori_frames = 6;
    drug_2_vert_frames = 1;

	// frameWidth = texture.width / numFrames;

	drug_2_frame_width = drug_2.width / drug_2_hori_frames;
    drug_2_frame_height = drug_2.height / drug_2_vert_frames;
	// std::cout << main_hero_frame_width << " " << main_hero_frame_height << "allah \n";
	
	// frameIndex = 0;
	frame_counter_hori = 5;
    frame_counter_vert = 0;

	float init_width_loc = 5.0f * drug_2_frame_width;

	// frameRect = {0.0f, 0.0f, (float)frameWidth, (float)texture.height};
    drug_2_frame = {320.0f , 0.0f, (float)drug_2_frame_width, (float)drug_2_frame_height};

	frameDelay = 8;
	frameDelayCounter = 0;

	walkSpeed = 2;

	// jumpSpeed = 2 * walkSpeed;
	
	// isOnGround = true;
}
	
Drug2::~Drug2() {
	UnloadTexture(drug_2);

	// UnloadMap(map);
	// UnloadTexture(car);

	// UnloadTMX(map);
}
	
bool Drug2::update() {
			
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
			frame_counter_hori %= drug_2_hori_frames;
			drug_2_frame.x = (float)drug_2_frame_width * frame_counter_hori;

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
	
void Drug2::draw() {
	// std::cout << "hello";
	Vector2 ulPosition = getUpperLeftPosition();

	// std::cout << "here - " << map.height << " " << map.width << " " << map.tileWidth << " " << map.tileHeight << "\n";
	

	// DrawTiled(map, 0, 0, WHITE);

	drug_2_frame.width = drug_2_frame_width;
	drug_2_frame.height = drug_2_frame_height;

	if (isRevived == false){
		DrawTextureRec(drug_2, drug_2_frame, ulPosition, RED);
	}

	else if (isRevived == true){
		DrawTextureRec(drug_2, drug_2_frame, ulPosition, WHITE);
	}

	else {
		DrawText("error bhai for Drug2", 50, 50, 40, RED);
	}

	// DrawTexture(car, 0, 0, RED);

}
	
Rectangle Drug2::getBoundingBox() {
	
    Vector2 ulPosition = getUpperLeftPosition();
	return {ulPosition.x, ulPosition.y, (float)drug_2_frame_width, (float)drug_2_frame_height};
}
	
void Drug2::goUp() {

	velocity.x = 0;
	velocity.y = -walkSpeed;
}

void Drug2::goDown() {

	velocity.x = 0;
	velocity.y = +walkSpeed;
}
	
void Drug2::goLeft() {

	velocity.y = 0;
	velocity.x = -walkSpeed;
}
	
void Drug2::goRight() {

	velocity.y = 0;
	velocity.x = +walkSpeed;
}

void Drug2::goNowhere() {

		velocity.x = 0;
		velocity.y = 0;
}
	
void Drug2::doInteractWith() {
}

Vector2 Drug2::getUpperLeftPosition() {
	return {position.x - drug_2_frame_width / 2, position.y};
}

