#include "Game/LevelGenerator.hpp"

Tile::Tile(){
    entityList.push_back(this);
}

void Tile::Update(){

}

//renders a single tile in a level
void Tile::Render(){
    DrawTexture(texture, GetScreenWidth()/2,GetScreenHeight()/2, WHITE);
}

Tile::~Tile(){

}

Level::Level(std::string t){

}

void Level::Update(){

}

//calls Render() on all the tiles in a level
void Level::Render(){

}

Level::~Level(){

};

LevelGenerator::LevelGenerator(){

}

Level LevelGenerator::GenLevel(std::string imgpath){    
    return {imgpath}; // temporary - the parameter is only the level name
}

LevelGenerator::~LevelGenerator(){

}