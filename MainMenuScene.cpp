#include "raylib.h"

#include "MainMenuScene.h"

#include "ScarfyScene.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"


#define TITLE_FONT_SIZE 160
#define TITLE_FONT_SPACING 10.0f
#define MENU_FONT_SIZE 40

#define BUTTON_WIDTH 280
#define BUTTON_HEIGHT 70
#define BUTTON_SPACING (BUTTON_HEIGHT + 10)

MainMenuScene::MainMenuScene() {
	startClicked = false;
	quit = false;
}
	
MainMenuScene::~MainMenuScene() {
}

std::shared_ptr<Scene> MainMenuScene::update() {

	if(startClicked) {
		return std::make_shared<ScarfyScene>();
	} 
	
	else {
		return nullptr;
	}
}

bool MainMenuScene::shouldQuit() {
	return quit;
}

void MainMenuScene::draw() {
	Scene::draw();
	
	int sceneWidth = GetScreenWidth();
	int sceneHeight = GetScreenHeight();
	
	const char *title = "GTA-IIT_DILLI";
	Font titleFont = GetFontDefault();
	Vector2 titleDim = MeasureTextEx(titleFont, title, TITLE_FONT_SIZE, TITLE_FONT_SPACING); 
	
	int titleLeft = (sceneWidth - titleDim.x) / 2;
	int titleTop = sceneHeight / 4 - titleDim.y / 2;
	Vector2 titlePos{(float)titleLeft, (float)titleTop};
	::DrawTextEx(titleFont, title, titlePos, TITLE_FONT_SIZE, TITLE_FONT_SPACING, RED);
	
	int menuLeft = (sceneWidth - BUTTON_WIDTH) / 2;
	int menuTop = sceneHeight / 2;
	float currX = (float)menuLeft;
	float currY = (float)menuTop;
	
	GuiSetStyle(BUTTON, TEXT_ALIGNMENT, TEXT_ALIGN_CENTER);
	GuiSetStyle(DEFAULT, TEXT_SIZE, MENU_FONT_SIZE);
	if (GuiButton((Rectangle){ currX, currY, BUTTON_WIDTH, BUTTON_HEIGHT }, "Start Game")) {
		startClicked = true;
	}
	currY += BUTTON_SPACING;
	if (GuiButton((Rectangle){ currX, currY, BUTTON_WIDTH, BUTTON_HEIGHT }, "Quit")) {
		quit = true;
	}
}

void MainMenuScene::doExit() {
	quit = true;
}
