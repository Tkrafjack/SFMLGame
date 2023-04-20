//header guard
#ifndef ROCKET_H
#define ROCKET_H
#endif

class Rocket {
private:
    float yVelocity;
    int width;
    int height;
public:
    Rocket(float yVel, int wdth, int hght);
    float getyVelocity();
    void setyVelocity(float yVel);
    int getWidth();
    void setWidth(int wdth);
    int getHeight();
    void setHeight(int hght);
};