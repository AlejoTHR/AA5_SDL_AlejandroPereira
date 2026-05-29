#pragma once
#include "Scene.h"
#include "Spaceship.h"
#include "Bullets.h"
#include "Asteroids.h"

class GameplayScene : public Scene {

	SDL_Renderer* renderer = nullptr; // RENDER RESTART, INSTANTIATED IN START() FUNCTION FOR UODATE FUNCTION CALSS

	float asteroidSpawnTime = 0; // TIME PASSED FOR AN ASTEROID TO SPAWN
	float asteroidSpawnTimeMax = 5.0f; // TIME TO PASS FOR AN ASTEROID TO SPAWN

public:
	GameplayScene() : Scene(){}

	void Start(SDL_Renderer* rend) override;
	void Update(float dt) override;
	void Render(SDL_Renderer* rend) override;
	void Exit() override;

};