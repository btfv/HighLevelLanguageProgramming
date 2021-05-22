#pragma once

class GameObject {
protected:
	bool isCollided;
	SDL_Renderer* renderer;
	struct Position {
		SDL_Rect rect;
		int rotation;
		SDL_RendererFlip flip = SDL_FLIP_NONE;
	} position;
	SDL_Rect blit;
	SDL_Texture* texture;
	int currentImgState;
public:
	GameObject(SDL_Renderer* renderer, const int x, const int y, const int w, const int h) {
		currentImgState = 0;
		isCollided = false;
		this->texture = nullptr;
		this->renderer = renderer;
		position.rect.x = x;
		position.rect.y = y;
		position.rect.w = w;
		position.rect.h = h;
		blit = { 0, 0, w, h };
	}
	GameObject(SDL_Renderer* renderer, SDL_Texture* texture, const int x, const int y, const int w, const int h) {
		currentImgState = 0;
		isCollided = false;
		this->texture = texture;
		this->renderer = renderer;
		position.rect.x = x;
		position.rect.y = y;
		position.rect.w = w;
		position.rect.h = h;
		blit = { 0, 0, w, h };
	}
	GameObject(SDL_Renderer* renderer, SDL_Surface* surface, const int x, const int y, const int w, const int h) {
		currentImgState = 0;
		isCollided = false;
		this->texture = SDL_CreateTextureFromSurface(renderer, surface);
		this->renderer = renderer;
		position.rect.x = x;
		position.rect.y = y;
		position.rect.w = w;
		position.rect.h = h;
		blit = { 0, 0, w, h };
	}
	virtual void render() {
		SDL_RenderCopyEx(renderer, texture, &blit, &(position.rect), position.rotation, nullptr, position.flip);
	}
	void moveObject(const int x, const int y, const int rotation) {
		position.rect.x = x;
		position.rect.y = y;
		position.rotation = rotation;	
	}
	~GameObject() {
		SDL_DestroyTexture(texture);
	}
};