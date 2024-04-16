#include "InputHandler.h"

#include "CommandListener.h"

#include "raylib.h"

InputHandler::InputHandler() {
	p1GamepadID = 0;
}
	
InputHandler::~InputHandler() {
}

void InputHandler::handleInput(CommandListener &listener) {
	bool moving = false;
	
	// Up/down
	if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W) ){
		listener.goUp();
		moving = true;
	} 
	
	else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S) ){
		listener.goDown();
		moving = true;
	}
	
	// Left/right
	if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D) ){
		listener.goRight();	
		moving = true;
	} 
	
	else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A) ){
		listener.goLeft();
		moving = true;
	}
	
	if(!moving) {
		listener.goNowhere();
	}
	
	// Select, push, pull, etc.
	if(IsKeyDown(KEY_SPACE) || IsKeyDown(KEY_ENTER)){
		listener.doInteractWith();
	}
}