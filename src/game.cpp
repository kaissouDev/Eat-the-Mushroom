//
//  KaissouDev
//  (c) 2023  - *game.cpp
//


#include "main.h"
#include "game.h"

void Game::createrenderer(SDL_Renderer*& renderer, SDL_Window* window){
    renderer = SDL_CreateRenderer(window, "direct3d11", SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void Game::createwindow(){
    //Declare pointers
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;
    SDL_Init(SDL_INIT_VIDEO); 

    window = SDL_CreateWindow(
        "Eat-the-mushroom (dev)",
        800,
        600,
        0
    );

    createrenderer(renderer, window);
    log(window, renderer);

    SDL_SetRenderDrawColor(renderer, 26, 118, 255, 0.83);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    SDL_Delay(3000);

    SDL_DestroyWindow(window);
}



void Game::run(){
    createwindow();
}