#include "game.hpp"
#include <iostream>

/*Game::Game()
{

}*/

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