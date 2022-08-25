#pragma once

#include "raylib.h"

template <typename T>
class Vec2{
    public:
        Vec2() = default;
        constexpr Vec2(T x, T y) : x(x), y(y) {

        }

        constexpr Vector2 To_Vector2(){
            return {x,y};
        }

        constexpr T GetX() const {return x;}
        constexpr T GetY() const {return y;}
        constexpr void SetX(T x) {this->x = x;}
        constexpr void SetY(T y) {this->y = y;}

    public:
        constexpr bool operator==(const Vec2& rhs) const{
            return (x == rhs.x && y == rhs.y);
        }
        constexpr bool operator!=(const Vec2& rhs) const{
            return !(*this == rhs);
        }
        constexpr Vec2 operator+(const Vec2& rhs) const {
            return {x + rhs.x, y + rhs.y};
        }
        constexpr Vec2 operator+(const float rhs) const {
            return {x + rhs, y + rhs};
        }
        constexpr Vec2 operator+= (const Vec2& rhs) {
            return *this = *this + rhs;
        }
        constexpr Vec2 operator-(const Vec2& rhs) const {
            return {x - rhs.x, y - rhs.y};
        }
        constexpr Vec2 operator-(const float rhs) const {
            return {x - rhs, y - rhs};
        }
        constexpr Vec2 operator-= (const Vec2& rhs) {
            return *this = *this - rhs;
        }
        constexpr Vec2 operator*(const Vec2& rhs) const {
            return {x * rhs.x, y * rhs.y};
        }
        constexpr Vec2 operator*(const float rhs) const {
            return {x * rhs, y * rhs};
        }
        constexpr Vec2 operator*= (const Vec2& rhs) {
            return *this = *this * rhs;
        }

    private:
    T x;
    T y;
};