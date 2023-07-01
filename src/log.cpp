#include "main.h"
#include "game.h"

void Game::log(SDL_Window* window, SDL_Renderer* renderer){
    if(window == nullptr){
        fmt::print("[error] the window has encountered an initialisation problem .");
    }
    else{
        fmt::print("[success] Window creation successful");
    }

    if (renderer == nullptr) {
        fmt::print("[error] The renderer has encountered an initialization problem.");
    }
    else {
        fmt::print("[success] Renderer creation successful.");
    }
}

