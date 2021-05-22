#pragma once
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "GameObject.h"
#include "Bullet.h"


class Tank : public GameObject {
protected:
	int tankSpeed;
	std::vector<Bullet*> bullets;
public:
	Tank(SDL_Renderer* renderer, const int x, const int y, const int w, const int h, LevelData* levelData) : GameObject(renderer, x, y, w, h, levelData) {
		currentImgState = 0;

		SDL_Surface* grid = IMG_Load("498_Tanks_sprites/gfx/tanks/pla1.png");
		SDL_DestroyTexture(texture);
		texture = SDL_CreateTextureFromSurface(renderer, grid);
		SDL_FreeSurface(grid);

		tankSpeed = 2;

		isCollided = true;
	}
	void moveUp() {
		currentImgState = (currentImgState + 1) % 4;
		blit.x = currentImgState * 32;
		moveObject(position.rect.x, position.rect.y - tankSpeed, -90);
	}
	void moveRight() {
		currentImgState = (currentImgState + 1) % 4;
		blit.x = (currentImgState + 1) % 4 * 32;
		moveObject(position.rect.x + tankSpeed, position.rect.y, 0);
	}
	void moveLeft() {
		currentImgState = (currentImgState + 1) % 4;
		blit.x = (currentImgState + 1) % 4 * 32;
		moveObject(position.rect.x - tankSpeed, position.rect.y, 180);
	}
	void moveDown() {
		currentImgState = (currentImgState + 1) % 4;
		blit.x = (currentImgState + 1) % 4 * 32;
		moveObject(position.rect.x, position.rect.y + tankSpeed, 90);
	}
	virtual void render() {
		SDL_RenderCopyEx(renderer, texture, &blit, &(position.rect), position.rotation, nullptr, position.flip);

		for (int i = 0; i < bullets.size(); i++) {
			bullets[i]->moveForward();
			bullets[i]->render();
		}
	}
	void strike() {
		Bullet* newBullet = new Bullet(renderer, position.rect.x, position.rect.y + 10, 32, 10, position.rotation, levelData);
		bullets.push_back(newBullet);
	}
};