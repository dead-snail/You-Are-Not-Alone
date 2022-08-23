#pragma once

#include "Game/Globals.hpp"
#include "Vec2.hpp"

#define SPEED 300

class Player : public Entity {
    public:
        Player();
        virtual void Update();
        virtual void Render();
        ~Player(void);

    private:
        Vec2<float> position;
        float speed;
};