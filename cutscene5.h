#pragma once

#include "Scene.h"

/** The cut 1.
 */
class cutscene5 : public Scene {
public:
	cutscene5();
	
	virtual ~cutscene5();
	
	virtual std::shared_ptr<Scene> update();
	
	virtual void draw();

	Texture2D tex;
	
private:
	bool next;
	bool prev;
};
