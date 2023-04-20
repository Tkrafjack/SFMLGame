//header guard
#ifndef SHIP_H
#define SHIP_H
#include "Ship.h"
#endif

class Player : public Ship
{
public:
    void playerMovement(float& xVel);
    bool playerShoot();
};