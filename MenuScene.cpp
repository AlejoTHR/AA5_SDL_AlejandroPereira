#pragma once
#include "MenuScene.h"

void MenuScene::Start(SDL_Renderer* rend) {
	Scene::Start(rend);
	options = { "MenuScene", "HighScoreScene", "GameplayScene" };
menuText = R"(     _    ____ _____ _____ ____   ___ ___ ____  ____  
    / \  / ___|_   _| ____|  _ \ / _ \_ _|  _ \/ ___| 
   / _ \ \___ \ | | |  _| | |_) | | | | || | | \___ \ 
  / ___ \ ___) || | | |___|  _ <| |_| | || |_| |___) |
 /_/   \_\____/ |_| |_____|_| \_\\___/___|____/|____/ 
)";
	extraText = "  Move with W & S, select with SPACE.";
}


void MenuScene::Render(SDL_Renderer* rend) {
	Scene::Render(rend);
	system("cls");

	std::cout << std::endl << menuText << std::endl << std::endl;

	for (int optionNum = 0; optionNum < options.size(); optionNum++)
	{

		bool canShowSelectionMarker = optionNum == selectedOption && ((actualFrame % 2 || direction.y != 0) || direction.x != 0);

		std::cout << optionNum + 1 << (optionNum == selectedOption ? (canShowSelectionMarker ? ". < " : ".   ") : ". ") << options[optionNum];

		if (canShowSelectionMarker) std::cout << " >";
		std::cout << std::endl;
	}
	if (!extraText.empty()) std::cout << std::endl << extraText;
	//Sleep(SCENE_TRAVEL_TIME);

}


void MenuScene::Update(float dt) {
	Scene::Update(dt);


}


void MenuScene::Exit() {

}

