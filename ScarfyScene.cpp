#include "ScarfyScene.h"
#include "raylib.h"

ScarfyScene::ScarfyScene() {
}
	
ScarfyScene::~ScarfyScene() {
}
	
void ScarfyScene::loadResources() {
	
	
	//
	std::shared_ptr<Scarfy> scarfy = std::make_shared<Scarfy>();
	
	std::shared_ptr<Drug1> drug1 = std::make_shared<Drug1>();

	int sceneWidth = GetScreenWidth();
	int sceneHeight = GetScreenHeight();
	// scarfy->position = {(float)sceneWidth / 2, (float)groundYPos};
	scarfy->position = {(float)sceneWidth / 2, (float)sceneHeight/2};
	// scarfy->Actor_dimension = 

	playerAvatar = scarfy;
	actors.emplace_back(scarfy);
	actors.emplace_back(drug1);
}
