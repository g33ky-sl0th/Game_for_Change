#pragma once

#include "Actor.h"

#include <raylib.h>
#include <raymath.h>

#define RAYLIB_TILESON_IMPLEMENTATION
#include "raylib-tileson.h"

/** Our Drug4 character.
 */
class Drug4 : public Actor {
public:
	/** Create Drug4.
	 */
	Drug4();
	
	virtual ~Drug4();
	
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

	Texture2D drug_4;

	// tmx_map* map; 

	// Animation state
	// unsigned numFrames;

	int drug_4_hori_frames;
    int drug_4_vert_frames;

	// int frameWidth;
	int drug_4_frame_width;
	int drug_4_frame_height;


	unsigned frameDelay;
	unsigned frameDelayCounter;

	// unsigned frameIndex;
	unsigned int frame_counter_hori;
    unsigned int frame_counter_vert;
	
    // Rectangle frameRect;
    Rectangle drug_4_frame;

	
	// float jumpSpeed;
	
	float walkSpeed;

	
	
	// bool isOnGround;
};

