//header guard
#ifndef ROCKET_H
#define ROCKET_H
#endif

class Rocket {
private:
    int width;
    int height;
public:
    Rocket(float yVel, int wdth, int hght);
    float yVelocity;
    int getWidth();
    void setWidth(int wdth);
    int getHeight();
    void setHeight(int hght);
    //These are commented out due to linker errors. They were added above main to avoid this error at compile time
    //sf::Vector2f checkVerticalBoundaries(sf::Vector2f objectPosition, sf::Vector2f playerPosition, float& yVel, sf::RectangleShape rocket);
    //sf::Vector2f movingRocket(sf::Vector2f rocketPosition, float rocketYVel, sf::RectangleShape rocket, bool shouldRocketMove, float playerXVel);
};