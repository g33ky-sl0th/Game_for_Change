#include "ScarfyScene.h"

#include "raylib.h"

ScarfyScene::ScarfyScene() {
}
	
ScarfyScene::~ScarfyScene() {
}
	
void ScarfyScene::loadResources() {
	
	
	//
	std::shared_ptr<Scarfy> scarfy = std::make_shared<Scarfy>();
	
	int sceneWidth = GetScreenWidth();
	int sceneHeight = GetScreenHeight();
	// scarfy->position = {(float)sceneWidth / 2, (float)groundYPos};
	scarfy->position = {(float)sceneWidth / 2, (float)sceneHeight/2};


	playerAvatar = scarfy;
	actors.emplace_back(scarfy);
}
