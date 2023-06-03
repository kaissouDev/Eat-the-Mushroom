/******************************************
*          Eat The Mushroom
*               MIT
*******************************************
*   (c) Kaissou || All right reserved!
*              init.cpp
*******************************************
*             03/06/2023
*******************************************/

#include "init.hpp"

void Init::InitWindowFunctions(){
    InitWindow(800, 600, "hello raylib");
    //SetTraceLogLevel(LOG_NONE);
}
void Init::LoadTextureFunctions(){
    Texture2D mushroom = LoadTexture("res/mushroom.png");
}