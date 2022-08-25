#include "Game/Player.hpp"

Vec2<float> KeysPressed(){
    float x,y;
    
    x = IsKeyDown(KEY_D) - IsKeyDown(KEY_A);
    y = IsKeyDown(KEY_S) - IsKeyDown(KEY_W);
    
    return {x,y};
}

Player::Player(const char* assetpath)
    :
    speed(SPEED),
    powers(0)
{
    this->assetpath = assetpath;
    entityList.push_back(this);
     
    position = {Settings::screenWidth / 2-25, Settings::screenHeight / 2-25};
}

void Player::Update(){

    //stops the rotation from being exceedingly large
    if(rot > 360)
        rot = 0;
    else if(rot < 0){
        rot = 360;
    }

    //move
    Vec2<float> locPos = KeysPressed();
    //makes sure the player is always moving at a similar speed
    speed = abs(locPos.GetX()) + abs(locPos.GetY()) > 1 ? 200 : 300;
    //updates aligning with the frame time so it runs the same at every framerate
    position += locPos * speed * GetFrameTime();
    rot += 100*GetFrameTime();
}

void Player::Render(){
    //draw the player texture
    DrawTexturePro(texture,
        size,
        Rectangle{position.GetX(), position.GetY(), (float)texture.width, (float)texture.height},
        centre.To_Vector2(),
        rot,
        WHITE
    );
}

Player::~Player(){
    //whatever was here seems to have evaporated
}

