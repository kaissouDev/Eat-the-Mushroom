//
//	*game.cpp
//
//	KaissouDev | Eat-the-Mushroom 
//	(c) 2023
//

#include "game.hpp"
#include "main.hpp"
#include "player_rotation.hpp"
#include <iostream>

void Game::DrawObject(){
    DrawText(TextFormat("Health = %d", Health), 269, 28, 42, WHITE);
    DrawTexture(mushroom, PosX, PosY, WHITE);
}

/*void Game::TitleScreen(){
    ClearBackground(BLUE);
    DrawText("Press Start To Play!", 50, 500, 64, WHITE);
    if(IsKeyPressed(KEY_SPACE)){
        fmt::print("space test");
        ClearBackground(WHITE);
    }
}*/

void Game::Gameloop(){
    PlayerRotation pr;
    Vector2 position = {0, 500};
    const float playerSpeed = 300.0f;
    Health = 0;
    PosX = GetRandomValue(0, GetScreenWidth() - mushroom.width);
    PosY = GetRandomValue(0, GetScreenHeight() - mushroom.height);
    int startTime = GetTime();


    while(!WindowShouldClose()){
        BeginDrawing();
        float deltaTime = GetFrameTime();
        
        //TitleScreen();
        ClearBackground(BLUE);
        DrawObject();
        drawPlayer(player, position, playerRotation);
        uint8_t playerDirection = pr.manageMovement( position, playerSpeed, deltaTime, player);
        pr.manageRotation(  playerRotation, playerDirection );

        float distance = 0.0f;
        
        int currentTime = GetTime() - startTime;
        int timeLeft = 10 - currentTime;
        if (timeLeft <= 0)
        {
            // Le timer est terminé, faire quelque chose ici
            // Par exemple, afficher un message à l'écran
            UnloadTexture(player);
            UnloadTexture(mushroom);
            ClearBackground(WHITE);
            DrawText("Game-Over ...", 269, 75, 42, RED);

        }
        else
        {
            // Afficher le temps restant
            DrawText(TextFormat("Timer : %02ds", timeLeft), 269, 75, 42, WHITE);
        }


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
    SetTraceLogLevel(LOG_NONE);
    
    InitWindow(800, 600, "Eat-the-Mushroom");
    
    // set the window icon
    icon = LoadImage("res/icon.png");
    SetWindowIcon(icon);

    mushroom = LoadTexture("res/mushroom.png");
    player = LoadTexture("res/player.png");
    
    Gameloop();
    UnloadTexture(player);
    UnloadTexture(mushroom);
    CloseWindow();
}

void Game::RunGame(){
    CreateWindow();
}