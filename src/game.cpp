//
//  KaissouDev
//  (c) 2023  - *game.cpp
//


#include "main.hpp"
#include "game.h"

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

    checkerror(window);
    SDL_Delay(3000);

    SDL_DestroyWindow(window);
}

void Game::checkerror(SDL_Window* window){
    if(window == nullptr){
        //print
    }
    else{
        fmt::print("hello fmt");
    }
}


void Game::run(){
    createwindow();
}