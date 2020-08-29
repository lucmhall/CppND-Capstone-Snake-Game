#ifndef FOOD_H
#define FOOD_H
#include "string"
#include "SDL.h"

class Food : public SDL_Point
{
public:
    float speedModifier = .02;
    int growthRate = 2;
    Uint8 red = 0xFF;
    Uint8 green = 0xCC;
    Uint8 blue = 0x00;
    Uint8 alpha = 0xFF;

    Food() {}
    void setCoordinates(int x, int y);

private:
};

class FriendlyFood : public Food
{
public:
    FriendlyFood()
    {
        speedModifier = -.01;
        growthRate = -1;
        red = 0x00;
        green = 0x00;
        blue = 0xFF;
        alpha = 0xFF;
    }
};

class SpeedyFood : public Food
{
public:
    SpeedyFood()
    {
        growthRate = 1;
        speedModifier = .06;
        red = 0x00;
        green = 0xFF;
        blue = 0x00;
        alpha = 0xFF;
    }
};
// Food(.06, 0), Food(.02, 1), Food(.0, 2), Food(.01, 3)

#endif