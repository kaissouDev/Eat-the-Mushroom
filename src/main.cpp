/******************************************
*          Eat The Mushroom
*             GPL V2
*******************************************
*   (c) Kaissou || All right reserved!
*              main.cpp
*******************************************
*             26/05/2023
*******************************************/

#include <iostream>
#include <raylib.h>

using namespace std;

void init(){
    SetTargetFPS(120);  
    InitWindow(800,600, "Eat The Mushroom (Release 3.0 DEBUG)");
    SetTraceLogLevel(LOG_NONE);
}


// fonction main de base
int main(){

    init();

    // drawing
    Texture2D player = LoadTexture("res/player.png");
    Texture2D  mushroom = LoadTexture("res/mushroom.png");
    Texture2D  blackmushroom = LoadTexture("res/black.png");
    Texture2D titlescreenmushroom = LoadTexture("res/TitleScreenMushroom.png");
    Font font = LoadFont("font/Gotham-Medium.otf");
    Font title = LoadFont("font/Gotham-Medium.otf");

    

    // declaration de variable
    Vector2 position = { 356, 250 };
    Vector2 titlemushroompos = { 302, 105 };
    int PosX = GetRandomValue(0, GetScreenWidth() - mushroom.width);
    int NewPosX = GetRandomValue(0, GetScreenWidth() - mushroom.width);
    int PosY = GetRandomValue(0, GetScreenHeight() - mushroom.height);
    int NewPosY = GetRandomValue(0, GetScreenHeight() - mushroom.height);
    const float playerSpeed = 300.0f;
    int vie = 0;
    float distance = 0.0f;
    float blackdistance = 0.0f; // Ajout de la variable distanc
    
    
    const bool Start = false;
    bool During = false;
    // game loop

    Vector2 Title = {269, 28};
    Vector2 titlescreenmushroomVector = {287, 104};
    Vector2 LifeVectorPos = {269, 28};


    //bool spacePressed = false;

    while(!WindowShouldClose()){
        if(Start == false)
        {
            BeginDrawing();
            ClearBackground(WHITE);
            DrawTextureEx(titlescreenmushroom, titlescreenmushroomVector, 0, 15, WHITE);
            DrawTextEx(title, TextFormat("Press Start To Play"), Title, 42, 2, BLACK);
            if(IsKeyDown(KEY_SPACE)){       
                During = true;
            }
            if (During == true){
            
            // drawing element
            float deltaTime = GetFrameTime();

            DrawTextEx(font, TextFormat("Vie = %d", vie), LifeVectorPos, 42, 2, WHITE);
            ClearBackground(BLUE);
            
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
                
                Vector2 finVector = {219, 204};
                Vector2 fin2Vector = {69, 431};

                ClearBackground(WHITE);
                Font fin = LoadFont("font/Gotham-Black.otf");
                Font fin2 = LoadFont("font/Gotham-Medium.otf");
                DrawTextEx(fin ,"You Win!", finVector, 64, 2, BLACK );
                DrawTextEx(fin2 ,"Press Space For close Window", fin2Vector, 48, 2, BLACK );
                if(IsKeyDown(KEY_SPACE)){

                  
                    UnloadFont(fin2);
                    
                    UnloadFont(fin);
                    UnloadFont(font);
                    UnloadTexture(mushroom);
                    UnloadTexture(blackmushroom);
                    UnloadTexture(player);
                    CloseWindow();
                }
            }
        // Ecran De Titre
        }
        

            //DrawTextEx(font ,"Salut tout le monde", (Vector2) {225, 246}, font.baseSize, 2, BLACK );
        }
        
        
        EndDrawing();
    }


    // unload et fermetture de la fenetre

    vie = 0;
    During = false;
    UnloadFont(font);
    UnloadTexture(mushroom);
    UnloadTexture(blackmushroom);
    UnloadTexture(player);
    UnloadTexture(titlescreenmushroom);
    UnloadFont(title);
    CloseWindow();
}