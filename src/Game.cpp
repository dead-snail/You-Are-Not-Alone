#include "Game/Game.hpp"

Game::Game(std::string title):player("../assets/playertest.png"){
    // assures that a window does not exist before creating a new one
    assert(!GetWindowHandle());

    InitWindow(WIDTH, HEIGHT, title.c_str());
}

void Game::Tick(){
    Update();

    //has to begin drawing before Render() is called
    BeginDrawing();
    Render();
    //Causes mem leaks if you don't call EndDrawing()
    EndDrawing();
}

void Game::Update(){
    //loops through the list of entities and updates them
    //I can probably forget this later
    for(Entity* entity : entityList){
        entity->Update();
    }
}

void Game::Render(){
    ClearBackground(BLACK);

    //draws a cross in the screen - get rid of later
    DrawLine(GetScreenWidth()/2,GetScreenHeight(), GetScreenWidth()/2, 0, SKYBLUE);
    DrawLine(GetScreenWidth(), GetScreenHeight()/2, 0, GetScreenHeight()/2, SKYBLUE);

    DrawFPS(10,10);

    //loops through the entity list and draws all of the elements
    for(Entity* entity : entityList){
        entity->Render();
    }
}

//extra steps make my brain fuzy
bool Game::ShouldClose(){
    return WindowShouldClose();
}

Game::~Game(){
    // assures there is already a window open before trying to close it
    assert(GetWindowHandle());

    CloseWindow();
}