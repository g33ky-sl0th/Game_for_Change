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
	std::shared_ptr<Drug2> drug2 = std::make_shared<Drug2>();
	std::shared_ptr<Drug3> drug3 = std::make_shared<Drug3>();
	std::shared_ptr<Drug4> drug4 = std::make_shared<Drug4>();
	std::shared_ptr<Drug5> drug5 = std::make_shared<Drug5>();

	int sceneWidth = GetScreenWidth();
	int sceneHeight = GetScreenHeight();
	// scarfy->position = {(float)sceneWidth / 2, (float)groundYPos};
	scarfy->position = {(float)sceneWidth / 2, (float)sceneHeight/2};

	drug1->position = {(float)sceneWidth / 4, (float)sceneHeight/4};
	drug2->position = {(float)sceneWidth*3 / 4, (float)sceneHeight/4};
	drug3->position = {(float)sceneWidth / 4, (float)sceneHeight*3 / 4};
	drug4->position = {(float)sceneWidth*3 / 4, (float)sceneHeight*3 /4};
	drug5->position = {(float)sceneWidth*3 / 5, (float)sceneHeight/3};
	// scarfy->Actor_dimension = 

	playerAvatar = scarfy;
	actors.emplace_back(scarfy);
	actors.emplace_back(drug1);
	actors.emplace_back(drug2);
	actors.emplace_back(drug3);
	actors.emplace_back(drug4);
	actors.emplace_back(drug5);
}
