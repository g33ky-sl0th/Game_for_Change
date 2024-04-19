#pragma once

#include "Actor.h"

#include <raylib.h>
#include <raymath.h>

#define RAYLIB_TILESON_IMPLEMENTATION
#include "raylib-tileson.h"

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
	virtual void doInteractWith_1();
	virtual void doInteractWith_2();
	
	Vector2 getUpperLeftPosition();

	Map map;

	// int tileSize = 64;

	int main_hero_frame_height;

	Texture2D mapTexture;
	Image mapImage;

private:
	/** Calculates the position of this object's upper-left corner.
	 */

	Texture2D main_hero;
	Texture2D car;

	// tmx_map* map; 

	// Animation state
	// unsigned numFrames;

	int main_hero_hori_frames = 9;
    int main_hero_vert_frames = 4;

	// int frameWidth;
	int main_hero_frame_width;


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