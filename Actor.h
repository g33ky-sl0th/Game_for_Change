#pragma once

#include "CommandListener.h"

#include "raylib.h"

/** Base class for actors in scenes. 
 * An actor is anything in the scene that moves, or is not part of the background.
 */

class Actor : public CommandListener {
	
public:

	Actor();
	
	virtual ~Actor();
	
	/** Updates this actor's state.
	 * This could include the animation state, triggering of sounde effects, etc.
	 *
	 * IMPORTANT: Physics simulation is handled at the scene level.
	 *
	 * @param onGround true if the actor is on the ground/floor, and false if
	 * he/she/it is airborne
	 *
	 * @return bool true if this actor still exists, and false if it has "exited
	 * the scene, never to return" (e., dead)
	 */
	virtual bool update();
	
	/** Draws this actor to the display.
	 */
	virtual void draw();
	
	/** Returns this actor's bounding box in world coordinages (i.e., the smallest 
	 * rectangle that contains this actor, including all its sub-components).
	 */
	virtual Rectangle getBoundingBox();

public:
	/** This actor's current position.
	 */
	Vector2 position;
	
	/** This actor's current velocity.
	 */
	Vector2 velocity;

	Vector2 Actor_dimension;

	bool isMain;
	bool isFpressed;
	bool isRevived;
};
