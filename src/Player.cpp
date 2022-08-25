#include "Game/Player.hpp"

Vec2<float> KeysPressed(){
    float x,y;
    
    x = IsKeyDown(KEY_D) - IsKeyDown(KEY_A);
    y = IsKeyDown(KEY_S) - IsKeyDown(KEY_W);
    
    return {x,y};
}

Player::Player(const char* assetpath)
    :
    position(Settings::screenWidth / 2-25, Settings::screenHeight / 2-25),
    speed(SPEED),
    powers(0)
{
    this->assetpath = assetpath;
    entityList.push_back(this);
}

void Player::Update(){
    //move
    Vec2<float> locPos = KeysPressed();
    speed = abs(locPos.GetX()) + abs(locPos.GetY()) > 1 ? 200 : 300;
    
    position += locPos * speed * GetFrameTime();
    rot += 100*GetFrameTime();
}

void Player::Render(){
    //draw the player rectangle at the centre of the screen
    DrawTexturePro(texture,
        size,
        Rectangle{position.GetX(), position.GetY(), (float)texture.width, (float)texture.height},
        centre.To_Vector2(),
        rot,
        WHITE
    );
}

Player::~Player(){
    
}

