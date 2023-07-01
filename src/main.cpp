//
//  KaissouDev
//  (c) 2023  - *main.cpp
//

#include "main.h"
#include "game.h"
#include "color.h"


int main(int argc, char** argv[], SDL_Window* window, SDL_Renderer* renderer) {
    
    Game game;
    game.run(window, renderer);
    
}