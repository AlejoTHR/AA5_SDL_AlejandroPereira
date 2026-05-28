#pragma once
#include "GameObject.h"
#include "InputManager.h"

class Spaceship : public GameObject {
	



public:
	Spaceship(SDL_Renderer* renderer, Vector2 position, float rotation, Vector2 scale);

	void UpdateMovement(float dt) override;
	void CreateBullets(float dt, SDL_Renderer* renderer, Vector2 position, float rotation, Vector2 scale);
};