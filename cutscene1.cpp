#include "raylib.h"

#include "MainMenuScene.h"  // prev
#include "cutscene1.h"  // curr
#include "cutscene2.h"    // next

// #include "ScarfyScene.h"    //

// #define RAYGUI_IMPLEMENTATION
// #include "raygui.h"

cutscene1::cutscene1() {
    tex = LoadTexture("s1.png");
	next = false;
	prev = false;
}
	
cutscene1::~cutscene1() {
    UnloadTexture(tex);
}

std::shared_ptr<Scene> cutscene1::update() {

	if(next) {
		return std::make_shared<cutscene2>();
	}

    if (prev){
        return std::make_shared<MainMenuScene>();
    }
	
	else {
		return nullptr;
	}
}

void cutscene1::draw() {

	Scene::draw();
    DrawTexture(tex, 0, 0, WHITE);

    if (IsKeyReleased(KEY_P)){
        next = true;
    }

    if (IsKeyReleased(KEY_O)){
        prev = true;
    }
}

// void cutscene1::doExit() {
// 	quit = true;
// }

