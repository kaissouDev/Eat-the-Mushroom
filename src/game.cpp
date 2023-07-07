#include "game.hpp"
#include "main.hpp"
#include <iostream>


void Game::Gameloop(){
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);
        EndDrawing();
    }
}

void Game::CreateWindow(){
    InitWindow(800, 600, "Eat-the-Mushroom");
    Gameloop();
    CloseWindow();
}

void Game::RunGame(){
    CreateWindow();
}