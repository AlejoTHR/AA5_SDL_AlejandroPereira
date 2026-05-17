#include "Game Engine.h"

GameEngine::GameEngine(int windowWith, int windowHeigh) {
	InitSDL();
	InitWindowAndRenderer(windowWith,windowHeigh);
}
void GameEngine::InitSDL() {
	int result = SDL_Init(SDL_INIT_VIDEO);

	if (result < 0) {
		std::cout << "SDL_Init error:" << SDL_GetError();
	}
}
void GameEngine::InitWindowAndRenderer(int windowWith, int windowHeigh) {
	
	 window = SDL_CreateWindow("SDL_WINDOW",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		windowWith, windowHeigh,
		SDL_WINDOW_SHOWN);

	if (window == nullptr) {
		std::cout << "Error creating window: " << SDL_GetError();
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == nullptr) {
		std::cout << "Error creating window: " << SDL_GetError();
	}
}

void GameEngine::Update() {
	//TIMEW Controler
	float dt = 0.0f;
	float lastTime = SDL_GetPerformanceCounter() / (float)SDL_GetPerformanceFrequency();

	const int FPS = 60;
	const float frameTime = 1.0f / (float)FPS;

	//Scenes
	std::map<std::string, Scene*> gameScene;
	//gameScene["MainMenu"] = new MenuScene();
	gameScene["Gameplay"] = new GameplayScene();
	gameScene["HighScore"] = new HighscoreScene();

	Scene* currentScene = gameScene["Gameplay"];
	currentScene->Start(renderer);

	while (!IM.GetQuit()) {
		//deltaTimeControl
		float currentTime = SDL_GetPerformanceCounter() / (float)SDL_GetPerformanceFrequency();
		dt += currentTime - lastTime;
		lastTime = currentTime;
		//Input
		if (dt > frameTime) {
			IM.Listen();

			//Update
			currentScene->Update(dt);

			//Render
			SDL_RenderClear(renderer);
			currentScene->Render(renderer);
			SDL_RenderPresent(renderer);

			//Scene Transition
			if (currentScene->IsFinished()) {
				currentScene->Exit();
				currentScene = gameScene[currentScene->GetTargetScene()];
				currentScene->Start(renderer);

			}
			dt -= frameTime;

		}
	}
}
// spritesheet nave ponerla en la escena gameplay y que rote con el deltatime
void GameEngine::Finish() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}