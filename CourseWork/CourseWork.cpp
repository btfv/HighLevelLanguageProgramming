#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "Level.h"
#include "Menu.h"

const int WIDTH = 640, HEIGHT = 640;

enum class GameMode { Menu = 1, Level_1 = 2, Level_2 = 3 };


int main(int argc, char* argv[])
{
    std::srand(std::time(nullptr));
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    SDL_Window* window = SDL_CreateWindow("tanks", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, 0, 0);
    if (!renderer) {
        std::cout << SDL_GetError();
        exit(EXIT_FAILURE);
    }
    std::unique_ptr<Menu> menu = std::unique_ptr<Menu>(new Menu(renderer, WIDTH, HEIGHT));
    Level* level = nullptr;

    GameMode mode = GameMode::Menu;

    SDL_bool done = SDL_FALSE;
    while (!done) {
        SDL_Event event;
        SDL_Delay(10);

        switch (mode) {
        case GameMode::Menu:
            menu->render();
            break;
        case GameMode::Level_1:
            level->render();
            break;
        }

        if (menu->getState() && !level) {
            mode = GameMode::Level_1;
            level = new Level(WIDTH, HEIGHT, renderer);
        }

        SDL_RenderPresent(renderer);
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                done = SDL_TRUE;
                break;
            }
        }
    }
    delete level;
    SDL_DestroyWindow(window);
    return EXIT_SUCCESS;
}