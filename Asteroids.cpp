#pragma once
#include "Asteroids.h"

Asteroids::Asteroids(SDL_Renderer* renderer) 
	: GameObject(GameObject(renderer, Vector2(40, 40), Vector2(40, 0))) {

	position = RandomAsteroidsSpawn();
    rotation = RandomAsteroidsRotation();
    scale = RandomAsteroidSize();

	linearVelocity = Vector2();
	angularVelocity = 0.0f;

	linearAcceleration = Vector2();
	angularAcceleration = 0.0f;

	linearDrag = 0.0f;
	angularDrag = 0.0f;

	linearAccFactor = RandomAsteroidsLinearVelocity();
	angularAccFactor = ASTEROID_ANG_ACC_FACTOR; 
}

Vector2 Asteroids::RandomAsteroidsSpawn() {
    unsigned short side = rand() % 3;

    switch (side) {
    case 0: 
        return Vector2 ((float)(rand() % WINDOW_WIDTH), 0.0f );
        break;
    case 1: 
        return Vector2( (float)(rand() % WINDOW_WIDTH), (float)WINDOW_HEGITH);
        break;
    case 2: 
        return Vector2( 0.0f, (float)(rand() % WINDOW_HEGITH));
        break;
    default: 
        return Vector2( (float)WINDOW_WIDTH, (float)(rand() % WINDOW_HEGITH));
        break;
    }
}

float Asteroids::RandomAsteroidsLinearVelocity() {
    float randomVelocity = (ASTEROID_LIN_ACC_FACTOR - 100) + (rand() % (int)((ASTEROID_LIN_ACC_FACTOR + 100) - (ASTEROID_LIN_ACC_FACTOR - 100)));

    return randomVelocity;
}

float Asteroids::RandomAsteroidsRotation() {
    float randomRotation = rand() % 360;
    return randomRotation;
}

Vector2 Asteroids::RandomAsteroidSize() {
    unsigned short randSize = rand() % 3;
    size = (AsteroidSize)randSize;
    switch (randSize) {
    case BIG:
        scale = Vector2 (1.5f,1.5f);
        break;
    case MEDIUM:
        scale = Vector2 (1.0f,1.0f);
        break;
    case SMALL:
        scale = Vector2(0.5f, 0.5f);
        break;
    }
    return scale;
}

void Asteroids::UpdateMovement(float dt) {

    position += GetForwardVector() * linearAccFactor * dt;
    rotation += angularVelocity * angularAccFactor * dt;

    GameObject::OutofBoundsTeleport();
}

Asteroids::~Asteroids() {

}