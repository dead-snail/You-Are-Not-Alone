#pragma once

#include <iostream>
#include "raylib.h"
#include "Vec2.hpp"

class Entity {
    public:
        Entity(){
            
        }

        virtual void Update() = 0;
        virtual void Render() = 0;
        void CreateTexture(){
            //loads the texture and changes its size 
            texture = LoadTexture(assetpath);
            texture.width *= 5;
            texture.height *= 5;
            //assigns values for drawing the entity
            size = {0,0,(float)texture.width, (float)texture.height};
            centre = {(float)texture.width/2, (float)texture.height/2};
            rot = 0;
            position = {0,0};
        }

        ~Entity(void) = default;

    public:
        const char * assetpath;
        Texture texture;
        Rectangle size;
        Vec2<float> centre; 
        float rot;
        Vec2<float> position;
};