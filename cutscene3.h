#pragma once

#include "Scene.h"

/** The cut 1.
 */
class cutscene3 : public Scene {
public:
	cutscene3();
	
	virtual ~cutscene3();
	
	virtual std::shared_ptr<Scene> update();
	
	virtual void draw();

	Texture2D tex;
	
private:
	bool next;
	bool prev;
};
