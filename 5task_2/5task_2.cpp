#include <iostream>
#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

const int WIDTH = 600, HEIGHT = 600;
const int framesPerMove = 30;

bool checkCollision(SDL_Rect& left, SDL_Rect& right) {
    if ((left.x > right.x && left.x < right.x + right.w) || (left.x + left.w > right.x && left.x + left.w < right.x + right.w)) {
        if ((left.y > right.y && left.y < right.y + right.h) || (left.y + left.h > right.y && left.y + left.h < right.y + right.h)) {
            return true;
        }
    }
    return false;
}

int main(int argc, char* argv[])
{
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    std::srand(std::time(nullptr));
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow("5task_2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, 0, 0);

    SDL_Surface* hedgehog = IMG_Load("sprites/sprite1.png");
    SDL_Surface* apple = IMG_Load("sprites/sprite2.png");
    if (!hedgehog || !apple) {
        std::cout << "Картинка не найдена!";
        exit(EXIT_FAILURE);
    }
    
    SDL_Texture* hedgehogTexture = SDL_CreateTextureFromSurface(renderer, hedgehog);
    SDL_Texture* appleTexture = SDL_CreateTextureFromSurface(renderer, apple);
    SDL_bool done = SDL_FALSE;

    SDL_Rect hedgehogPosition = { 50, 400, 150, 125 };

    struct appleData {
        SDL_Rect position = { 50, 50, 100, 80 };
        double rotation = 0;
    };

    std::vector <appleData> apples;

    int framesCounter = 0;
    bool hedgehogVector = false;
    bool stopHedgehog = false;
    while (!done) {
        SDL_Event event;
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        if (framesCounter == 0) {            
            for (int i = 0; i < apples.size(); i++) {
                    apples[i].position.y++;
                    apples[i].rotation++;
                if (checkCollision(apples[i].position, hedgehogPosition) || apples[i].position.y > 580) {
                    stopHedgehog = true;
                    apples.erase(apples.begin() + i);
                }
            }

            if (!stopHedgehog) {
                if (hedgehogVector) {
                    hedgehogPosition.x++;
                }
                else {
                    hedgehogPosition.x--;
                }
                if (hedgehogPosition.x > 450 || hedgehogPosition.x < 50) {
                    hedgehogVector = !hedgehogVector;
                }
            }
        }
        SDL_RendererFlip flip = hedgehogVector ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL;
        SDL_RenderCopyEx(renderer, hedgehogTexture, 0, &hedgehogPosition, 0, NULL, flip);

        for (int i = 0; i < apples.size(); i++) {
            SDL_RenderCopyEx(renderer, appleTexture, 0, &apples[i].position, apples[i].rotation, NULL, SDL_FLIP_NONE);
        }

        SDL_RenderPresent(renderer);
        framesCounter = (framesCounter + 1) % framesPerMove;
        while (SDL_PollEvent(&event)) {
            switch(event.type){
            case SDL_QUIT:
                done = SDL_TRUE;
                break;
            case SDL_KEYUP:
                if (event.key.keysym.sym == SDLK_RETURN) {
                    appleData newApple;
                    newApple.position.x += rand() % 400;
                    apples.push_back(newApple);
                }
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    done = SDL_TRUE;
                }
                break;
            }
        }
    }

    SDL_FreeSurface(hedgehog);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    return EXIT_SUCCESS;    
}