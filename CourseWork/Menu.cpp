#include "Menu.h"
#include <iostream>

Menu::Menu(SDL_Renderer* renderer, const int width, const int height) {
	this->renderer = renderer;

	SDL_Surface* surface = IMG_Load("498_Tanks_sprites/gfx/gui/i_background.jpg");
	if (!surface) {
		std::cout << IMG_GetError();
		exit(EXIT_FAILURE);
	}
	background = SDL_CreateTextureFromSurface(renderer, surface);
	backgroundRect = { 0, 0, width, height };
	SDL_FreeSurface(surface);
	font = TTF_OpenFont("Pixeboy-z8XGD.ttf", 72);
	fontOutline = TTF_OpenFont("Pixeboy-z8XGD.ttf", 72);
	TTF_SetFontOutline(fontOutline, 1);

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, "Play!", { 0, 0, 0, 255 });
	playText = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	playTextRect = { width / 2 - 75, height / 2 - 75 / 2, 150, 75 };
	SDL_FreeSurface(surfaceMessage);

	surfaceMessage = TTF_RenderText_Solid(fontOutline, "Play!", { 0, 0, 0, 255 });
	playTextOutline = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	SDL_FreeSurface(surfaceMessage);

	state = 0;
	playTextState = 0;
}
void Menu::render() {
	SDL_RenderCopy(renderer, background, nullptr, &backgroundRect);
	if (playTextState == 0) {
		SDL_RenderCopy(renderer, playText, nullptr, &playTextRect);
	}
	else {
		SDL_RenderCopy(renderer, playTextOutline, nullptr, &playTextRect);
	}
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			exit(EXIT_SUCCESS);
			break;
		case SDL_KEYUP:
			if (event.key.keysym.scancode == SDL_SCANCODE_RETURN) {
				playTextState = 0;
				state = 1;
			}
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.scancode == SDL_SCANCODE_RETURN) {
				playTextState = 1;
			}
			break;
		}
	}
}

bool Menu::getState() {
	return this->state;
}

Menu::~Menu() {
	SDL_DestroyTexture(playText);
	SDL_DestroyTexture(playTextOutline);
	TTF_CloseFont(font);
	TTF_CloseFont(fontOutline);
	SDL_DestroyTexture(background);
}