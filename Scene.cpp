#include "Scene.h"

void Scene::Start(SDL_Renderer* rend) {
	finished = false;

};

void Scene::Update(float dt) {
	for (GameObject* var : objects)
	{
		var->Update(dt);
	}
};

void Scene::Render(SDL_Renderer* rend) {
	for (GameObject* var : objects)
	{
		var->Render(rend);
	}

};

bool Scene::IsFinished() { return finished; }
std::string Scene::GetTargetScene() { return targetScene; }