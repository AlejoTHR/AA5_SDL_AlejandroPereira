#pragma once
#include "GameObject.h"
#include "InputManager.h"
#include "Bullets.h"
#include "Cons.h"

class GameplayScene;

class Spaceship : public GameObject {
	
	SDL_Renderer* Render;
	GameplayScene* ShipScene;

public:
	Spaceship(SDL_Renderer* renderer, Vector2 position, float rotation, Vector2 scale, GameplayScene* shipScene);

	void UpdateMovement(float dt) override;

};
