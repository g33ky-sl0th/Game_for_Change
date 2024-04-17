#pragma once

#include "Scene.h"

/** The game's main menu.
 */
class MainMenuScene : public Scene {
public:
	MainMenuScene();
	
	virtual ~MainMenuScene();
	
	virtual std::shared_ptr<Scene> update();
	
	virtual bool shouldQuit();
	
	virtual void draw();
	
	virtual void doExit();
	
private:
	bool startClicked;
	bool quit;
};