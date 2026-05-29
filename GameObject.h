#pragma once
#include "Utils.h"
#include "Cons.h"
#include "SDL.h"
#include <SDL_image.h>
#include <cmath>
#include <iostream>


class GameObject 
{
protected:
	// RENDERING
	Vector2 position;
	float rotation;
	Vector2 scale;
	Vector2	sizetext; // Width|height of Cut from Texture;
	Vector2 padding; // Pos of texture cut
	bool isActive = true;

	float radius;

	SDL_Texture* texture;

	SDL_Texture* CreateTexture(SDL_Renderer* renderer);

	// MOVEMENT
	Vector2 linearVelocity;
	float angularVelocity;

	Vector2 linearAcceleration;
	float angularAcceleration;

	float linearDrag;
	float angularDrag;

	float linearAccFactor;
	float angularAccFactor;

	virtual void UpdateMovement(float dt);

public:
	GameObject(SDL_Renderer* renderer, Vector2 textSize, Vector2 textPadding);
	void Render(SDL_Renderer* renderer);
	void Update(float dt);

	Vector2 GetForwardVector();

	void OutofBoundsTeleport();

	bool GetIsActive();

	void SetIsActive(bool isactive);

	Vector2 GetPosition();

	Vector2 GetScale();

	float GetRadius();

	bool CollidesWith(GameObject* other);

};