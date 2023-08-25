//
//	*game.cpp
//
//	KaissouDev | Eat-the-Mushroom 
//	(c) 2023
//

#include "game.hpp"
#include "main.hpp"
#include "player_rotation.hpp"
#include "level.hpp"
#include <iostream>

void Game::GameOver(){
    UnloadTexture(player);
    UnloadTexture(mushroom);
    ClearBackground(WHITE);
    DrawText("Game Over...", 269, 75, 42, RED); 
    CloseWindow();
}

void Game::flags(int argc, char* argv[]) { // add the --test argument
    // Votre code actuel pour la fonction flags ici

    // Parcourir les arguments de la ligne de commande
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg == "--test") {    
            printf("== running ... ==\n");
            printf("test coming soon ...\n");
            printf("\n");
            printf("== passed ! ==");
            CloseWindow();
        }
    }

    // Reste de votre code pour la fonction flags ici
}

void Game::DrawObject(){
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
    Level level;
    PlayerRotation pr;
    Vector2 position = { 0, 500 };
    const float playerSpeed = 300.0f;
    Health = 0;
    PosX = GetRandomValue(0, GetScreenWidth() - mushroom.width);
    PosY = GetRandomValue(0, GetScreenHeight() - mushroom.height);
    int startTime = GetTime();
    level.CurrentLevel = 1;
    GameRunning = true;
    float timeLeft = 10;
    Button buttonExit(DARKBLUE, BLACK, RED, { 300,350, 200,100},std::string("Exit"));
    Button buttonResume(DARKBLUE, BLACK, GREEN, { 300,200, 200,100 }, std::string("Resume"));
    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();
        BeginDrawing();
        //std::cout << Objective << std::endl;
        //TitleScreen();
        if (!GameRunning) {
            DrawRectangle(0, 0, 800, 600,{60,60,60,1});
            buttonExit.draw();
            buttonResume.draw();
            buttonExit.hover();
            buttonResume.hover();
            if (buttonExit.isClicked()) {
                break;
            }
            else if(buttonResume.isClicked()){
                GameRunning=true;
            }
            if (IsKeyPressed(KEY_ESCAPE)) {
                GameRunning = true;
            }
        }
        else {
            if (IsKeyPressed(KEY_ESCAPE)) {
                GameRunning = false;
            }
            level.CheckLevel();
            DrawObject();
            drawPlayer(player, position, playerRotation);
            uint8_t playerDirection = pr.manageMovement(position, playerSpeed, deltaTime, player);
            pr.manageRotation(playerRotation, playerDirection);

            float distance = 0.0f;

            timeLeft -= deltaTime;

            DrawText(TextFormat("Objective : %d", Objective), 269, 510, 42, WHITE);
            DrawText(TextFormat("Level : 1"), 269, 560, 32, WHITE);
            DrawText(TextFormat("Health = %d", Health), 269, 28, 42, WHITE);

            if (timeLeft >= 0) {
                Objective = 3;
                DrawText(TextFormat("Timer : %02ds", (int)timeLeft), 269, 75, 42, WHITE);

                if (Health >= 3) {
                    DrawText(TextFormat("Objective : ", Objective), 269, 510, 42, GREEN);
                }
                if (timeLeft <= 0 && Health >= 3) {
                    Objective + 2;
                    //++level.CurrentLevel;
                    //DrawText(TextFormat("Timer : %02ds", timeLeft), 269, 75, 42, WHITE);
                }
                if (timeLeft <= 0 && Health < 3) {
                    //WaitTime(5.0);
                    GameOver();
                }
            }



            distance = sqrt(pow(position.x - PosX, 2) + pow(position.y - PosY, 2));
            if (distance < 50) {

                Health++;

                UnloadTexture(mushroom);


                PosX = GetRandomValue(0, GetScreenWidth() - mushroom.width);
                PosY = GetRandomValue(0, GetScreenHeight() - mushroom.height);


                mushroom = LoadTexture("res/mushroom.png");

            }
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
    
    SetExitKey(0);

    Gameloop();
    UnloadTexture(player);
    UnloadTexture(mushroom);
    CloseWindow();
}

void Game::RunGame(){
    CreateWindow();
}