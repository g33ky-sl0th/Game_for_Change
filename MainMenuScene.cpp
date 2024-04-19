// #include "raylib.h"

// #include "MainMenuScene.h"

// #include "cutscene1.h"

// // #include "ScarfyScene.h"

// #define RAYGUI_IMPLEMENTATION
// #include "raygui.h"


// #define TITLE_FONT_SIZE 160
// #define TITLE_FONT_SPACING 10.0f
// #define MENU_FONT_SIZE 40

// #define BUTTON_WIDTH 280
// #define BUTTON_HEIGHT 70
// #define BUTTON_SPACING (BUTTON_HEIGHT + 10)

// MainMenuScene::MainMenuScene() {
// 	startClicked = false;
// 	quit = false;
// 	InitAudioDevice();
//     backgroundMusic = LoadMusicStream("bgm_menu.mp3");
//     PlayMusicStream(backgroundMusic);
// }
	
// MainMenuScene::~MainMenuScene() {
// 	UnloadMusicStream(backgroundMusic);
//     CloseAudioDevice();
// }

// std::shared_ptr<Scene> MainMenuScene::update() {

// 	UpdateMusicStream(backgroundMusic);

// 	if(startClicked) {
// 		return std::make_shared<cutscene1>();
// 	} 
	
// 	else {
// 		return nullptr;
// 	}
// }

// bool MainMenuScene::shouldQuit() {
// 	return quit;
// }

// void MainMenuScene::draw() {

// 	Scene::draw();
	
// 	int sceneWidth = GetScreenWidth();
// 	int sceneHeight = GetScreenHeight();
	
// 	const char *title = "GTA-IIT_DILLI";
// 	Font titleFont = GetFontDefault();
// 	Vector2 titleDim = MeasureTextEx(titleFont, title, TITLE_FONT_SIZE, TITLE_FONT_SPACING); 
	
// 	int titleLeft = (sceneWidth - titleDim.x) / 2;
// 	int titleTop = sceneHeight / 4 - titleDim.y / 2;
// 	Vector2 titlePos{(float)titleLeft, (float)titleTop};
// 	::DrawTextEx(titleFont, title, titlePos, TITLE_FONT_SIZE, TITLE_FONT_SPACING, RED);
	
// 	int menuLeft = (sceneWidth - BUTTON_WIDTH) / 2;
// 	int menuTop = sceneHeight / 2;
// 	float currX = (float)menuLeft;
// 	float currY = (float)menuTop;
	
// 	GuiSetStyle(BUTTON, TEXT_ALIGNMENT, TEXT_ALIGN_CENTER);
// 	GuiSetStyle(DEFAULT, TEXT_SIZE, MENU_FONT_SIZE);

// 	if (GuiButton((Rectangle){ currX, currY, BUTTON_WIDTH, BUTTON_HEIGHT }, "Start Game")) {
// 		startClicked = true;
// 	}

// 	currY += BUTTON_SPACING;
	
// 	if (GuiButton((Rectangle){ currX, currY, BUTTON_WIDTH, BUTTON_HEIGHT }, "Quit")) {
// 		quit = true;
// 	}
// }

// void MainMenuScene::doExit() {
// 	quit = true;
// }

#include "raylib.h"

#include "MainMenuScene.h"

#include "ScarfyScene.h"
#include "cutscene1.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"


#define GREEN CLITERAL(Color){ 0, 228, 48, 255 }

#define TITLE_FONT_SIZE 100
#define TITLE_FONT_SPACING 10.0f
#define MENU_FONT_SIZE 40

#define BUTTON_WIDTH 280
#define BUTTON_HEIGHT 70
#define BUTTON_SPACING (BUTTON_HEIGHT + 10)

MainMenuScene::MainMenuScene() {
	startClicked = false;
	quit = false;
    InitAudioDevice();
    backgroundMusic = LoadMusicStream("bgm_menu.mp3");
    PlayMusicStream(backgroundMusic);
}
	
MainMenuScene::~MainMenuScene() {
    UnloadMusicStream(backgroundMusic);
    CloseAudioDevice();
}

std::shared_ptr<Scene> MainMenuScene::update() {
    UpdateMusicStream(backgroundMusic);
	if(startClicked) {
		return std::make_shared<cutscene1>();
	} 
	
	else {
		return nullptr;
	}
}

bool MainMenuScene::shouldQuit() {
	return quit;
}

void DrawRoundedRectangle(int posX, int posY, int width, int height, int cornerRadius, Color color) {
    DrawRectangleRounded((Rectangle){ posX, posY, width, height }, (float)cornerRadius, 0, color);
}

bool GuiButtonRounded(Rectangle bounds, const char *text, int cornerRadius) {
    bool clicked = GuiButton(bounds, text);

    // Draw rounded rectangle over the default button
    DrawRoundedRectangle(bounds.x, bounds.y, bounds.width, bounds.height, cornerRadius, (Color){ 0, 0, 0, 0 });

    return clicked;
}

Color titleColor = BLACK;

void MainMenuScene::draw() {

	Scene::draw();
	
	int sceneWidth = GetScreenWidth();
	int sceneHeight = GetScreenHeight();
    //InitAudioDevice();
	
	const char *title = "CAMPUS-RESCUE";
	Font f1 = LoadFont("font4.otf");
	Vector2 titleDim = MeasureTextEx(f1, title, TITLE_FONT_SIZE, TITLE_FONT_SPACING); 
	
    Texture2D background = LoadTexture("back4(1).png");
    

    titleColor = (Color){ (unsigned char)(255 * sinf(GetTime())), (unsigned char)(255 * cosf(GetTime())), (unsigned char)(255 * sinf(GetTime() * 0.5f)), 255 };
	int titleLeft = (sceneWidth - titleDim.x) / 2;
	int titleTop = sceneHeight / 4 - titleDim.y / 2;
	Vector2 titlePos{(float)titleLeft, (float)titleTop};
	::DrawTextEx(f1, title, titlePos, TITLE_FONT_SIZE, TITLE_FONT_SPACING, titleColor);
	
	int menuLeft = (sceneWidth - BUTTON_WIDTH) / 2;
	int menuTop = sceneHeight / 2;
	float currX = (float)menuLeft;
	float currY = (float)menuTop;
	
	GuiSetStyle(BUTTON, TEXT_ALIGNMENT, TEXT_ALIGN_CENTER);
	GuiSetStyle(DEFAULT, TEXT_SIZE, MENU_FONT_SIZE);
    GuiSetStyle(BUTTON, TEXT_COLOR_NORMAL, 255);

    Font buttonFont = LoadFont("font2.otf"); // Load your custom font
    GuiSetFont(buttonFont);
    DrawTexture(background,250,250,WHITE);

    if (CheckCollisionPointRec(GetMousePosition(), (Rectangle){currX, currY, BUTTON_WIDTH, BUTTON_HEIGHT})) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    } 
    else {
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }

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
