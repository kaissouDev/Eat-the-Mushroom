#include "init.hpp"

void Init::InitWindowFunctions(){
    InitWindow(800, 600, "hello raylib");
    //SetTraceLogLevel(LOG_NONE);
}
void Init::LoadTextureFunctions(){
    Texture2D mushroom = LoadTexture("res/mushroom.png");
}