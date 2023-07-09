//
//	*game.hpp
//
//	KaissouDev | Eat-the-Mushroom 
//	(c) 2023
//

#include "main.hpp"

class Game{
    public:
        Texture2D mushroom;
        Texture2D player;
        Image icon;
        int PosX;
        int PosY;
        int Health;
		int Timer;

        uint16_t playerRotation = 0;
        bool GameStarted;
        void CreateWindow();
        void Gameloop();
        void TitleScreen();
        void DrawObject();
        static void drawPlayer ( Texture2D &Texture, Vector2 &position, uint16_t rotation )
        {
	        Vector2 newPosition = position;
	        switch (rotation) {
	            case 0:
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
        void RunGame();
    private:
};