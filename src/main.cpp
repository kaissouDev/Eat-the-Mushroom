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

//load textures

using namespace std;

int main(int argc, char ** argv){


    SetTraceLogLevel(LOG_ALL);
    fmt::print("Hello Window :) !");
    InitWindowClass initwindow;
    initwindow.InitWindowFunctions();
    InitClass initclass;

    initclass.GameStarted = false;
    while(!WindowShouldClose()){
        BeginDrawing();
        if(initclass.GameStarted == false){
            ClearBackground(BLACK);
            initclass.TitleScreen();
        }
        else if(initclass.GameStarted == true)
        {
            ClearBackground(WHITE);
            DrawText(TextFormat("Vie = %d", initclass.vie), 269, 28, 42, BLACK);
            DrawTexture(initclass.mushroom, initclass.PosX, initclass.PosY, WHITE);
            DrawTexture(initclass.player, 0, 500, WHITE);
        }
        EndDrawing();
    }
    UnloadTexture(initclass.mushroom);
    CloseWindow();
    return 0;
}