#include "Scarfy.h"
#include "raymath.h"


static const int jumpUpFrame = 3;
static const int jumpDownFrame = 4;
static const int footstepFrame1 = 1;
static const int footstepFrame2 = 4;

static bool isFootstepFrame(int frameIndex) {
	
	if(frameIndex == footstepFrame1 || frameIndex == footstepFrame2) {
		return true;
	} else {
		return false;
	}
}

Scarfy::Scarfy() 

        // : 

		// footstepSound("Single-footstep-in-grass-A-www.fesliyanstudios.com.mp3"),
		// landingSound("Single-footstep-in-grass-B-www.fesliyanstudios.com.mp3") 
        
    {
	
    texture = LoadTexture("scarfy.png"),
	
	numFrames = 6;
	frameWidth = texture.width / numFrames;
	frameRect = {0.0f, 0.0f, (float)frameWidth, (float)texture.height};
	
	frameDelay = 5;
	frameDelayCounter = 0;
	frameIndex = 0;
	
	walkSpeed = 10;
	jumpSpeed = 2 * walkSpeed;
	
	isOnGround = true;
}
	
Scarfy::~Scarfy() {
}
	
bool Scarfy::update(bool onGround) {

	bool b1 = velocity.x == 0.0f;
	bool b2 = velocity.y == 0.0f;

	bool scarfyMoving = b1 || b2;
			
	bool wasOnGround = isOnGround;
	isOnGround = onGround;
	
	// if(isOnGround && !wasOnGround) {
	// 	PlaySound(landingSound);
	// }
	
	++frameDelayCounter;
	if(frameDelayCounter > frameDelay) {
		frameDelayCounter = 0;
		
		if(scarfyMoving) {
			if(isOnGround) {
				++frameIndex;
				frameIndex %= numFrames;
				
				// if(isFootstepFrame(frameIndex)) {
				// 	PlaySound(footstepSound);
				// }
			} else {
				if(velocity.y < 0) {
					frameIndex = jumpUpFrame;
				} else {
					frameIndex = jumpDownFrame;
				}
			}
			frameRect.x = (float) frameWidth * frameIndex;
		}
	}
	
	return true;
}
	
void Scarfy::draw() {
	Vector2 ulPosition = getUpperLeftPosition();
	DrawTextureRec(texture, frameRect, ulPosition, WHITE);
}
	
Rectangle Scarfy::getBoundingBox() {
	
    Vector2 ulPosition = getUpperLeftPosition();
	return {ulPosition.x, ulPosition.y, texture.width, texture.height};
}
	
void Scarfy::goUp() {
	if(isOnGround) {
		velocity.y = -jumpSpeed;
	}
}
	
void Scarfy::goLeft() {
	if(isOnGround) {
		velocity.x = -walkSpeed;
		if(frameRect.width > 0) {
			frameRect.width = -frameRect.width;
		}
	}
}
	
void Scarfy::goRight() {
	if(isOnGround) {
		velocity.x = walkSpeed;
		if(frameRect.width < 0) {
			frameRect.width = -frameRect.width;
		}
	}
}

void Scarfy::goNowhere() {
	if(isOnGround) {
		velocity.x = 0;
	}
}
	
void Scarfy::goDown() {
}
	
void Scarfy::doInteractWith() {
}

Vector2 Scarfy::getUpperLeftPosition() {
	return {position.x - frameWidth / 2, position.y - texture.height};
}