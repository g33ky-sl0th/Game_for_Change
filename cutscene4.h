#pragma once

#include "Scene.h"

/** The cut 1.
 */
class cutscene4 : public Scene {
public:
	cutscene4();
	
	virtual ~cutscene4();
	
	virtual std::shared_ptr<Scene> update();
	
	virtual void draw();

	Texture2D tex;
	
private:
	bool next;
	bool prev;
};
