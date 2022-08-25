#include "Game/Game.hpp"

Game::Game(std::string title):player("../assets/playertest.png"){
    // assures that a window does not exist before creating a new one
    assert(!GetWindowHandle());

    InitWindow(WIDTH, HEIGHT, title.c_str());
}

void Game::Tick(){
    Update();

    BeginDrawing();
    Render();
    EndDrawing();
}

void Game::Update(){
    for(Entity* entity : entityList){
        entity->Update();
    }
}

void Game::Render(){
    ClearBackground(Color{16,0,50,255});
    DrawFPS(10,10);

    for(Entity* entity : entityList){
        entity->Render();
    }
}

bool Game::ShouldClose(){
    return WindowShouldClose();
}

Game::~Game(){
    assert(GetWindowHandle());

    CloseWindow();
}