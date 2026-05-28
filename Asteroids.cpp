#pragma
#include "Asteroids.h"

Asteroids::Asteroids(SDL_Renderer* renderer, Vector2 pos, float rot, Vector2 scl) 
	: GameObject(GameObject(renderer, Vector2(40, 40), Vector2(40, 0))) {

	position = pos;
	rotation = rot;
	scale = scl;

	linearVelocity = Vector2();
	angularVelocity = 0.0f;

	linearAcceleration = Vector2();
	angularAcceleration = 0.0f;

	linearDrag = 1.2f;
	angularDrag = 6.0f;

	linearAccFactor = 500.f; // PIXELES / SECOND ^2
	angularAccFactor = 180000.0f; // GRADOS / SECOND ^2


}


void Asteroids::UpdateMovement(float dt) {

	Vector2 dir;

	float rotInRad = rotation * (M_PI / 180.f);
	dir.x = cos(rotInRad);
	dir.y = sin(rotInRad);


	linearAcceleration = dir * linearAccFactor;

}