#include "Game/LevelGenerator.hpp"

Tile::Tile(std::string assetpath){

}

void Tile::Update(){

}

void Tile::Render(){

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