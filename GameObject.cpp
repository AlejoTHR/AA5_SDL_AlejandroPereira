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

Vector2 GameObject::GetForwardVector() {
	Vector2 dir;
	float rotInRad = rotation * (M_PI / 180.f);
	dir.x = cos(rotInRad);
	dir.y = sin(rotInRad);
	return dir;
}


void GameObject::Render(SDL_Renderer* renderer) {
	SDL_Rect source{ padding.x,padding.y,
		size.x, size.y
	};

	SDL_Rect destination{ position.x - size.x/2, position.y - size.y / 2,
		source.w * scale.x, source.h * scale.y

	};
	//SDL_RenderCopy(renderer, texture, &source, &destination); SOLO PARA COSAS ESTÁTICAS
	SDL_RenderCopyEx(renderer, texture, &source, &destination, 90.f + rotation, NULL, SDL_FLIP_NONE);
};

void GameObject::OutofBoundsTeleport() {
	if (position.x > WINDOW_WIDTH+10) {
		position.x = 0;
	}
	
	if (position.x < 0){
		position.x = WINDOW_WIDTH;
	}

	if (position.y > WINDOW_HEGITH+10){
		position.y = 0;
	}
	
	if (position.y < 0){
		position.y = WINDOW_HEGITH;
	}

}



void GameObject::Update(float dt) {
	UpdateMovement(dt);

}