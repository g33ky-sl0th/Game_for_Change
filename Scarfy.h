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
	
	virtual bool update(bool onGround);
	
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
	
private:
	/** Calculates the position of this object's upper-left corner.
	 */
	Vector2 getUpperLeftPosition();

	Texture2D main_hero;

	// Animation state
	// unsigned numFrames;

	unsigned main_hero_hori_frames = 9;
    unsigned main_hero_vert_frames = 4;

	// int frameWidth;
	int main_hero_frame_width;
	int main_hero_frame_height;


	unsigned frameDelay;
	unsigned frameDelayCounter;
	unsigned frameIndex;
	
    // Rectangle frameRect;
    Rectangle main_hero_frame = {0.0f, 0.0f, (float)main_hero.width/main_hero_hori_frames, (float)main_hero.height/main_hero_vert_frames};

	
	float jumpSpeed;
	float walkSpeed;
	
	bool isOnGround;
};