#include <iostream>
#include <raylib.h>

struct Draw{
    Texture2D player = LoadTexture("res/player.png");
    Texture2D  mushroom = LoadTexture("res/mushroom.png");
    Texture2D  blackmushroom = LoadTexture("res/black.png");
    Font font = LoadFont("font/Gotham-Medium.otf");
};