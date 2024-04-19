#include "raylib.h"

#include "cutscene1.h"  // prev
#include "cutscene2.h"  // curr
#include "cutscene3.h"    // next

// #include "ScarfyScene.h"    //

// #define RAYGUI_IMPLEMENTATION
// #include "raygui.h"

cutscene2::cutscene2() {
    tex = LoadTexture("s2.png");
	next = false;
	prev = false;
}
	
cutscene2::~cutscene2() {
    UnloadTexture(tex);
}

std::shared_ptr<Scene> cutscene2::update() {

	if(next) {
		return std::make_shared<cutscene3>();
	}

    if (prev){
        return std::make_shared<cutscene1>();
    }
	
	else {
		return nullptr;
	}
}

void cutscene2::draw() {

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


