#include "GameplayScene.h"


void GameplayScene::Start(SDL_Renderer* rend) {
	Scene::Start(rend);
	renderer = rend;

	objects.push_back(new Spaceship(rend, Vector2(210, 210), 0, Vector2(1,1), this));
	for (size_t i = 0; i < 3; i++)
	{
		AuxItemsinUpdate.push_back(new Asteroids(renderer));

	}
}

void GameplayScene::Render(SDL_Renderer* rend) {
	Scene::Render(rend);

}


void GameplayScene::Update(float dt) {
	Scene::Update(dt);

	if (asteroidSpawnTime >= (asteroidSpawnTimeMax)) {

		AuxItemsinUpdate.push_back(new Asteroids(renderer));

		asteroidSpawnTime = 0;
		if (asteroidSpawnTimeMax >= 1) asteroidSpawnTimeMax -= 0.1;
		std::cout << "Asteroid Spawned " << asteroidSpawnTimeMax << std::endl;
	}

	asteroidSpawnTime += dt;
}


void GameplayScene::Exit(){

}

