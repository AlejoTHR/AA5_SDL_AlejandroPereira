#pragma once
#include "GameObject.h"
#include "GameplayScene.h"

class Asteroids : public GameObject{
	
	enum AsteroidSize { BIG = 2, MEDIUM = 1, SMALL = 0 };

	Vector2 randomStartPosition;
    Vector2 direction;
    
    int points;
    AsteroidSize size;
    

public:
	Asteroids(SDL_Renderer* renderer);
    void UpdateMovement(float dt);
    
    int GetPoints() const { return points; }

    AsteroidSize GetSize() const { return size; }

    Vector2 RandomAsteroidSize();
    Vector2 RandomAsteroidsSpawn();
    float RandomAsteroidsLinearVelocity();
    float RandomAsteroidsRotation();

    ~Asteroids();

};