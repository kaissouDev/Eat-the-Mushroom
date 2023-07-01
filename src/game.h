//
//  KaissouDev
//  (c) 2023  - *game.h
//

#include "main.h"

class Game{
    public:
        void run(SDL_Window* window, SDL_Renderer* renderer);
        void createwindow();
        void createrenderer(SDL_Renderer*& renderer, SDL_Window* window);
        void loadtexture();
        void log(SDL_Window* window, SDL_Renderer* renderer);
        void gameloop();
    private:
};