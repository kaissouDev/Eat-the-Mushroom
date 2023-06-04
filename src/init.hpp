#include <raylib.h>
#include <iostream>
#include <math.h>
#include <fmt/core.h>

class InitClass{
    public:
        //void LoadTextureFunctions();
        Texture2D texture1 = LoadTexture("res/mushroom.png");
        void TitleScreen();
    private:
    //protected:

};

class InitWindowClass{
    public:
        void InitWindowFunctions();
};