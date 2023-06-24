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
#include <cmath>

//load textures

using namespace std;
using namespace fmt;


void _DEBUG_(InitClass initclass){
    print("InitWindow ..\n");
    print("The Maximum framewrate is : 60.0fps\n");
    print("Desktop Version\n");
    
    if (!initclass.mushroom.id || !initclass.player.id){
        print("texture not load...\n");
    }
    else{
        print("texture load !\n");
    }

}


int main(int argc, char ** argv){

    if(!glfwInit()){
        boxer::Selection glfwInit = boxer::show("La version de votre GPU n'est pas compatible avec OpenGL. Veuillez changer ou mettre à jour votre GPU.", "Échec de la création de la fenêtre !", boxer::Style::Warning);
    }

    SetTraceLogLevel(LOG_NONE);
    InitWindowClass initwindow;
    initwindow.InitWindowFunctions();
    InitClass initclass;
    Move move;

    _DEBUG_(initclass);

    float distance = 0.0f;

    initclass.GameStarted = false;

    Vector2 position = {0, 500};
    const float playerSpeed = 300.0f;

    while(!WindowShouldClose()){
        BeginDrawing();
        if(!glfwInit()){
            boxer::Selection glfwInit = boxer::show("La version de votre GPU n'est pas compatible avec OpenGL. Veuillez changer ou mettre à jour votre GPU.", "Échec de la création de la fenêtre !", boxer::Style::Warning);
        }
        if(initclass.GameStarted == false){
            ClearBackground(BLACK);
            initclass.TitleScreen();
        }
        else if(initclass.GameStarted == true)
        {
            float deltaTime = GetFrameTime();
            ClearBackground(BLUE);
            DrawText(TextFormat("Health = %d", initclass.vie), 269, 28, 42, BLACK);
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