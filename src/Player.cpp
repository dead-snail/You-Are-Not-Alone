#include "Game/Player.hpp"

Player::Player()
    :
    position(Settings::screenWidth / 2, Settings::screenHeight / 2)
{
    entityList.push_back(this);
}

void Player::Update(){
    
}

void Player::Render() const {
    //draw the player rectangle at the centre of the screen
    DrawRectangle(position.GetX()-25, position.GetY()-25, 50, 50, GREEN);
}

Player::~Player(){
    
}