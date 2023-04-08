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

/*void deplacement(){


}*/

// fonction main de base
int main(){

    InitWindow(800,600, "mon jeux");

    //AfficherConsole();

    // load des fichiers / audios

    Vector2 position = { 356, 250 };

    Texture2D player = LoadTexture("res/player.png");
    Texture2D  mushroom = LoadTexture("res/mushroom.png");
    Font font = LoadFont("font/Gotham-Medium.otf");
    int PosX = GetRandomValue(0, GetScreenWidth() - mushroom.width);
    int PosY = GetRandomValue(0, GetScreenHeight() - mushroom.height);
    const float playerSpeed = 500.0f;
    int vie = 0;
    // game loop
    while(!WindowShouldClose()){
        BeginDrawing();
        SetTraceLogLevel(LOG_NONE);
            ClearBackground(WHITE);
            
            float deltaTime = GetFrameTime();

            DrawTextEx(font, TextFormat("Vie = %d", vie), (Vector2) {269, 28}, 42, 2, BLACK);


            // deplacement
            if (IsKeyDown(KEY_RIGHT)) position.x += playerSpeed * deltaTime;
            if (IsKeyDown(KEY_LEFT)) position.x -= playerSpeed * deltaTime;
            if (IsKeyDown(KEY_DOWN)) position.y += playerSpeed * deltaTime;
            if (IsKeyDown(KEY_UP)) position.y -= playerSpeed * deltaTime;

            
            DrawTexture(mushroom, PosX, PosY, WHITE);
            DrawTexture(player, position.x, position.y, WHITE);
            //DrawTextEx(font ,"Salut tout le monde", (Vector2) {225, 246}, font.baseSize, 2, BLACK );

        EndDrawing();
    }


    // unload et fermetture de la fenetre
    UnloadTexture(player);
    CloseWindow();
}