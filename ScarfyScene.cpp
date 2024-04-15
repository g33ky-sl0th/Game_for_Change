#include "ScarfyScene.h"

#include "raylib.h"

ScarfyScene::ScarfyScene() {
}
	
ScarfyScene::~ScarfyScene() {
}
	
void ScarfyScene::loadResources() {
	std::shared_ptr<Scarfy> scarfy = std::make_shared<Scarfy>();
	
	int sceneWidth = GetScreenWidth();
	scarfy->position = {(float)sceneWidth / 2, (float)groundYPos};
	
	playerAvatar = scarfy;
	actors.emplace_back(scarfy);
}
