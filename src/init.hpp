#include <raylib.h>
#include <iostream>
#include <math.h>
#include <fmt/core.h>

class InitClass {
public:
    Texture2D mushroom;
    Texture2D player;
    int PosX;
    int PosY;
    uint16_t playerRotation = 0;
    bool GameStarted;
    int vie;

    InitClass()
    {
        // If on Windows or Linux
#if defined(_WIN32) || defined(__linux__)
        mushroom = LoadTexture("res/mushroom.png");
        player = LoadTexture("res/player.png");
        fmt::print("Load from Windows or Linux");
        // If on Apple products (macOS/iPhone/Apple Watch, etc.)
#elif defined(__APPLE__)
        mushroom = LoadTexture("../Resources/res/res/mushroom.png");
        player = LoadTexture("../Resources/res/res/player.png");
        fmt::print("Load from macOS");
#endif

        PosX = GetRandomValue(0, GetScreenWidth() - mushroom.width);
        PosY = GetRandomValue(0, GetScreenHeight() - mushroom.height);
        GameStarted = false;
        vie = 0;
    }

    void TitleScreen();
    //void MovePlayer();
};

class InitWindowClass {
public:
    void InitWindowFunctions();
};
