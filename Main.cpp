#include "InputHandler.h"
#include "ScarfyScene.h"
#include "MainMenuScene.h"

#include "raymath.h"
#include "raylib.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdexcept>

#include <iostream>

const int screenWidth = 1600;
const int screenHeight = 900;

/* Displays a single line error message, and exits when the user pushes ESCape, or the window's close
 * button.
 */
void showErrorAndExit(const char *errMsg) {
	while (!WindowShouldClose()) {
		BeginDrawing();
			ClearBackground(BLACK);
			DrawText(errMsg, 20, 20, 20, RED);
		EndDrawing();
	}
	
	exit(EXIT_FAILURE);
}

int main(void)
{
	int retVal = EXIT_SUCCESS;
	
	// Initialization
	// NOTE: These are put outside the try block, so that they still exist in the catch block.
	// Otherwise we'll never see any error messages...
	InitWindow(screenWidth, screenHeight, "GTA - IIT_Dilli");
		
	try {
		InputHandler inputHandler;
		
		std::shared_ptr<Scene> currScene = std::make_shared<MainMenuScene>();
		currScene->loadResources();
		currScene->start();

		SetTargetFPS(60);
		SetExitKey(KEY_NULL);

		// Main game loop
		bool quit = false;

		while (!quit)    // Detect window close button or ESC key
		{
			// Update
			inputHandler.handleInput(*currScene);
			// in currScene's function velocity is being 
			// updated for out actor and then 
			// currScene uses the updated velocity

			auto nextScene = currScene->update();

			// if (nextScene == nullptr){

			// std::cout << "hi\n";
			// }
			
			if(nextScene) {

				// std::cout << "hello\n";

				nextScene->loadResources();
				nextScene->start();
				currScene = nextScene;
			}

			quit = WindowShouldClose() || currScene->shouldQuit();
			
			// Draw
			BeginDrawing();
			currScene->draw();
			EndDrawing();
		}
	} 
	
	catch(std::runtime_error &e) {
		showErrorAndExit(e.what());
		retVal = EXIT_FAILURE; 
	}
	
    return retVal;
}
