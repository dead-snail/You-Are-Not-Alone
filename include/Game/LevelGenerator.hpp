#pragma once

#include <string>
#include "Game/Globals.hpp"
#include <vector>
#include "Vec2.hpp"
#include "raylib.h"
#include "Game/TileTypes.hpp"
#include "math.h"

//what everything is made of
class Tile : public Entity {
    public:
        //adds this to the things to be updated + rendered every frame
        Tile(const char * assetpath, Vec2<float> pos);
        virtual void Update();
        virtual void Render();
        ~Tile();

        bool ShouldUpdate();

    private:
        int id;
};

// level is made of tiles
class Level : public Entity {
    public:
        Level(const char* t);
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
        void GenLevel(const char* levelTitle, const char* imgPath);

        Level* currentLevel;
};