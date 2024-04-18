#include "Drug1.h"
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

Drug1::Drug1() 

        // : 

		// footstepSound("Single-footstep-in-grass-A-www.fesliyanstudios.com.mp3"),
		// landingSound("Single-footstep-in-grass-B-www.fesliyanstudios.com.mp3") 
        
    {

	isRevived = false;

	isMain = false;
	
    drug_1 = LoadTexture("characters/drug1_revive.png");
	// car = LoadTexture("Car_1_01.png");

	// map = LoadTiled("desert.json"); 

	// LoadTMXMap("resources/desert.tmx");

	// numFrames = 6;

	drug_1_hori_frames = 6;
    drug_1_vert_frames = 1;

	// frameWidth = texture.width / numFrames;

	drug_1_frame_width = drug_1.width / drug_1_hori_frames;
    drug_1_frame_height = drug_1.height / drug_1_vert_frames;
	// std::cout << main_hero_frame_width << " " << main_hero_frame_height << "allah \n";
	
	// frameIndex = 0;
	frame_counter_hori = 5;
    frame_counter_vert = 0;

	// frameRect = {0.0f, 0.0f, (float)frameWidth, (float)texture.height};
    Rectangle drug_1_frame = {5.0f * (float)drug_1_frame_width, 0.0f, (float)drug_1_frame_width, (float)drug_1_frame_height};

	frameDelay = 3;
	frameDelayCounter = 0;

	walkSpeed = 2;

	// jumpSpeed = 2 * walkSpeed;
	
	// isOnGround = true;
}
	
Drug1::~Drug1() {
	UnloadTexture(drug_1);

	// UnloadMap(map);
	// UnloadTexture(car);

	// UnloadTMX(map);
}
	
bool Drug1::update() {
			
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
			frame_counter_hori %= drug_1_hori_frames;
			drug_1_frame.x = (float)drug_1_frame_width * frame_counter_hori;

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
	
void Drug1::draw() {
	// std::cout << "hello";
	Vector2 ulPosition = getUpperLeftPosition();

	// std::cout << "here - " << map.height << " " << map.width << " " << map.tileWidth << " " << map.tileHeight << "\n";
	

	// DrawTiled(map, 0, 0, WHITE);

	drug_1_frame.width = drug_1_frame_width;
	drug_1_frame.height = drug_1_frame_height;

	if (isRevived == false){
		DrawTextureRec(drug_1, drug_1_frame, ulPosition, RED);
	}

	else if (isRevived == true){
		DrawTextureRec(drug_1, drug_1_frame, ulPosition, WHITE);
	}

	else {
		DrawText("error bhai for drug1", 50, 50, 40, RED);
	}

	// DrawTexture(car, 0, 0, RED);

}
	
Rectangle Drug1::getBoundingBox() {
	
    Vector2 ulPosition = getUpperLeftPosition();
	return {ulPosition.x, ulPosition.y, (float)drug_1_frame_width, (float)drug_1_frame_height};
}
	
void Drug1::goUp() {

	velocity.x = 0;
	velocity.y = -walkSpeed;
}

void Drug1::goDown() {

	velocity.x = 0;
	velocity.y = +walkSpeed;
}
	
void Drug1::goLeft() {

	velocity.y = 0;
	velocity.x = -walkSpeed;
}
	
void Drug1::goRight() {

	velocity.y = 0;
	velocity.x = +walkSpeed;
}

void Drug1::goNowhere() {

		velocity.x = 0;
		velocity.y = 0;
}
	
void Drug1::doInteractWith() {
}

Vector2 Drug1::getUpperLeftPosition() {
	return {position.x - drug_1_frame_width / 2, position.y};
}
