#pragma once
#include "GameObject.h"
#include "InputManager.h"

class Bullets : public GameObject {
	Vector2 bulletDirection;
	float bulletVelocity;

public:
	Bullets(SDL_Renderer* renderer, Vector2 pos, Vector2 bulletDirection);
	~Bullets();

	void OutOfBoundsDestroy();
	void UpdateMovement(float dt) override;
};