#pragma once

#include "Actor.h"

#include <raylib.h>
#include <raymath.h>

#define RAYLIB_TILESON_IMPLEMENTATION
#include "raylib-tileson.h"

/** Our Drug2 character.
 */
class Drug2 : public Actor {
public:
	/** Create Drug2.
	 */
	Drug2();
	
	virtual ~Drug2();
	
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

	Texture2D drug_2;

	// tmx_map* map; 

	// Animation state
	// unsigned numFrames;

	int drug_2_hori_frames;
    int drug_2_vert_frames;

	// int frameWidth;
	int drug_2_frame_width;
	int drug_2_frame_height;


	unsigned frameDelay;
	unsigned frameDelayCounter;

	// unsigned frameIndex;
	unsigned int frame_counter_hori;
    unsigned int frame_counter_vert;
	
    // Rectangle frameRect;
    Rectangle drug_2_frame;

	
	// float jumpSpeed;
	
	float walkSpeed;

	
	
	// bool isOnGround;
};
