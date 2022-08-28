#pragma once

#include <string>
#include <assert.h>
#include "raylib.h"
#include <list>
#include "Game/Globals.hpp"
#include "Game/Player.hpp"
#include "Game/LevelGenerator.hpp"

#define WIDTH 1280
#define HEIGHT 720

class Game{
    public:
        Game(std::string title);
        Game (const Game&) = delete;
        Game& operator= (const Game&) = delete;
        ~Game(void);   

        void Tick();
        void Update();
        void Render();
        bool ShouldClose(); 
        void CreateLevel(const char* levelTitle, const char* imgpath);

    private:
        Player player; //  bread
        LevelGenerator LGen; // havent finished making
        Camera2D cam; //not working for some reason - need to look into
};