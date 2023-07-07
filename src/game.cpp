#include "game.hpp"
#include "main.hpp"
#include "player_rotation.hpp"
#include <iostream>

void Game::DrawObject(){
    DrawText(TextFormat("Health = %d", Health), 269, 28, 42, WHITE);
    DrawTexture(mushroom, PosX, PosY, WHITE);
}

void Game::TitleScreen(){
    ClearBackground(BLUE);
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

    while(!WindowShouldClose()){
        BeginDrawing();
        float deltaTime = GetFrameTime();
        //TitleScreen();
        ClearBackground(BLUE);
        DrawObject();
        drawPlayer(player, position, playerRotation);
        uint8_t playerDirection = pr.manageMovement( position, playerSpeed, deltaTime);
        pr.manageRotation(  playerRotation, playerDirection );

        float distance = 0.0f;

        distance = sqrt(pow(position.x - PosX, 2) + pow(position.y - PosY, 2));
        if(distance < 50) {

            Health++;

            UnloadTexture(mushroom);

       
            PosX = GetRandomValue(0, GetScreenWidth() - mushroom.width);
            PosY = GetRandomValue(0, GetScreenHeight() - mushroom.height);

     
            mushroom = LoadTexture("res/mushroom.png");
                
        }

        EndDrawing();
    }
}

void Game::CreateWindow(){
    InitWindow(800, 600, "Eat-the-Mushroom");
    
    // set the window icon
    icon = LoadImage("res/icon.png");
    SetWindowIcon(icon);

    // check operating system
    #if defined(_WIN32) || defined(__linux__)
        mushroom = LoadTexture("res/mushroom.png");
        player = LoadTexture("res/player.png");
        fmt::print("Load from Windows or Linux");
    #elif defined(__APPLE__)
        mushroom = LoadTexture("../Resources/res/res/mushroom.png");
        player = LoadTexture("../Resources/res/res/player.png");
        fmt::print("Load from macOS");
    #endif
    
    Gameloop();
    UnloadTexture(player);
    UnloadTexture(mushroom);
    CloseWindow();
}

void Game::RunGame(){
    CreateWindow();
}