#pragma once
#include "Tank.h"

class Player {
private:
	Tank* tankObject;
public:
	Player(Tank* tankObject) {
		this->tankObject = tankObject;
	}

	void render() {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_UP) {
					tankObject->moveUp();
				}
				if (event.key.keysym.sym == SDLK_RIGHT) {
					tankObject->moveRight();
				}
				if (event.key.keysym.sym == SDLK_LEFT) {
					tankObject->moveLeft();
				}
				if (event.key.keysym.sym == SDLK_DOWN) {
					tankObject->moveDown();
				}
				if (event.key.keysym.sym == SDLK_SPACE) {
					tankObject->strike();
				}
				break;
			}
		}
		tankObject->render();
	}
};
