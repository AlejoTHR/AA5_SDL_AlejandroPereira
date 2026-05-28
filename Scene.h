#pragma once
#include "GameObject.h"
#include <vector>


class Scene {
protected:
	std::vector<GameObject*> objects;
	bool finished;
	std::string targetScene;

public:

	virtual void Start(SDL_Renderer* rend);

	virtual void Update(float dt);

	virtual void Render(SDL_Renderer* rend);

	virtual void Exit() = 0;

	bool IsFinished();
	std::string GetTargetScene();
};