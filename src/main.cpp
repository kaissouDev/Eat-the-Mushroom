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

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        
        initclass.TitleScreen();

        DrawTexture(initclass.texture1, 0, 0, WHITE);
        EndDrawing();
    }
    UnloadTexture(initclass.texture1);
    CloseWindow();
    return 0;
}