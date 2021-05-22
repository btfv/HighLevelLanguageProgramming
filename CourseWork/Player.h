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
				switch (event.key.keysym.sym) {
				case SDLK_UP:
				case SDLK_w:
					tankObject->moveUp();
					break;
				case SDLK_RIGHT:
				case SDLK_d:
					tankObject->moveRight();
					break;
				case SDLK_LEFT:
				case SDLK_a:
					tankObject->moveLeft();
					break;
				case SDLK_DOWN:
				case SDLK_s:
					tankObject->moveDown();
					break;
				case SDLK_SPACE:
					tankObject->strike();
					break;
				}
				break;
			}
		}
		tankObject->render();
	}
};
