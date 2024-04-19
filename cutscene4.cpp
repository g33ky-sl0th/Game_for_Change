#include "raylib.h"

#include "cutscene3.h"  // prev
#include "cutscene4.h"  // curr
#include "cutscene5.h"    // next

// #include "ScarfyScene.h"    //

// #define RAYGUI_IMPLEMENTATION
// #include "raygui.h"

cutscene4::cutscene4() {
    tex = LoadTexture("s4.png");
	next = false;
	prev = false;
}
	
cutscene4::~cutscene4() {
    UnloadTexture(tex);
}

std::shared_ptr<Scene> cutscene4::update() {

	if(next) {
		return std::make_shared<cutscene5>();
	}

    if (prev){
        return std::make_shared<cutscene3>();
    }
	
	else {
		return nullptr;
	}
}

void cutscene4::draw() {

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




