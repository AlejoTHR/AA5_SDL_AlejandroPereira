#pragma once
#include "GameObject.h"
#include "GameplayScene.h"

class Asteroids : public GameObject{
	
	enum AsteroidSize { BIG = 2, MEDIUM = 1, SMALL = 0 };

	Vector2 randomStartPosition;
    Vector2 direction;
    
    unsigned short points;
    AsteroidSize size;
    

public:
	Asteroids(SDL_Renderer* renderer);
    void UpdateMovement(float dt);
    
    unsigned short GetPoints() { return points; }

    AsteroidSize GetSize() const { return size; }

    Vector2 RandomAsteroidSize();
    Vector2 RandomAsteroidsSpawn();
    float RandomAsteroidsLinearVelocity();
    float RandomAsteroidsRotation();

    ~Asteroids();

};