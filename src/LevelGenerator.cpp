#include "Game/LevelGenerator.hpp"

Tile::Tile(const char * assetpath){
    this->assetpath=assetpath;
}

void Tile::Update(){
    // if(id != Tiles::Types::Air){
    //     std::cout << "hello\n";
    // }
}

//renders a single tile in a level
void Tile::Render(){
    DrawRectangle(GetScreenWidth()/2, GetScreenHeight()/2, 50, 50, WHITE);
    //DrawTexture(texture, GetScreenWidth()/2,GetScreenHeight()/2, WHITE);
}

Tile::~Tile(){

}

Level::Level(const char* t){

}

Level::~Level(){

};

LevelGenerator::LevelGenerator(){

}

Level LevelGenerator::GenLevel(const char* levelTitle, const char* imgpath){  
    Level newlevel(levelTitle);

    //Image image = LoadImage(imgpath);
    //Color* colours = LoadImageColors(image);

    // for(int i = 0; i < image.width*image.height-1; ++i){
    //     if(colours[i].r == Tiles::Wall){
    //         newlevel.tileGrid[i] = Tile(Tiles::Types::Wall);
    //     } else {
    //         newlevel.tileGrid[i] = Tile(Tiles::Types::Air);
    //     }
    // }

    for(int i = 0; i < 100;++i){
        newlevel.tileGrid[i] = Tile("../assets/playertest.png");
    }

    for(Tile t : newlevel.tileGrid){
        t.CreateTexture();
    }

    return newlevel;
}

LevelGenerator::~LevelGenerator(){

}