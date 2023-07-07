/******************************************
*          Eat The Mushroom
*               MIT
*******************************************
*   (c) Kaissou || All right reserved!
*              main.cpp
*******************************************
*             28/06/2023
*******************************************/
#include "main.hpp"
#include "game.hpp"

#include <iostream>
//load textures

using namespace std;
using namespace fmt;

/*
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

enum PlayerDirectionEnum
{
	RIGHT = 0b00010000,
	LEFT = 0b00100000,
	UP = 0b01000000,
	DOWN = 0b10000000,
	UP_RIGHT = UP | RIGHT,
	DOWN_RIGHT = DOWN | RIGHT,
	UP_LEFT = UP | LEFT,
	DOWN_LEFT = DOWN | LEFT
};

static void manageRotation( uint16_t &rotation, uint8_t rotationFlags )
{
	switch (rotationFlags) {
		case PlayerDirectionEnum::RIGHT:
		      rotation = 0;
		      break;
		case PlayerDirectionEnum::LEFT:
		      rotation = 180;
		      break;
		case PlayerDirectionEnum::UP:
		      rotation = 270;
		      break;
		case PlayerDirectionEnum::DOWN:
		      rotation = 90;
		      break;
		case PlayerDirectionEnum::UP_RIGHT:
		      rotation = 315;
		      break;
		case PlayerDirectionEnum::DOWN_RIGHT:
		      rotation = 45;
		      break;
		case PlayerDirectionEnum::UP_LEFT:
		      rotation = 225;
		      break;
		case PlayerDirectionEnum::DOWN_LEFT:
		      rotation = 135;
	}
}

static uint8_t manageMovement( Vector2 &position, const float &playerSpeed, float &deltaTime )
{
	uint8_t rotationFlags = 0;
	    //managing player movement and save rotation flags.
            if (IsKeyDown(KEY_RIGHT))
	    {
		    rotationFlags |= PlayerDirectionEnum::RIGHT;
		    position.x += playerSpeed * deltaTime;
	    }
            if (IsKeyDown(KEY_LEFT))
	    {
		    rotationFlags |= PlayerDirectionEnum::LEFT;
		    position.x -= playerSpeed * deltaTime;
	    }
            if (IsKeyDown(KEY_DOWN))
	    {
		    rotationFlags |= PlayerDirectionEnum::DOWN;
		    position.y += playerSpeed * deltaTime;
	    }
            if (IsKeyDown(KEY_UP))
	    {
		    rotationFlags |= PlayerDirectionEnum::UP;
		    position.y -= playerSpeed * deltaTime;
	    }

	    return rotationFlags;
}

static void drawPlayer ( Texture2D &Texture, Vector2 &position, uint16_t rotation )
{
	Vector2 newPosition = position;
	switch (rotation) {
	case  0:
	      break;
	case 180:
	      newPosition.x += 64;
	      newPosition.y += 64;
	      break;
	case 270:
	      newPosition.y += 64;
	      break;
	case 90:
	      newPosition.x += 64;
	      break;
	case 45:
	      newPosition.x += 32;
	      break;
	case 135:
	      newPosition.y += 32;
	      newPosition.x += 64;
	      break;
	case 315:
	      newPosition.y += 32;
	      break;
	case 225:
	      newPosition.y += 64;
	      newPosition.x += 32;
	      break;
	default:
	      break;
	};
	DrawTextureEx( Texture, newPosition, rotation, 1.0f, WHITE);
}
*/
int main(int argc, char ** argv){

    /*SetTraceLogLevel(LOG_NONE);
    InitWindowClass initwindow;
    initwindow.InitWindowFunctions();
    InitClass initclass;
    Move move;
    Image icon = LoadImage("res/icon.png");

    SetWindowIcon(icon);
    //_DEBUG_(initclass);

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
            ClearBackground(BLUE);
            DrawText(TextFormat("Health = %d", initclass.vie), 269, 28, 42, WHITE);
            DrawTexture(initclass.mushroom, initclass.PosX, initclass.PosY, WHITE);
	    //drawPlayer( initclass.player, position, initclass.playerRotation);    
       
	    //uint8_t playerDirection = manageMovement( position, playerSpeed, deltaTime);
           
	    //manageRotation(  initclass.playerRotation, playerDirection );

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
    CloseWindow();*/

	Game game;

	game.RunGame();
    return 0;
}
