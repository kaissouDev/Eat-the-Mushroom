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


using namespace std;

int main(){
    SetTraceLogLevel(LOG_NONE);
    Init init;
    fmt::print("Hello Window :) !");
    init.InitWindowFunctions();
    init.LoadTextureFunctions();


    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Hello World Raylib...", 0, 0, 64, WHITE);
        DrawText("Start", 0, 200, 32, WHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}