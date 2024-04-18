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

	isMain = false;
	
    drug_1 = LoadTexture("main_hero_movt.png");
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

	// frameRect = {0.0f, 0.0f, (float)frameWidth, (float)texture.height};
    Rectangle drug_1_frame = {0.0f, 0.0f, (float)drug_1_frame_width, (float)drug_1_frame_height};


	frameDelay = 3;
	frameDelayCounter = 0;

	// frameIndex = 0;
	frame_counter_hori = 0;
    frame_counter_vert = 0;

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
			++frame_counter_hori;
			frame_counter_hori %= drug_1_hori_frames;
			drug_1_frame.x = (float)drug_1_frame_width * frame_counter_hori;

			if (velocity.y < 0){

				// std::cout << "up\n";

				frame_counter_vert = 0;
                drug_1_frame.y = (float)frame_counter_vert * drug_1_frame_height;
			}

			else if (velocity.y > 0){

				// std::cout << "down\n";

				frame_counter_vert = 2;
                drug_1_frame.y = (float)frame_counter_vert * drug_1_frame_height;
			}

			else if (velocity.x < 0){	// left

				// std::cout << "left\n";

				frame_counter_vert = 1; 
                drug_1_frame.y = (float)frame_counter_vert * drug_1_frame_height;
			}

			else if (velocity.x > 0){	// right

				// std::cout << "right\n";

				frame_counter_vert = 3;             
                drug_1_frame.y = (float)frame_counter_vert * drug_1_frame_height;
			}

			// if(isOnGround) {

			// 	++frameIndex;
			// 	frameIndex %= numFrames;
				
			// 	// if(isFootstepFrame(frameIndex)) {
			// 	// 	PlaySound(footstepSound);
			// 	// }
			// } 
			
			// else {

			// 	if(velocity.y < 0) {
			// 		frameIndex = jumpUpFrame;
			// 	} else {
			// 		frameIndex = jumpDownFrame;
			// 	}
			// }


			// frameRect.x = (float) frameWidth * frameIndex;

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



	DrawTextureRec(drug_1, drug_1_frame, ulPosition, WHITE);
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
