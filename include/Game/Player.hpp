#pragma once

#include "Game/Globals.hpp"
#include "Vec2.hpp"

#define SPEED 300

class Player : public Entity {
    public:
        Player(const char* assetpath);
        virtual void Update();
        virtual void Render();
        ~Player(void);

    private:
        Vec2<float> position;
        float speed;

        unsigned int powers : 3;
};