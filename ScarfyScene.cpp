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
	scarfy->position = {180.0f, 180.0f};

	// Determine positions in world space
	Vector2 drug1Pos = {200.0f, 200.0f}; // Example position for drug1
	Vector2 drug2Pos = {600.0f, 200.0f}; // Example position for drug2
	Vector2 drug3Pos = {200.0f, 600.0f}; // Example position for drug3
	Vector2 drug4Pos = {600.0f, 600.0f}; // Example position for drug4
	Vector2 drug5Pos = {400.0f, 300.0f}; // Example position for drug5

	// Assign positions to drug1 to drug5
	drug1->position = drug1Pos;
	drug2->position = drug2Pos;
	drug3->position = drug3Pos;
	drug4->position = drug4Pos;
	drug5->position = drug5Pos;
	// scarfy->Actor_dimension = 

	playerAvatar = scarfy;
	actors.emplace_back(scarfy);
	actors.emplace_back(drug1);
	actors.emplace_back(drug2);
	actors.emplace_back(drug3);
	actors.emplace_back(drug4);
	actors.emplace_back(drug5);
}
