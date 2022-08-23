#include "Game/Player.hpp"

Vec2<float> KeysPressed(){
    float x,y;
    
    x = IsKeyDown(KEY_D) - IsKeyDown(KEY_A);
    y = IsKeyDown(KEY_S) - IsKeyDown(KEY_W);
    
    return {x,y};
}

Player::Player()
    :
    position(Settings::screenWidth / 2-25, Settings::screenHeight / 2-25),
    speed(SPEED),
    powers(0)
{
    entityList.push_back(this);
}

void Player::Update(){
    //move
    Vec2<float> locPos = KeysPressed();
    speed = abs(locPos.GetX()) + abs(locPos.GetY()) > 1 ? 200 : 300;
    
    position += locPos * speed * GetFrameTime();
}

void Player::Render(){
    //draw the player rectangle at the centre of the screen
    DrawRectangle(position.GetX(), position.GetY(), 50, 50, GREEN);
}

Player::~Player(){
    
}

