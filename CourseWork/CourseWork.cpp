#include <iostream>
#include <SDL/SDL.h>
#include "Level.h"

const int WIDTH = 640, HEIGHT = 640;

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow("tanks", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, 0, 0);
    if (!renderer) {
        std::cout << SDL_GetError();
        exit(EXIT_FAILURE);
    }
    Level* level = new Level(WIDTH, HEIGHT, renderer);

    SDL_bool done = SDL_FALSE;
    int i = 0;
    while (level) {
        SDL_Event event;
        if(i == 0)
            level->render();

        i = (i + 1) % 120;
    }
    delete level;
    SDL_DestroyWindow(window);
    return EXIT_SUCCESS;
}