#include "GameObject.h"

SDL_Texture* GameObject::CreateTexture(SDL_Renderer* renderer) {

	SDL_Surface* surf = IMG_Load("Assets/asteroids_spritesheet.jpg");

	if (surf == nullptr) {
		std::cout << "Error creating surf: " << SDL_GetError();
	}
	SDL_Texture* textureTmp = SDL_CreateTextureFromSurface(renderer, surf);

	if (textureTmp == nullptr) {
		std::cout << "Error creating texture: " << SDL_GetError();
	}
	SDL_FreeSurface(surf);

	return textureTmp;
}

void GameObject::UpdateMovement(float dt) {

	// UPDATE VELOCITY AND ANGL VELOCITY
	linearVelocity = linearVelocity + linearAcceleration * dt;
	angularVelocity = angularVelocity + angularAcceleration * dt;

	// APLY DRAGG
	linearVelocity = linearVelocity * (1.0 - linearDrag * dt);
	angularVelocity = angularVelocity * (1.0 - angularDrag * dt);

	// UPDATE POSITION
	position = position + linearVelocity * dt;
	rotation = rotation + angularVelocity * dt;

}



GameObject::GameObject(SDL_Renderer* renderer, Vector2 textSize, Vector2 textPadding) {
	position = Vector2(0,0);
	rotation = 0.f;
	scale = Vector2(1.f, 1.f);

	texture = CreateTexture(renderer);
	size = textSize;
	padding = textPadding;



}

void GameObject::Render(SDL_Renderer* renderer) {
	SDL_Rect source{ padding.x,padding.y,
		size.x, size.y
	};

	SDL_Rect destination{ position.x, position.y,
		source.w * scale.x, source.h * scale.y

	};
	//SDL_RenderCopy(renderer, texture, &source, &destination); SOLO PARA COSAS ESTÁTICAS
	SDL_RenderCopyEx(renderer, texture, &source, &destination, 90.f + rotation, NULL, SDL_FLIP_NONE);
};

void GameObject::Update(float dt) {
	UpdateMovement(dt);

}