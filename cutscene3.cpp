#include "raylib.h"

#include "cutscene2.h"  // prev
#include "cutscene3.h"  // curr
#include "cutscene4.h"    // next

// #include "ScarfyScene.h"    //

// #define RAYGUI_IMPLEMENTATION
// #include "raygui.h"

cutscene3::cutscene3() {
    tex = LoadTexture("s3.png");
	next = false;
	prev = false;
}
	
cutscene3::~cutscene3() {
    UnloadTexture(tex);
}

std::shared_ptr<Scene> cutscene3::update() {

	if(next) {
		return std::make_shared<cutscene4>();
	}

    if (prev){
        return std::make_shared<cutscene2>();
    }
	
	else {
		return nullptr;
	}
}

void cutscene3::draw() {

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



