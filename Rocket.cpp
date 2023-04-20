#include <SFML/Graphics.hpp>
#include "Rocket.h"

Rocket::Rocket(float yVel, int wdth, int hght) {
    yVelocity = yVel;
    width = wdth;
    height = hght;
}
float Rocket::getyVelocity() {
    return (yVelocity);
}
void Rocket::setyVelocity(float yVel) {
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