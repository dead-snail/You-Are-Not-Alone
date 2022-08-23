#pragma once

#include <string>
#include "Game/Entity.hpp"
#include <vector>

class Tile : public Entity {
    public:
        Tile(std::string assetpath);
        virtual void Update();
        virtual void Render();
        ~Tile();
};

class Level : public Entity {
    public:
        Level(std::string t);
        virtual void Update();
        virtual void Render();
        ~Level(void);

        std::vector<Tile> tileGrid; 
};

class LevelGenerator {
    public:
        LevelGenerator();
        LevelGenerator (const LevelGenerator&) = delete;
        LevelGenerator& operator= (const LevelGenerator&) = delete;
        ~LevelGenerator();

        Level GenLevel(std::string imgPath);
};