#pragma once
#include "GameObject.h"


class Asteroids : public GameObject{

public:
	Asteroids(SDL_Renderer* renderer, Vector2 position, float rotation, Vector2 scale);
	void UpdateMovement(float dt) override;
};