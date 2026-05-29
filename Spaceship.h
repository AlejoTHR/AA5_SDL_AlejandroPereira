#pragma once
#include "GameObject.h"
#include "InputManager.h"
#include "Bullets.h"
#include "Cons.h"

class GameplayScene;

class Spaceship : public GameObject {
	
	SDL_Renderer* Render;
	GameplayScene* ShipScene;

	unsigned short lifes = 3;

public:
	Spaceship(SDL_Renderer* renderer, Vector2 position, float rotation, Vector2 scale, GameplayScene* shipScene);

	unsigned short GetLifes();
	void ShipDamaged();

	void UpdateMovement(float dt) override;

};
