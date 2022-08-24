#pragma once

#include <string>
#include "Game/Entity.hpp"
#include <vector>
#include "Vec2.hpp"
#include "raylib.h"

class Tile : public Entity {
    public:
        Tile();
        virtual void Update();
        virtual void Render();
        ~Tile();

        void CreateTile(const char * assetpath);

    private:
        Texture texture;
        Vec2<int> size;
        Vec2<int> position;
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