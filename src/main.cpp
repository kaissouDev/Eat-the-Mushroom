//
//  KaissouInc / KadjFoundation
//          (c) 2023
//  ---------------------------
//      * main.cpp
//

// Example program:
// Using SDL2 to create an application window

#include <SDL3/SDL.h>
#include <stdio.h>
#include <fmt/core.h>

int main(int argc, char* argv[]) {

    SDL_Window *window;                    // Declare a pointer

    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2
    SDL_Renderer* renderer;
    SDL_Event event;
    int isRunning = 1;

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "Eat-The-Mushroom (5.X dev)",                  // window title
        800,                               // width, in pixels
        600,                               // height, in pixels
        SDL_WINDOW_OPENGL                 // flags - see below
    );


    renderer = SDL_CreateRenderer(window, NULL, 0);

    while (isRunning) {
        // Gestion des événements
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                isRunning = 0;
            }
        }
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 0, 161, 255);
        SDL_RenderPresent(renderer);
    }
    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}