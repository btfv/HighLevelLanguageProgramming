#pragma once
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>
#include <vector>
#include <SDL/SDL_image.h>

struct LevelData {
	int windowWidth;
	int windowHeight;
	int tileHeight;
	int tileWidth;
	std::vector<std::vector<bool>> colliderTileMap;
};

#include "GameObject.h"
#include "Player.h"

class Level {
private:
	SDL_Renderer* renderer;
	std::vector <GameObject*> gameObjects;
	Player* player;
	GameObject* background;
	LevelData levelData;

	void drawGrid() {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

		for (int i = 0; i <= levelData.windowWidth / levelData.tileWidth; i++) {
			SDL_RenderDrawLine(renderer, i * levelData.tileWidth, 0, i * levelData.tileWidth, levelData.windowHeight);
		}
		for (int i = 0; i <= levelData.windowHeight / levelData.tileHeight; i++) {
			SDL_RenderDrawLine(renderer, 0, i * levelData.tileHeight, levelData.windowWidth, i * levelData.tileHeight);
		}
		SDL_Rect rect;
		for (int i = 0; i < levelData.windowWidth / levelData.tileWidth; i++) {
			for (int j = 0; j < levelData.windowHeight / levelData.tileHeight; j++) {
				if (levelData.colliderTileMap[i][j]) {
					rect = { j * levelData.tileWidth, i * levelData.tileHeight, levelData.tileWidth, levelData.tileHeight };
					SDL_RenderFillRect(renderer, &rect);
				}
			}
		}
	}
public:
	Level(const int windowWidth, const int windowHeight, SDL_Renderer* renderer) {
		this->levelData.windowHeight = windowHeight;
		this->levelData.windowWidth = windowWidth;
		this->renderer = renderer;
		this->levelData.tileHeight = 32;
		this->levelData.tileWidth = 32;
		setup();
	}
	void setup() {
		this->levelData.colliderTileMap = std::vector<std::vector<bool>>(this->levelData.windowHeight / this->levelData.tileHeight + 1, std::vector<bool>(this->levelData.windowWidth / this->levelData.tileWidth + 1, false));


		for (int i = 4; i <= 19; i++) {
			this->levelData.colliderTileMap[3][i] = true;
		}


		SDL_Surface* backgroundSurface = SDL_LoadBMP("498_Tanks_sprites/gfx/ground/ground02.bmp");
		if (!backgroundSurface) {
			std::cout << SDL_GetError();
			exit(EXIT_FAILURE);
		}
		background = new GameObject(renderer, backgroundSurface, 0, 0, this->levelData.windowWidth, this->levelData.windowHeight, &levelData);
		SDL_FreeSurface(backgroundSurface);

		Tank* tank = new Tank(renderer, 32, 32, 32, 32, &levelData);
		player = new Player(tank);
	}
	void render() {
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
		
		drawGrid();

		//background->render();
		player->render();

		SDL_RenderPresent(renderer);
	}
	~Level() {
		delete player;
		SDL_DestroyRenderer(renderer);
	}

	
};