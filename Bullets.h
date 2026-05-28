#pragma once
#include "GameObject.h"
#include "InputManager.h"

class Bullets : public GameObject {

public:
	Bullets(SDL_Renderer* renderer, Vector2 position, float rotation, Vector2 scale);
	void UpdateMovement(float dt) override;
};