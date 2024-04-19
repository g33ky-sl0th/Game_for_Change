#pragma once

#include "Scene.h"

/** The cut 1.
 */
class cutscene2 : public Scene {
public:
	cutscene2();
	
	virtual ~cutscene2();
	
	virtual std::shared_ptr<Scene> update();
	
	virtual void draw();

	Texture2D tex;
	
private:
	bool next;
	bool prev;
};
