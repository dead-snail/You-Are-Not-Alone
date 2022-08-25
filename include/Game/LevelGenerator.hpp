#pragma once

#include <string>
#include "Game/Globals.hpp"
#include <vector>
#include "Vec2.hpp"
#include "raylib.h"

//what everything is made of
class Tile : public Entity {
    public:
        //adds this to the things to be updated + rendered every frame
        Tile(){
            entityList.push_back(this);
        }
        virtual void Update();
        virtual void Render();
        ~Tile();

        void CreateTile(const char * assetpath);
};

// level is made of tiles
class Level : public Entity {
    public:
        Level(std::string t);
        virtual void Update();
        virtual void Render();
        ~Level(void);

        std::vector<Tile> tileGrid; // y*width + x
};

//generates the tiles from an image and assigns it a level
class LevelGenerator {
    public:
        LevelGenerator();
        LevelGenerator (const LevelGenerator&) = delete;
        LevelGenerator& operator= (const LevelGenerator&) = delete;
        ~LevelGenerator();

        //actually does the generation - idk how it works i havent made it yet
        Level GenLevel(std::string imgPath);
};