#pragma once

#include "Scene.h"

#include "Scarfy.h" ////////////////////////
#include "Drug1.h"

/** A scene for scarfy to walk around in.
 */
class ScarfyScene : public Scene {
public:
	ScarfyScene();
	
	virtual ~ScarfyScene();
	
	virtual void loadResources();
};

