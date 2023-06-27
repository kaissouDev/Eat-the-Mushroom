//
//  KaissouInc / KadjFoundation
//          (c) 2023
//  ---------------------------
//      * main.cpp
//

// Example program:
// Using SDL2 to create an application window

#include "SDL.h"
#include <stdio.h>
#include <fmt/core.h>
#include <boxer.h>

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


    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        boxer::show("Could not create window", "Window error");
        return 1;
    }

    while (isRunning) {
        // Gestion des événements
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                isRunning = 0;
            }
        }

        // Effacer l'écran
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 0, 161, 255);
        // Mettre à jour l'affichage
        SDL_RenderPresent(renderer);
    }
    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}