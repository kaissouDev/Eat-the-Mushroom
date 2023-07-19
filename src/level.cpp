#include "level.hpp"
#include "main.hpp"

void Level::CheckLevel(){
    if(Level::CurrentLevel == 1){
        ClearBackground(BLUE);
    }
    if(Level::CurrentLevel == 2){
        ClearBackground(RED);
    }
    if(Level::CurrentLevel == 3){
        ClearBackground(GREEN);
    }
    if(Level::CurrentLevel == 4){
        ClearBackground(BLACK);
    }
}