#include <SFML/Graphics.hpp>
#include "Ship.h"


float Ship::getyVelocity() {
    return (yVelocity);
}
void Ship::setyVelocity(float yVel) {
    yVelocity = yVel;
}
void Ship::checkHorizontalBoundaries(sf::Vector2f objectPosition){
    if (objectPosition.x < 0 + width / 2 || objectPosition.x > 1280 - width / 2)
        xVelocity *= -1;
}
float moveShip(float yVel, float& xVel) {
    return yVel;
}
