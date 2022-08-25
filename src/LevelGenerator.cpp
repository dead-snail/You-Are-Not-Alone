#include "Game/LevelGenerator.hpp"

Tile::Tile(){

}

void Tile::Update(){

}

void Tile::Render(){
    DrawTexture(texture, GetScreenWidth()/2,GetScreenHeight()/2, WHITE);
}

void Tile::CreateTile(const char* assetpath){
    
    size.SetX(texture.width);
    size.SetY(texture.height);
}

Tile::~Tile(){

}

Level::Level(std::string t){

}

void Level::Update(){

}

void Level::Render(){

}

Level::~Level(){

};

LevelGenerator::LevelGenerator(){

}

Level LevelGenerator::GenLevel(std::string imgpath){    
    return {"bread"};
}

LevelGenerator::~LevelGenerator(){

}