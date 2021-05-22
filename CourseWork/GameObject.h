#pragma once
#include "Level.h"
struct LevelData;

class GameObject {
protected:
	struct LevelData* levelData;
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

	bool checkForCollision(const int& leftX, const int& leftY) {
		int rightX = leftX + this->position.rect.w;
		int rightY = leftY + this->position.rect.h;
		if (rightX < 0 || rightX > levelData->windowWidth || rightY < 0 || rightY > levelData->windowHeight) {
			return false;
		}
		if (leftX < 0 || leftX > levelData->windowWidth || leftY < 0 || leftY > levelData->windowHeight) {
			return false;
		}
		if (levelData->colliderTileMap[leftY / levelData->tileHeight][leftX / levelData->tileWidth]) {
			return false;
		}
		if (levelData->colliderTileMap[(leftY + position.rect.h - 1) / levelData->tileHeight][leftX / levelData->tileWidth]) {
			return false;
		}
		if (levelData->colliderTileMap[(leftY + position.rect.h - 1) / levelData->tileHeight][(leftX + position.rect.w - 1) / levelData->tileWidth]) {
			return false;
		}
		if (levelData->colliderTileMap[leftY / levelData->tileHeight][(leftX + position.rect.w - 1) / levelData->tileWidth]) {
			return false;
		}
		return true;
	}
public:
	GameObject(SDL_Renderer* renderer, const int x, const int y, const int w, const int h, LevelData* levelData) {
		currentImgState = 0;
		isCollided = false;
		this->texture = nullptr;
		this->renderer = renderer;
		position.rect.x = x;
		position.rect.y = y;
		position.rect.w = w;
		position.rect.h = h;
		blit = { 0, 0, w, h };

		this->levelData = levelData;
	}
	GameObject(SDL_Renderer* renderer, SDL_Surface* surface, const int x, const int y, const int w, const int h, LevelData* levelData) : GameObject(renderer, x, y, w, h, levelData) {
		this->texture = SDL_CreateTextureFromSurface(renderer, surface);
	}
	GameObject(SDL_Renderer* renderer, SDL_Texture* texture, const int x, const int y, const int w, const int h, LevelData* levelData) : GameObject(renderer, x, y, w, h, levelData) {
		this->texture = texture;
	}
	virtual void render() {
		SDL_RenderCopyEx(renderer, texture, &blit, &(position.rect), position.rotation, nullptr, position.flip);
	}
	void moveObject(const int x, const int y, const int rotation) {
		if (isCollided && !checkForCollision(x, y)) {
			return;
		}
		position.rect.x = x;
		position.rect.y = y;
		position.rotation = rotation;	
	}
	~GameObject() {
		SDL_DestroyTexture(texture);
	}
};