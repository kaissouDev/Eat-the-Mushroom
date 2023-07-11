//
//	*player_rotation.html
//
//	KaissouDev | Eat-the-Mushroom 
//	(c) 2023
//

#include "main.hpp"

class PlayerRotation{
    public:
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


        static uint8_t manageMovement( Vector2 &position, const float &playerSpeed, float &deltaTime )
        {
            uint8_t rotationFlags = 0;
            int playerSize = 50; // TODO grab player size from game.cpp
                //managing player movement and save rotation flags.
                if (IsKeyDown(KEY_RIGHT) && position.x < GetScreenWidth() - playerSize)
                {
                    rotationFlags |= PlayerDirectionEnum::RIGHT;
                    position.x += playerSpeed * deltaTime;
                }
                    if (IsKeyDown(KEY_LEFT) && position.x > 0 - playerSize / 2 + 10)
                {
                    rotationFlags |= PlayerDirectionEnum::LEFT;
                    position.x -= playerSpeed * deltaTime;
                }
                    if (IsKeyDown(KEY_DOWN) && position.y < GetScreenHeight() - playerSize)
                {
                    rotationFlags |= PlayerDirectionEnum::DOWN;
                    position.y += playerSpeed * deltaTime;
                }
                    if (IsKeyDown(KEY_UP) && position.y > 0 - playerSize / 2 + 10)
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
};