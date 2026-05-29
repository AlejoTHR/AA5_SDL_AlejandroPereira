#pragma once
#include "Spaceship.h"
#include "GameplayScene.h"


Spaceship::Spaceship(SDL_Renderer* renderer, Vector2 pos, float rot, Vector2 scl, GameplayScene* shipScene) 
	: GameObject(renderer, Vector2(32,40), Vector2(0,0)) {

	position = pos;
	rotation = rot;
	scale = scl;
	Render = renderer;
	ShipScene = shipScene;

	linearVelocity = Vector2();
	angularVelocity = 0.0f;

	linearAcceleration = Vector2();
	angularAcceleration = 0.0f;

	linearDrag = LINEAR_DRAG;
	angularDrag = ANGULAR_DRAG;

	linearAccFactor = SHIP_LIN_ACC_FACTOR; // PIXELES / SECOND ^2
	angularAccFactor = SHIP_ANG_ACC_FACTOR; // GRADOS / SECOND ^2


}

unsigned short Spaceship::GetLifes() {
	return lifes;
}
void Spaceship::ShipDamaged() {
	lifes--;
}

void Spaceship::UpdateMovement(float dt){
	
	linearAcceleration = Vector2();

	angularAcceleration = 0.0f;
	if (IM.GetKey(SDLK_d, HOLD))
	{
		angularAcceleration = angularAccFactor * dt;
	}
	if (IM.GetKey(SDLK_a, HOLD))
	{
		angularAcceleration = -angularAccFactor * dt;
	}

	if (IM.GetKey(SDLK_w, HOLD))
	{
		linearAcceleration = GetForwardVector() * linearAccFactor;
	}

	if (IM.GetKey(SDLK_SPACE, DOWN))
	{
		Bullets* newBullet = new Bullets(Render, position, GetForwardVector());
		ShipScene->InstantiateObject(newBullet);
	}
	GameObject::OutofBoundsTeleport();
	GameObject::UpdateMovement(dt);
}
