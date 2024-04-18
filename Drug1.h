#pragma once

#include "Actor.h"

#include <raylib.h>
#include <raymath.h>

#define RAYLIB_TILESON_IMPLEMENTATION
#include "raylib-tileson.h"

/** Our Drug1 character.
 */
class Drug1 : public Actor {
public:
	/** Create Drug1.
	 */
	Drug1();
	
	virtual ~Drug1();
	
	virtual bool update();
	
	virtual void draw();
	
	virtual Rectangle getBoundingBox();
	
	virtual void goUp();
	
	virtual void goLeft();
	
	virtual void goRight();
	
	virtual void goDown();
	
	virtual void goNowhere();
	
	/** Select, push, pull, punch, fire, etc.
	 */
	virtual void doInteractWith();
	
	Vector2 getUpperLeftPosition();

	// int tileSize = 64;


private:
	/** Calculates the position of this object's upper-left corner.
	 */

	Texture2D drug_1;

	// tmx_map* map; 

	// Animation state
	// unsigned numFrames;

	int drug_1_hori_frames;
    int drug_1_vert_frames;

	// int frameWidth;
	int drug_1_frame_width;
	int drug_1_frame_height;


	unsigned frameDelay;
	unsigned frameDelayCounter;

	// unsigned frameIndex;
	unsigned int frame_counter_hori;
    unsigned int frame_counter_vert;
	
    // Rectangle frameRect;
    Rectangle drug_1_frame;

	
	// float jumpSpeed;
	
	float walkSpeed;

	
	
	// bool isOnGround;
};
