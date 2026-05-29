#pragma once
#include <SDL.h>
#include <iostream>
#include <map>

#include "Cons.h"
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
	int wWidth = WINDOW_WIDTH;
	int wHeight = WINDOW_HEGITH;

	void InitSDL();
	void InitWindowAndRenderer(int windowWith, int windowHeigh);

public:
	GameEngine(int windowWith, int windowHeigh);
	
	int GetwWidth();
	int GetwHeigth();
	SDL_Window* GetWindow();
	SDL_Renderer* getRenderer();

	void Update();
	void Finish();
};