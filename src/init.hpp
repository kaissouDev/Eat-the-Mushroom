#include <raylib.h>
#include <iostream>
#include <math.h>
#include <fmt/core.h>

class InitClass{
    public:
        //void LoadTextureFunctions();
        Texture2D mushroom = LoadTexture("res/mushroom.png");
        Texture2D player = LoadTexture("res/player.png");
        int PosX = GetRandomValue(0, GetScreenWidth() - mushroom.width);
        int PosY = GetRandomValue(0, GetScreenHeight() - mushroom.height);
        void TitleScreen();
        bool GameStarted;
        int vie = 0;
        
        //void MovePlayer();
        private:
    //protected:

};

class InitWindowClass{
    public:
        void InitWindowFunctions();
};