#pragma once

#include <iostream>
#include "raylib.h"

class Entity {
    public:
        Entity() = default;

        virtual void Update() = 0;
        virtual void Render() = 0;
        void CreateTexture(){
            texture = LoadTexture(assetpath);
            texture.width *= 5;
            texture.height *= 5;
        }

        ~Entity(void) = default;

    private:
        const char * assetpath;
    public:
        Texture texture;
};