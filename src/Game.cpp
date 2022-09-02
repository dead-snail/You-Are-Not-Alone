#include "Game/Game.hpp"

Game::Game(std::string title):player("../assets/playertest.png"){
    // assures that a window does not exist before creating a new one
    assert(!GetWindowHandle());

    InitWindow(WIDTH, HEIGHT, title.c_str());

    cam.offset = {0,0};
    cam.target = {0,0};
    cam.rotation = 0.0f;
    cam.zoom = 1.0f;
}

void Game::Tick(){
    Update();

    //has to begin drawing before Render() is 
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

    cam.target = (player.position - Vec2<float>{GetScreenWidth()/2, GetScreenHeight()/2}).To_Vector2();
}

void Game::Render(){
    ClearBackground(BLACK);

    BeginMode2D(cam);
    //draws a cross in the screen - get rid of later
    DrawLine(GetScreenWidth()/2,GetScreenHeight(), GetScreenWidth()/2, 0, SKYBLUE);
    DrawLine(GetScreenWidth(), GetScreenHeight()/2, 0, GetScreenHeight()/2, SKYBLUE);

    Vector2 worldPos = GetScreenToWorld2D(Vector2{10,10}, cam);

    DrawFPS(worldPos.x, worldPos.y);

    //LGen.currentLevel->Render();

    //loops through the entity list and draws all of the elements
    for(Entity* entity : entityList){
        entity->Render();
    }

    EndMode2D();
}

//extra steps make my brain fuzy
bool Game::ShouldClose(){
    return WindowShouldClose();
}

void Game::CreateLevel(const char * levelTitle, const char* imgpath){
    LGen.GenLevel(levelTitle, imgpath);
}

Game::~Game(){
    // assures there is already a window open before trying to close it
    assert(GetWindowHandle());

    CloseWindow();
}