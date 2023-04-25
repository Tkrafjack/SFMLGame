//header guard
#ifndef SHIP_H
#define SHIP_H
#endif

class Ship {
private:
    float yVelocity;
public:
    float width;
    float height;
    float xVelocity;

    float getyVelocity();
    void setyVelocity(float yVel);
    void checkHorizontalBoundaries(sf::Vector2f objectPosition);
    //void moveShip(float yVel, float& xVel);
};