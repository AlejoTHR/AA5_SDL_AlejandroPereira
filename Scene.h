#pragma once
#include "GameObject.h"
#include <vector>

class Scene {
protected:
	std::vector<GameObject*> objects;
	bool finished;
	std::string targetScene;

public:
	virtual void Start(SDL_Renderer* rend) {
		finished = false;

	};

	virtual void Update(float dt) {
		for (GameObject* var : objects)
		{
			var->Update(dt);
		}
	};

	virtual void Render(SDL_Renderer* rend) {
		for (GameObject* var : objects)
		{
			var->Render(rend);
		}
	
	};

	virtual void Exit() = 0;

	bool IsFinished() { return finished; }
	std::string GetTargetScene() { return targetScene; }

};