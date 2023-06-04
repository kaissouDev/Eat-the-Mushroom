/******************************************
*          Eat The Mushroom
*               MIT
*******************************************
*   (c) Kaissou || All right reserved!
*              main.cpp
*******************************************
*             03/06/2023
*******************************************/


#include "init.hpp"
#include "input.hpp"

//load textures

using namespace std;

int main(int argc, char ** argv){

    SetTraceLogLevel(LOG_ALL);
    fmt::print("Hello Window :) !");
    InitWindowClass initwindow;
    initwindow.InitWindowFunctions();
    InitClass initclass;
    Move move;

    float distance = 0.0f;

    initclass.GameStarted = false;

    Vector2 position = {0, 500};
    const float playerSpeed = 300.0f;

    while(!WindowShouldClose()){
        BeginDrawing();
        if(initclass.GameStarted == false){
            ClearBackground(BLACK);
            initclass.TitleScreen();
        }
        else if(initclass.GameStarted == true)
        {
            float deltaTime = GetFrameTime();
            ClearBackground(WHITE);
            DrawText(TextFormat("Vie = %d", initclass.vie), 269, 28, 42, BLACK);
            DrawTexture(initclass.mushroom, initclass.PosX, initclass.PosY, WHITE);
            DrawTexture(initclass.player, position.x, position.y, WHITE);
        
            if (IsKeyDown(KEY_RIGHT)) position.x += playerSpeed * deltaTime;
            if (IsKeyDown(KEY_LEFT)) position.x -= playerSpeed * deltaTime;
            if (IsKeyDown(KEY_DOWN)) position.y += playerSpeed * deltaTime;
            if (IsKeyDown(KEY_UP)) position.y -= playerSpeed * deltaTime;
            
            //only work on windows!
            distance = sqrt(pow(position.x - initclass.PosX, 2) + pow(position.y - initclass.PosY, 2));
            if(distance < 50) {

                initclass.vie++;

                UnloadTexture(initclass.mushroom);

       
                initclass.PosX = GetRandomValue(0, GetScreenWidth() - initclass.mushroom.width);
                initclass.PosY = GetRandomValue(0, GetScreenHeight() - initclass.mushroom.height);

     
                initclass.mushroom = LoadTexture("res/mushroom.png");
                
            }
        
        }
        EndDrawing();
    }
    UnloadTexture(initclass.mushroom);
    CloseWindow();
    return 0;
}