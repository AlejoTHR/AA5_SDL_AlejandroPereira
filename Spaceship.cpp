#pragma once
#include "SpaceshipClass.h"

Spaceship::Spaceship(SDL_Renderer* renderer, Vector2 pos, float rot, Vector2 scl) : GameObject(renderer, Vector2(32,40), Vector2(0,0)) {

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



void Spaceship::UpdateMovement(float dt){
	
	linearAcceleration = Vector2();
	if(IM.GetKey(SDLK_w, HOLD))
	{
		Vector2 dir;
		float rotInRad = rotation * (M_PI / 180.f);
		dir.x = cos(rotation);
		dir.y = sin(rotation);


		linearAcceleration = dir * angularAcceleration;

	}

	angularAcceleration = 0.0f;
	if (IM.GetKey(SDLK_d, HOLD))
	{

		angularAcceleration = angularAccFactor * dt;
	}
	if (IM.GetKey(SDLK_a, HOLD))
	{

		angularAcceleration = -angularAccFactor * dt;
	}


	GameObject::UpdateMovement(dt);


}