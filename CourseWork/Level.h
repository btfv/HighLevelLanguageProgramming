#pragma once
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>
#include <vector>
#include <SDL/SDL_image.h>
#include "GameObject.h"
#include "Player.h"

class Level {
private:
	int windowWidth;
	int windowHeight;
	SDL_Renderer* renderer;
	std::vector <GameObject*> gameObjects;
	Player* player;
	GameObject* background;
public:
	Level(const int windowWidth, const int windowHeight, SDL_Renderer* renderer) {
		this->windowHeight = windowHeight;
		this->windowWidth = windowWidth;
		this->renderer = renderer;
		setup();
	}
	void setup() {
		SDL_Surface* backgroundSurface = SDL_LoadBMP("498_Tanks_sprites/gfx/ground/ground02.bmp");
		if (!backgroundSurface) {
			std::cout << SDL_GetError();
			exit(EXIT_FAILURE);
		}
		background = new GameObject(renderer, backgroundSurface, 0, 0, windowWidth, windowHeight);
		SDL_FreeSurface(backgroundSurface);

		Tank* tank = new Tank(renderer, 32, 32, 32, 32);
		player = new Player(tank);
	}
	void render() {
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);

		background->render();
		player->render();

		SDL_RenderPresent(renderer);
	}
	~Level() {
		delete player;
		SDL_DestroyRenderer(renderer);
	}
};