#pragma once
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "GameObject.h"

class Bullet : public GameObject {
public:
	Bullet(SDL_Renderer* renderer, const int x, const int y, const int w, const int h, const int rotation, LevelData* levelData) : GameObject(renderer, x, y, w, h, levelData) {
		currentImgState = 0;
		SDL_Surface* grid = IMG_Load("498_Tanks_sprites/gfx/bullet/bullet02.png");
		SDL_DestroyTexture(texture);
		texture = SDL_CreateTextureFromSurface(renderer, grid);
		SDL_FreeSurface(grid);
		isCollided = true;

		position.rotation = rotation;
	}
	void moveForward() {
		currentImgState = (currentImgState + 1) % 8;
		blit.x = currentImgState * 32;
		int moveX = 0;
		int moveY = 0;
		switch (position.rotation) {
		case 0:
			moveX = 1;
			moveY = 0;
			break;
		case 90:
			moveX = 0;
			moveY = 1;
			break;
		case 180:
			moveX = -1;
			moveY = 0;
			break;
		case -90:
		case 270:
			moveX = 0;
			moveY = -1;
			break;
		}
		moveObject(position.rect.x + moveX, position.rect.y + moveY, position.rotation);
	}
};