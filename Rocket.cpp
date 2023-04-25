#include <SFML/Graphics.hpp>
#include "Rocket.h"

Rocket::Rocket(float yVel, int wdth, int hght) {
    width = wdth;
    height = hght;
    yVelocity = yVel;
}
int Rocket::getWidth() {
    return (width);
}
void Rocket::setWidth(int wdth) {
    width = wdth;
}
int Rocket::getHeight() {
    return(height);
}
void Rocket::setHeight(int hght) {
    height = hght;
}
/*
void checkVerticalBoundaries(sf::Vector2f rocketPosition, sf::Vector2f playerPosition, float yVel, sf::RectangleShape rocket) {
    if (rocketPosition.y > 720) {
        yVel = 0;
        rocketPosition = playerPosition;
        rocket.setPosition(rocketPosition);
    }
    //return rocketPosition;
}
void movingRocket(sf::Vector2f rocketPosition, float rocketYVel, sf::RectangleShape rocket, bool shouldRocketMove, float playerXVel) {
    if (shouldRocketMove) {
        rocketPosition.y += rocketYVel;
        rocket.setPosition(rocketPosition);
        //return rocketPosition;
    }
    else {
        rocketPosition.x += playerXVel;
        rocket.setPosition(rocketPosition);
        //return rocketPosition;
    }
}
    */