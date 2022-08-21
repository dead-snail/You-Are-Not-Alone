#include "raylib.h"
#include "Game/Game.hpp"
#include "time.h"

int main() {
    //creates the initial "Game" object
    Game game{"Test"};

    //runs the game loop
    while(!game.ShouldClose()){
        game.Tick();
    }

    return 0;
}