#pragma once
#include <memory>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

class Menu {
private:
	SDL_Renderer* renderer;
	SDL_Texture* background;
	TTF_Font* font;
	TTF_Font* fontOutline;
	SDL_Rect backgroundRect;
	SDL_Texture* playText;
	SDL_Texture* playTextOutline;
	SDL_Rect playTextRect;
	bool state;
	bool playTextState;
public:
	Menu(SDL_Renderer* renderer, const int width, const int height);
	void render();
	bool getState();
	~Menu();
};