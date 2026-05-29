#include "GameplayScene.h"


void GameplayScene::Start(SDL_Renderer* rend) {
	Scene::Start(rend);

	objects.push_back(new Spaceship(rend, Vector2(210, 210), 0, Vector2(1,1), this));
	AuxItemsinUpdate.push_back(new Asteroids(rend));
}

void GameplayScene::Render(SDL_Renderer* rend) {
	Scene::Render(rend);

}


void GameplayScene::Update(float dt) {
	Scene::Update(dt);
}


void GameplayScene::Exit(){

}

