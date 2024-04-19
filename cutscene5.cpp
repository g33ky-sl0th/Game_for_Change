#include "raylib.h"

#include "cutscene4.h"  // prev
#include "cutscene5.h"  // curr
#include "ScarfyScene.h"    // next

// #define RAYGUI_IMPLEMENTATION
// #include "raygui.h"

cutscene5::cutscene5() {
    tex = LoadTexture("s5.png");
	next = false;
	prev = false;
}
	
cutscene5::~cutscene5() {
    UnloadTexture(tex);
}

std::shared_ptr<Scene> cutscene5::update() {

	if(next) {
		return std::make_shared<ScarfyScene>();
	}

    if (prev){
        return std::make_shared<cutscene4>();
    }
	
	else {
		return nullptr;
	}
}

void cutscene5::draw() {

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




