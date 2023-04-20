#include <SFML/Graphics.hpp>
#include "Player.h"

void Player::playerMovement(float& xVel)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        xVel = -6;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        xVel = 6;
}
bool playerShoot()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        return true;
    else
        return false;
}