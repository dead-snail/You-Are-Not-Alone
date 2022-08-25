#include "raylib.h"
#include "Game/Game.hpp"
#include "time.h"

void PreLoadTextures();

int main() {
    //creates the initial "Game" object
    Game game{"Test"};

    LoadTextures(); // causes a segfault

    //runs the game loop
    while(!game.ShouldClose()){
        game.Tick();
        //if i ever have to touch this file again it will be to delete the whole project bc i hate myself
    }

    return 0;
}

void LoadTextures(){
    for(Entity* e : entityList){
        e->CreateTexture();
    }
}