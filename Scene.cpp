#include "Scene.h"

void Scene::Start(SDL_Renderer* rend) {
	finished = false;

};


void Scene::ClearAllAuxObjects() {
	for (GameObject* destroyedObj : AuxItemsinUpdate)
	{
		std::vector<GameObject*>::iterator iterator = objects.begin();
		for (size_t objIdx = 0; objIdx < objects.size(); objIdx++)
		{
			if (objects[objIdx] == destroyedObj) {
				objects.erase(iterator);
				break;
			}
			if (iterator != objects.end())
				iterator++;
		}
		delete(destroyedObj);
	}
}

void Scene::Update(float dt) {

	for (GameObject* var : objects)
	{
		var->Update(dt);
	}

	if (!AuxItemsinUpdate.empty())
	{
		objects.reserve(objects.size() + AuxItemsinUpdate.size());
		objects.insert(objects.end(), AuxItemsinUpdate.begin(), AuxItemsinUpdate.end());
		AuxItemsinUpdate.clear();
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

void Scene::InstantiateObject(GameObject* newItem) {
	AuxItemsinUpdate.push_back(newItem);
}
