#pragma once

#include "Actor.h"

#include <raylib.h>
#include <raymath.h>

/** Our scarfy character.
 */
class Scarfy : public Actor {
public:
	/** Create Scarfy.
	 */
	Scarfy();
	
	virtual ~Scarfy();
	
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
private:
	/** Calculates the position of this object's upper-left corner.
	 */

	Texture2D main_hero;
	Texture2D car;

	// Animation state
	// unsigned numFrames;

	int main_hero_hori_frames = 9;
    int main_hero_vert_frames = 4;

	// int frameWidth;
	int main_hero_frame_width;
	int main_hero_frame_height;


	unsigned frameDelay;
	unsigned frameDelayCounter;

	// unsigned frameIndex;
	unsigned int frame_counter_hori;
    unsigned int frame_counter_vert;
	
    // Rectangle frameRect;
    Rectangle main_hero_frame;

	
	// float jumpSpeed;
	
	float walkSpeed;
	
	// bool isOnGround;
};