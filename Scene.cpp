#include "Scene.h"
#include "Actor.h"

#include "raymath.h"

#include <cmath>

Scene::Scene() {
	int sceneHeight = GetScreenHeight();

	// groundYPos = (3 * sceneHeight) / 4;
	// gravity = 1;
}
	
Scene::~Scene() {
	freeResources();
}
	
void Scene::loadResources() {
}
	
void Scene::freeResources() {

	playerAvatar.reset();
	actors.clear();
}

void Scene::start() {
}
	
std::shared_ptr<Scene> Scene::update() {

	auto scarfy = actors.front();
	scarfy->position = Vector2Add(scarfy->position,scarfy->velocity);

	

	for(auto &actor : actors) {

		if (actor == scarfy){
			continue;
		}

		scarfy->update();

		if (scarfy->isFpressed == true){

			float dist = ((scarfy->position.x - actor->position.x)*(scarfy->position.x - actor->position.x)) + ((scarfy->position.x - actor->position.x)*(scarfy->position.y - actor->position.y));
			dist = sqrt(dist);

			float ht = 50.0;

			if (dist <= ht){
				actor->update();
			}
		}

		// auto boundingRect = actor->getBoundingBox();
	}
	
	return nullptr;
}

bool Scene::shouldQuit() {
	return false;
}
	
void Scene::draw() {

	ClearBackground(RAYWHITE);
		
	if(actors.size() != 0) {

		for(auto &actor: actors) {
			actor->draw();
		}
	} 
	
	else {
		DrawText("Are you ready for actual virtual tour of IIT-Delhi ?!", 20, 20, 20, BLUE);
	}
}
	
void Scene::goUp() {
	if(playerAvatar) {
		playerAvatar->goUp();
	}
}
	
void Scene::goLeft() {
	if(playerAvatar) {
		playerAvatar->goLeft();
	}
}
	
void Scene::goRight() {
	if(playerAvatar) {
		playerAvatar->goRight();
	}
}
	
void Scene::goDown() {
	if(playerAvatar) {
		playerAvatar->goDown();
	}
}

void Scene::goNowhere() {
	if(playerAvatar) {
		playerAvatar->goNowhere();
	}
}
	
void Scene::doInteractWith_1() {
	if(playerAvatar) {
		playerAvatar->doInteractWith_1();
	}
}

void Scene::doInteractWith_2() {
	if(playerAvatar) {
		playerAvatar->doInteractWith_2();
	}
}