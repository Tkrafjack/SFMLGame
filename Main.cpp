#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>

#include "Ship.h"
#include "Rocket.h"
#include "Player.h"

int main()
{
    enum Window
    {
        windowWidth = 1280,
        windowHeight = 720
    };

#pragma region Creating Objects
    Ship enemy;
    enemy.setyVelocity(0.3);
    enemy.xVelocity = 3;
    enemy.width = 30;
    enemy.height = 60;

    Player player;
    //player's size
    player.width = 100;
    player.height = 25;
    //player's movement speed
    player.xVelocity = 0;

    //rocket(yVelocity,width, height)
    Rocket rocket(-25.0, 10, 20);
#pragma endregion

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Galaga");
    window.setFramerateLimit(60);

#pragma region Creating Shapes

    //Setting playerShip on screen and formating
    sf::RectangleShape playerShip;
    sf::Vector2f playerShipPosition(windowWidth / 2, windowHeight - player.height / 2);
    playerShip.setPosition(playerShipPosition);
    playerShip.setSize(sf::Vector2f(player.width, player.height));
    playerShip.setOrigin(player.width/2, player.height / 2);

    sf::RectangleShape rocketBody(sf::Vector2f(rocket.getWidth(), rocket.getHeight()));
    sf::Vector2f rocketBodyPosition(playerShipPosition.x, playerShipPosition.y);
    rocketBody.setFillColor(sf::Color::Cyan);
    rocketBody.setPosition(rocketBodyPosition);

    sf::RectangleShape enemyShip(sf::Vector2f(enemy.width, enemy.height));
    enemyShip.setFillColor(sf::Color::Red);
    sf::Vector2f enemyShipPosistion(300, -50);
    enemyShip.setPosition(enemyShipPosistion);
    enemyShip.setOrigin(enemy.width / 2, enemy.height / 2);

    sf::RectangleShape enemyShip1(sf::Vector2f(enemy.width, enemy.height));
    enemyShip1.setFillColor(sf::Color::Red);
    sf::Vector2f enemyShipPosistion1(600, -50);
    enemyShip1.setPosition(enemyShipPosistion1);
    enemyShip1.setOrigin(enemy.width / 2, enemy.height / 2);
#pragma endregion

#pragma region Adding Font and Text

    sf::Font font;
    if (!font.loadFromFile("C:/Users/TKraf/sfmlGame/Open-sans/OpenSans-Bold.ttf"))
    {
        std::cout << "Error loading the font file" << std::endl;
    }
    int score = 0;
    std::string stringScore = std::to_string(score);
    sf::Text scoreText;
    scoreText.setFont(font); // font is a sf::Font
    scoreText.setString("Score:");
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::Magenta);
    scoreText.setPosition(10,100);

    sf::Text scoreValueText;
    scoreValueText.setFont(font); // font is a sf::Font
    scoreValueText.setString(stringScore);
    scoreValueText.setCharacterSize(24);
    scoreValueText.setFillColor(sf::Color::Magenta);
    scoreValueText.setPosition(85, 100);
#pragma endregion

#pragma region Main Loop

    bool moveRocket = false;
    //Main loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //changing player direction
        player.playerMovement(player.xVelocity);

        player.checkHorizontalBoundaries(playerShipPosition);  
        enemy.checkHorizontalBoundaries(enemyShipPosistion);
        //enemy.checkVerticalBoundaries(enemyShipPosistion);

        //moving enemyShip on window
        enemyShipPosistion.x += enemy.xVelocity;
        enemyShipPosistion.y += enemy.getyVelocity();
        enemyShip.setPosition(enemyShipPosistion);

        //moving player's ship
        playerShipPosition.x += player.xVelocity;
        playerShip.setPosition(playerShipPosition);

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)))
            moveRocket = true;

        //moving rocket on window
        if (moveRocket) {
            rocketBodyPosition.y += rocket.getyVelocity();
            rocketBody.setPosition(rocketBodyPosition);
        }
        else {
            rocketBodyPosition.x += player.xVelocity;
            rocketBody.setPosition(rocketBodyPosition);
        }

        if (rocketBody.getGlobalBounds().intersects(enemyShip.getGlobalBounds())) {
            enemyShip.setPosition(500, 500);
            score += score;
            stringScore = std::to_string(score);
            scoreValueText.setString(stringScore);
            std::cout << stringScore << std::endl;
        }

        //if rocket goes of screen return it to the player
        if (rocketBodyPosition.y < 0) {
            moveRocket = false;
            rocketBodyPosition.x = playerShipPosition.x;
            rocketBodyPosition.y = playerShipPosition.y;
            rocketBody.setPosition(rocketBodyPosition.x, rocketBodyPosition.y);
        }

        //render window and items
        window.clear();
        window.draw(playerShip);
        window.draw(rocketBody);
        window.draw(enemyShip);
        window.draw(enemyShip1);
        window.draw(scoreText);
        window.draw(scoreValueText);
        window.display();

    }//end of main loop

    return 0;
}
#pragma endregion
