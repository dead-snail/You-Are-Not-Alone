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

    cam.target = player.position.To_Vector2();
}

void Game::Render(){
    ClearBackground(BLACK);

    DrawLine(GetScreenWidth()/2,GetScreenHeight(), GetScreenWidth()/2, 0, SKYBLUE);
    DrawLine(GetScreenWidth(), GetScreenHeight()/2, 0, GetScreenHeight()/2, SKYBLUE);

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