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
#include <iostream>
#include <math.h>

using namespace std;

/*void load(){

    (a mettre plus tard)
}*/

/*void deplacement(){


}*/



void AfficherConsole(int vie){

    perso kais;


    std::cout << "--------------------------------" << std::endl;
    std::cout << "Nom du Joueur : " << kais.nom << std::endl;
    std::cout << "Vie = " << vie << std::endl;
}

// fonction main de base
int main(){

    InitWindow(800,600, "Eat The Mushroom (DEBUG PROTOTYPE 1.0)");

    // load des fichiers / audios

    
    Vector2 position = { 356, 250 };

    
    Texture2D player = LoadTexture("res/player.png");
    Texture2D  mushroom = LoadTexture("res/mushroom.png");
    Texture2D  blackmushroom = LoadTexture("res/black.png");
    Font font = LoadFont("font/Gotham-Medium.otf");
    int PosX = GetRandomValue(0, GetScreenWidth() - mushroom.width);
    int NewPosX = GetRandomValue(0, GetScreenWidth() - mushroom.width);
    int PosY = GetRandomValue(0, GetScreenHeight() - mushroom.height);
    int NewPosY = GetRandomValue(0, GetScreenHeight() - mushroom.height);
    const float playerSpeed = 300.0f;
    int vie = 0;
    float distance = 0.0f;
    float blackdistance = 0.0f; // Ajout de la variable distanc
    // game loop

    //bool spacePressed = false;

    while(!WindowShouldClose()){
        BeginDrawing();
        SetTraceLogLevel(LOG_NONE);
            ClearBackground(BLUE);
            
            float deltaTime = GetFrameTime();

            DrawTextEx(font, TextFormat("Vie = %d", vie), (Vector2) {269, 28}, 42, 2, WHITE);


            // deplacement
            if (IsKeyDown(KEY_RIGHT)) position.x += playerSpeed * deltaTime;
            if (IsKeyDown(KEY_LEFT)) position.x -= playerSpeed * deltaTime;
            if (IsKeyDown(KEY_DOWN)) position.y += playerSpeed * deltaTime;
            if (IsKeyDown(KEY_UP)) position.y -= playerSpeed * deltaTime;

            bool IsMushroomVisible = true;
            
            
            DrawTexture(mushroom, PosX, PosY, WHITE);
            DrawTexture(blackmushroom, NewPosX, NewPosY, WHITE);
            DrawTexture(player, position.x, position.y, WHITE);
            distance = sqrt(pow(position.x - PosX, 2) + pow(position.y - PosY, 2));
            blackdistance = sqrt(pow(position.x - NewPosX, 2) + pow(position.y - NewPosY, 2));

           

            if(distance < 50) {

                vie++;

                UnloadTexture(mushroom);

       
                PosX = GetRandomValue(0, GetScreenWidth() - mushroom.width);
                PosY = GetRandomValue(0, GetScreenHeight() - mushroom.height);

     
                mushroom = LoadTexture("res/mushroom.png");
                
            }
            if(blackdistance < 50) {

                vie--;

                UnloadTexture(blackmushroom);

       
                NewPosX = GetRandomValue(0, GetScreenWidth() - mushroom.width);
                NewPosY = GetRandomValue(0, GetScreenHeight() - mushroom.height);

     
                blackmushroom = LoadTexture("res/black.png");
                
            }

            if(vie == 13){
                UnloadTexture(mushroom);
                UnloadTexture(player);
                UnloadTexture(blackmushroom);
                
                ClearBackground(WHITE);
                Font fin = LoadFont("font/Gotham-Black.otf");
                Font fin2 = LoadFont("font/Gotham-Medium.otf");
                DrawTextEx(fin ,"You Win!", (Vector2) {219, 204}, 64, 2, BLACK );
                DrawTextEx(fin2 ,"Press Space For close Window", (Vector2) {69, 431}, 48, 2, BLACK );
                if(IsKeyDown(KEY_SPACE)){

                    CloseWindow();
                    UnloadFont(fin2);
                    UnloadFont(fin);
                }

            }
            //DrawTextEx(font ,"Salut tout le monde", (Vector2) {225, 246}, font.baseSize, 2, BLACK );

        EndDrawing();
    }


    // unload et fermetture de la fenetre
    vie = 0;
    UnloadFont(font);
    UnloadTexture(mushroom);
    UnloadTexture(blackmushroom);
    UnloadTexture(player);
    CloseWindow();
}