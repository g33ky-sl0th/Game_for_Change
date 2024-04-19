#pragma once

#include "Scene.h"

/** The cut 1.
 */
class cutscene1 : public Scene {
public:
	cutscene1();
	
	virtual ~cutscene1();
	
	virtual std::shared_ptr<Scene> update();
	
	virtual void draw();

	Texture2D tex;
	
private:
	bool next;
	bool prev;
};
