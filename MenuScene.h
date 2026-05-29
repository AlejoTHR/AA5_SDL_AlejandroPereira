#pragma once
#include "Scene.h"

class MenuScene : public Scene {
private:
	std::vector<std::string> options;
	std::string menuText;
	std::string extraText;

	short selectedOption = 0; 
	unsigned long actualFrame = 0;
	Vector2 direction;
public:
	MenuScene() : Scene(){}

	void Start(SDL_Renderer* rend) override;
	void Update(float dt) override;
	void Render(SDL_Renderer* rend) override;
	void Exit() override;

};