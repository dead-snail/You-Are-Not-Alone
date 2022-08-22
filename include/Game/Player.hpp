#pragma once

#include "Game/Globals.hpp"
#include "Vec2.hpp"

class Player : public Entity {
    public:
        Player();
        Player (const Player&) = delete;
        Player& operator= (const Player&) = delete;
        ~Player(void);

        virtual void Update();
        virtual void Render() const;

    private:
        Vec2<float> position;
};