#include <iostream>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <string>

const int WIDTH = 700, HEIGHT = 700;

double func(double x) {
    return (x * x - 3) / (x + 2);
}

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow("5task_1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, 0, 0);
    TTF_Init();

    SDL_Event windowEvent;
    SDL_Color blackColor = { 0, 0, 0, 255 };
    TTF_Font* Roboto = TTF_OpenFont("Roboto-Regular.ttf", 96);
    if (Roboto == NULL) {
        std::cout << "Font not found!";
        exit(EXIT_FAILURE);
    }

    

    SDL_bool done = SDL_FALSE;
    while (!done) {
        SDL_Event event;

        const int defaultX = 350;
        const int defaultY = 350;

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawLine(renderer, defaultX, defaultY - 300, defaultX, defaultY + 300);
        SDL_RenderDrawLine(renderer, defaultX - 300, defaultY, defaultX + 300, defaultY);
        SDL_RenderDrawLine(renderer, defaultX, defaultY - 300, defaultX + 10, defaultY - 300 + 10);
        SDL_RenderDrawLine(renderer, defaultX, defaultY - 300, defaultX - 10, defaultY - 300 + 10);
        SDL_RenderDrawLine(renderer, defaultX + 300, defaultY, defaultX + 300 - 10, defaultY + 10);
        SDL_RenderDrawLine(renderer, defaultX + 300, defaultY, defaultX + 300 - 10, defaultY - 10);


        for (int shiftX = 0; shiftX < 300; shiftX += 20) {
            SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Roboto, std::to_string(shiftX / 20).c_str(), blackColor);
            SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
            SDL_Rect dstrect = { defaultX + shiftX, defaultY - 10, 14, 14 };
            SDL_RenderCopy(renderer, message, NULL, &dstrect);

            SDL_RenderDrawLine(renderer, defaultX + shiftX, defaultY + 5, defaultX + shiftX, defaultY - 5);
        }
        for (int shiftX = -20; shiftX > -300; shiftX -= 20) {
            SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Roboto, std::to_string(shiftX / 20).c_str(), blackColor);
            SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
            SDL_Rect dstrect = { defaultX + shiftX, defaultY - 10, 14, 14 };
            SDL_RenderCopy(renderer, message, NULL, &dstrect);

            SDL_RenderDrawLine(renderer, defaultX + shiftX, defaultY + 5, defaultX + shiftX, defaultY - 5);
        }

        for (int shiftY = -20; shiftY > -300; shiftY -= 20) {
            SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Roboto, std::to_string(-shiftY / 20).c_str(), blackColor);
            SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
            SDL_Rect dstrect = { defaultX + 5, defaultY + shiftY, 14, 14 };
            SDL_RenderCopy(renderer, message, NULL, &dstrect);

            SDL_RenderDrawLine(renderer, defaultX - 5, defaultY + shiftY, defaultX + 5, defaultY + shiftY);
        }
        for (int shiftY = 0; shiftY < 300; shiftY += 20) {
            if (shiftY != 0) {
                SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Roboto, std::to_string(-shiftY / 20).c_str(), blackColor);
                SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
                SDL_Rect dstrect = { defaultX + 5, defaultY + shiftY, 14, 14 };
                SDL_RenderCopy(renderer, message, NULL, &dstrect);
            }

            SDL_RenderDrawLine(renderer, defaultX - 5, defaultY + shiftY, defaultX + 5, defaultY + shiftY);
        }

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        for (double shiftX = -1; shiftX <= 9; shiftX += 0.05) {
            SDL_Rect rect = { defaultX + shiftX * 20, defaultY - 20 * func(shiftX), 2, 2 };
            SDL_RenderDrawRect(renderer, &rect);
        }
        SDL_RenderPresent(renderer);

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                done = SDL_TRUE;
            }
        }
    }

    TTF_CloseFont(Roboto);
    TTF_Quit();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
