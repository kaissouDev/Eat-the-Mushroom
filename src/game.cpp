#include "game.hpp"
#include "main.hpp"
#include "player_rotation.hpp"
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
    PlayerRotation pr;
    Vector2 position = {0, 500};
    const float playerSpeed = 300.0f;
    float deltaTime = GetFrameTime();

    while(!WindowShouldClose()){
        BeginDrawing();
        //TitleScreen();

        drawPlayer(player, position, playerRotation);
        uint8_t playerDirection = pr.manageMovement( position, playerSpeed, deltaTime);

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