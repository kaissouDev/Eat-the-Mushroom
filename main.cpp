/******************************************
*   create by RAYLIB 4.5 || ZLIB license
*******************************************
*   (c) Kaissou || All right reserved!
*   main.cpp || main.hpp
*   C++ project
*******************************************
*       2023 || 08/04/2023
*******************************************/

#include <raylib.h>
#include "include/main.hpp"

/*void load(){

    (a mettre plus tard)
}*/



// fonction main de base
int main(){

    InitWindow(800,600, "mon jeux");

    AfficherConsole();

    // load des fichiers / audios
    Font font = LoadFont("font/Super-Mario-World.ttf");

    
    // game loop
    while(!WindowShouldClose()){
        BeginDrawing();
        SetTraceLogLevel(LOG_NONE);
            ClearBackground(WHITE);
            DrawTextEx(font ,"Salut tout le monde", (Vector2) {225, 246}, font.baseSize, 2, BLACK );
        EndDrawing();
    }


    // unload et fermetture de la fenetre
    UnloadFont(font);
    CloseWindow();
}