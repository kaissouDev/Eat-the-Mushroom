#include "game.hpp"
#include "main.hpp"
#include <iostream>

void Game::TitleScreen(){
    ClearBackground(BLACK);
    DrawText("Press Start To Play!", 50, 500, 64, WHITE);
    if(IsKeyPressed(KEY_SPACE)){
        fmt::print("space test");
        ClearBackground(WHITE);
    }
}

void Game::Gameloop(){
    while(!WindowShouldClose()){
        BeginDrawing();
        TitleScreen();
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