#include "Actor.h"

// #include "raylib-cpp/include/Functions.hpp"
// #include "raylib-cpp/include/Text.hpp"

#include "raylib.h"

Actor::Actor() {
}
	
Actor::~Actor() {
}

bool Actor::update(bool onGround) {
	return true;
}

void Actor::draw() {
	// raylib::Text message("Override Actor::draw()", 20, RED, ::GetFontDefault(), 1.0f);
	// auto textSize = message.MeasureEx();
	// message.Draw(position, 0, textSize);
}

Rectangle Actor::getBoundingBox() {
	return {position.x, position.y, Actor_dimension.x, Actor_dimension.y};
}
