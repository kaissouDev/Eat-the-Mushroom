#include "main.hpp"

class Game{
    public:
        Texture2D mushroom;
        Texture2D player;
        int PosX;
        int PosY;
        uint16_t playerRotation = 0;
        bool GameStarted;
        void CreateWindow();
        void Gameloop();
        void TitleScreen();
        void RunGame();
    private:
};