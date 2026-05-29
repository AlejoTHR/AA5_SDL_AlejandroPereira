#pragma once
#include "Bullets.h"

Bullets::Bullets(SDL_Renderer* renderer, Vector2 pos, Vector2 dir) :
	GameObject(renderer, Vector2(8, 8), Vector2(32, 36)){
	position = pos;
	bulletDirection = dir;
	bulletVelocity = 500;
}



void Bullets::UpdateMovement(float dt) {
	position += bulletDirection * bulletVelocity * dt;
	OutOfBoundsDestroy();
}

void Bullets::OutOfBoundsDestroy() {
	if (position.x > 810 || position.x < 0) {
		Bullets::~Bullets();
	}
	if (position.y < 0 || position.y > 610)
	{
		Bullets::~Bullets();
	}

}


Bullets::~Bullets() {

}