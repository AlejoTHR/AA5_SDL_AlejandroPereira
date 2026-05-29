#pragma once
#include "GameplayScene.h"


unsigned int GameplayScene::GetPointsCollected() {
	return pointsCollected;
}

void GameplayScene::SetpointsCollected(unsigned short PointsCollected) {
	pointsCollected += PointsCollected;
}


void GameplayScene::Start(SDL_Renderer* rend) {
	Scene::Start(rend);
	renderer = rend;

	objects.push_back(new Spaceship(renderer, Vector2(210, 210), 0, Vector2(1,1), this));
	for (size_t i = 0; i < 3; i++)
	{
		AuxItemsinUpdate.push_back(new Asteroids(renderer));
		AuxItemsinUpdate.push_back(new Asteroids(renderer)); // ADDS TO AUXILIAR OBJECT ARRAY THAT LOADS SAFELY AFTER UPDATE
		if (asteroidSpawnTimeMax < 2) // DIFICULTY UP, IF SPAWN RATIO REDUCES TO MUCH
		{
			AuxItemsinUpdate.push_back(new Asteroids(renderer)); 
		}
	}
}


void GameplayScene::Render(SDL_Renderer* rend) {
	Scene::Render(rend);

}


void GameplayScene::Update(float dt) {
	Scene::Update(dt);

	if (asteroidSpawnTime >= (asteroidSpawnTimeMax)) {

		AuxItemsinUpdate.push_back(new Asteroids(renderer));

		asteroidSpawnTime = 0;
		if (asteroidSpawnTimeMax >= 1) asteroidSpawnTimeMax -= ASTEROID_SPAWN_RATIO;
		std::cout << "Asteroid Spawned " << asteroidSpawnTimeMax << std::endl;
	}

	for (GameObject* obj : objects) {
		Spaceship* spship = dynamic_cast<Spaceship*>(obj); // TURNS OBJECTS INTO SPACESHIP IF IT IS

		// IF obj IS NOT A BULLET
		if (!spship) continue;

		for (GameObject* astrd : objects) {
			Asteroids* asteroid = dynamic_cast<Asteroids*>(astrd);

			// IF obj IS NOT AN ASTEROID
			if (!asteroid) continue;

			if (spship->CollidesWith(asteroid)) {

				for (auto* o : objects) {
					std::cout << "OBJ " << o << " active=" << o->GetIsActive() << std::endl;
				}

				// PREPARE TO DESTROY
				asteroid->SetIsActive(false);
				spship->ShipDamaged();
				std::cout << "LIVES = " << spship->GetLifes();
				if (spship->GetLifes() <= 0) {
					spship->SetIsActive(false);
					std::cout << "\n\n\tGAME OVER";
					std::cout << "TOTAL POINTS = " << GetPointsCollected() << std::endl;
					system("pause");
				}
			}

		}

	}



	for (GameObject* bullts : objects) {
		Bullets* bullet = dynamic_cast<Bullets*>(bullts); // TURNS OBJECTS INTO BULLETS IF IT IS

		// IF obj IS NOT A BULLET
		if (!bullet) continue;

		for (GameObject* astrd : objects) {
			Asteroids* asteroid = dynamic_cast<Asteroids*>(astrd);// TURNS OBJECTS INTO ASTEROIDS IF IT IS

			// IF obj IS NOT AN ASTEROID
			if (!asteroid) continue;

			if (bullet->CollidesWith(asteroid)){

				for (auto* o : objects) {
					std::cout << "OBJ " << o << " active=" << o->GetIsActive() << std::endl;
				}				// DEBUG FOR ALL ACTIVE OBJETS

				// SETS POINTS AND ADDS TO SCENE POINT COUNT
				SetpointsCollected(asteroid->GetPoints());
				std::cout << "Asteroid Hit FOR: " << asteroid->GetPoints() << " POINTS" << std::endl;
				std::cout << "TOTAL POINTS = " 	<< GetPointsCollected() << std::endl;



				// PREPARE TO DESTROY
				bullet->SetIsActive(false);
				asteroid->SetIsActive(false);
			}

		}

	}

	// REMOVES FROM OBJETCS SAFELY BASED ON IsActive ATRIBUTE
	objects.erase(
		std::remove_if(objects.begin(), objects.end(),
			[](GameObject* obj) {
				if (!obj->GetIsActive()) {
					delete obj;
					return true;
				}
				return false;
			}),
		objects.end()
	);

	// ADDS TO asteroidSpawnTime BASED ON dt DELTA TIME
	asteroidSpawnTime += dt;
}


void GameplayScene::Exit(){

}

