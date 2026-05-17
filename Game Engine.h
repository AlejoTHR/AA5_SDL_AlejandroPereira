#pragma once
#include <SDL.h>

#include <iostream>
#include "GameObject.h"
#include <map>
#include "Scene.h"
#include "MenuScene.h"
#include "HighscoreScene.h"
#include "GameplayScene.h"
#include "InputManager.h"

class GameEngine 
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	void InitSDL();
	void InitWindowAndRenderer(int windowWith, int windowHeigh);

public:
	GameEngine(int windowWith, int windowHeigh);

	void Update();
	void Finish();
};