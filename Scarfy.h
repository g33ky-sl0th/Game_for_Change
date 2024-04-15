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

	Texture2D texture;

	
	// Animation state
	unsigned numFrames;
	int frameWidth;
	unsigned frameDelay;
	unsigned frameDelayCounter;
	unsigned frameIndex;
	
    Rectangle frameRect;
	
	float jumpSpeed;
	float walkSpeed;
	
	bool isOnGround;
};