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
    //wave 1 enemies
    Ship enemy;
    enemy.setyVelocity(0.3);
    enemy.xVelocity = -3;
    enemy.width = 30;
    enemy.height = 60;

    Ship enemy2;
    enemy2.setyVelocity(0.3);
    enemy2.xVelocity = 3;
    enemy2.width = 30;
    enemy2.height = 60;

    Ship enemy3;
    enemy3.setyVelocity(0.3);
    enemy3.xVelocity = -3;
    enemy3.width = 30;
    enemy3.height = 60;

    Ship enemy4;
    enemy4.setyVelocity(0.3);
    enemy4.xVelocity = 3;
    enemy4.width = 30;
    enemy4.height = 60;

    //Wave 2 Enemies
    Ship enemy5;
    enemy5.setyVelocity(0.9);
    enemy5.xVelocity = 5;
    enemy5.width = 30;
    enemy5.height = 60;

    Ship enemy6;
    enemy6.setyVelocity(0.9);
    enemy6.xVelocity = -5;
    enemy6.width = 30;
    enemy6.height = 60;

    Ship enemy7;
    enemy7.setyVelocity(0.9);
    enemy7.xVelocity = -5;
    enemy7.width = 30;
    enemy7.height = 60;

    //Wave 3 Enemies
    Ship enemy8;
    enemy8.setyVelocity(0.3);
    enemy8.xVelocity = -3;
    enemy8.width = 30;
    enemy8.height = 60;

    Ship enemy9;
    enemy9.setyVelocity(0.9);
    enemy9.xVelocity = 5;
    enemy9.width = 30;
    enemy9.height = 60;

    Ship enemy10;
    enemy10.setyVelocity(0.3);
    enemy10.xVelocity = 3;
    enemy10.width = 30;
    enemy10.height = 60;

    Ship enemy11;
    enemy11.setyVelocity(0.6);
    enemy11.xVelocity = 5;
    enemy11.width = 30;
    enemy11.height = 60;

    Ship enemy12;
    enemy12.setyVelocity(0.6);
    enemy12.xVelocity = -4;
    enemy12.width = 30;
    enemy12.height = 60;

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

    //Wave 1 Enemies
    sf::RectangleShape enemyShip(sf::Vector2f(enemy.width, enemy.height));
    enemyShip.setFillColor(sf::Color::Red);
    sf::Vector2f enemyShipPosistion(300, -50);
    enemyShip.setPosition(enemyShipPosistion);
    enemyShip.setOrigin(enemy.width / 2, enemy.height / 2);

    sf::RectangleShape enemyShip2(sf::Vector2f(enemy.width, enemy.height));
    enemyShip2.setFillColor(sf::Color::Red);
    sf::Vector2f enemyShipPosistion2(600, -70);
    enemyShip2.setPosition(enemyShipPosistion2);
    enemyShip2.setOrigin(enemy.width / 2, enemy.height / 2);

    sf::RectangleShape enemyShip3(sf::Vector2f(enemy.width, enemy.height));
    enemyShip3.setFillColor(sf::Color::Red);
    sf::Vector2f enemyShipPosistion3(75, -100);
    enemyShip3.setPosition(enemyShipPosistion3);
    enemyShip3.setOrigin(enemy.width / 2, enemy.height / 2);

    sf::RectangleShape enemyShip4(sf::Vector2f(enemy.width, enemy.height));
    enemyShip4.setFillColor(sf::Color::Red);
    sf::Vector2f enemyShipPosistion4(900, -50);
    enemyShip4.setPosition(enemyShipPosistion4);
    enemyShip4.setOrigin(enemy.width / 2, enemy.height / 2);

    //Wave 2 Enemies
    sf::RectangleShape enemyShip5(sf::Vector2f(enemy.width, enemy.height));
    enemyShip5.setFillColor(sf::Color::Green);
    sf::Vector2f enemyShipPosistion5(600, -70);
    enemyShip5.setPosition(enemyShipPosistion5);
    enemyShip5.setOrigin(enemy.width / 2, enemy.height / 2);

    sf::RectangleShape enemyShip6(sf::Vector2f(enemy.width, enemy.height));
    enemyShip6.setFillColor(sf::Color::Green);
    sf::Vector2f enemyShipPosistion6(75, -100);
    enemyShip6.setPosition(enemyShipPosistion6);
    enemyShip6.setOrigin(enemy.width / 2, enemy.height / 2);

    sf::RectangleShape enemyShip7(sf::Vector2f(enemy.width, enemy.height));
    enemyShip7.setFillColor(sf::Color::Green);
    sf::Vector2f enemyShipPosistion7(900, -50);
    enemyShip7.setPosition(enemyShipPosistion7);
    enemyShip7.setOrigin(enemy.width / 2, enemy.height / 2);
    
    //Wave 3 Enemies
    sf::RectangleShape enemyShip8(sf::Vector2f(enemy.width, enemy.height));
    enemyShip8.setFillColor(sf::Color::Red);
    sf::Vector2f enemyShipPosistion8(600, -70);
    enemyShip8.setPosition(enemyShipPosistion8);
    enemyShip8.setOrigin(enemy.width / 2, enemy.height / 2);

    sf::RectangleShape enemyShip9(sf::Vector2f(enemy.width, enemy.height));
    enemyShip9.setFillColor(sf::Color::Green);
    sf::Vector2f enemyShipPosistion9(75, -100);
    enemyShip9.setPosition(enemyShipPosistion9);
    enemyShip9.setOrigin(enemy.width / 2, enemy.height / 2);

    sf::RectangleShape enemyShip10(sf::Vector2f(enemy.width, enemy.height));
    enemyShip10.setFillColor(sf::Color::Red);
    sf::Vector2f enemyShipPosistion10(900, -50);
    enemyShip10.setPosition(enemyShipPosistion10);
    enemyShip10.setOrigin(enemy.width / 2, enemy.height / 2);

    sf::RectangleShape enemyShip11(sf::Vector2f(enemy.width, enemy.height));
    enemyShip11.setFillColor(sf::Color::Green);
    sf::Vector2f enemyShipPosistion11(900, -50);
    enemyShip11.setPosition(enemyShipPosistion11);
    enemyShip10.setOrigin(enemy.width / 2, enemy.height / 2);

    sf::RectangleShape enemyShip12(sf::Vector2f(enemy.width, enemy.height));
    enemyShip12.setFillColor(sf::Color::Green);
    sf::Vector2f enemyShipPosistion12(900, -50);
    enemyShip12.setPosition(enemyShipPosistion12);
    enemyShip12.setOrigin(enemy.width / 2, enemy.height / 2);
#pragma endregion

#pragma region Adding Font and Text

    sf::Font font;
    if (!font.loadFromFile("C:/Users/TKraf/sfmlGame/Open-sans/OpenSans-Bold.ttf"))
    {
        std::cout << "Error loading the font file" << std::endl;
    }
    sf::Text loserText;
    loserText.setFont(font); // font is a sf::Font
    loserText.setString("Game Over!:");
    loserText.setCharacterSize(24);
    loserText.setFillColor(sf::Color::Red);
    loserText.setPosition(windowWidth/2, windowHeight/2);

    sf::Text winnerText;
    winnerText.setFont(font); // font is a sf::Font
    winnerText.setString("Winner!");
    winnerText.setCharacterSize(24);
    winnerText.setFillColor(sf::Color::Magenta);
    winnerText.setPosition(windowWidth / 2, windowHeight / 2);
#pragma endregion

#pragma region Main Loop

    bool moveRocket = false;
    bool endWinner = false;
    bool endLoser = false;
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
        enemy2.checkHorizontalBoundaries(enemyShipPosistion2);
        enemy3.checkHorizontalBoundaries(enemyShipPosistion3);
        enemy4.checkHorizontalBoundaries(enemyShipPosistion4);
        enemy5.checkHorizontalBoundaries(enemyShipPosistion5);
        enemy6.checkHorizontalBoundaries(enemyShipPosistion6);
        enemy7.checkHorizontalBoundaries(enemyShipPosistion7);
        enemy8.checkHorizontalBoundaries(enemyShipPosistion8);
        enemy9.checkHorizontalBoundaries(enemyShipPosistion9);
        enemy10.checkHorizontalBoundaries(enemyShipPosistion10);
        enemy11.checkHorizontalBoundaries(enemyShipPosistion11);
        enemy12.checkHorizontalBoundaries(enemyShipPosistion12);

        //moving enemyShip on window
        enemyShipPosistion.x += enemy.xVelocity;
        enemyShipPosistion.y += enemy.getyVelocity();
        enemyShip.setPosition(enemyShipPosistion);
        //moving enemyShip2 on window
        enemyShipPosistion2.x += enemy2.xVelocity;
        enemyShipPosistion2.y += enemy2.getyVelocity();
        enemyShip2.setPosition(enemyShipPosistion2);
        //moving enemyShip3 on window
        enemyShipPosistion3.x += enemy3.xVelocity;
        enemyShipPosistion3.y += enemy3.getyVelocity();
        enemyShip3.setPosition(enemyShipPosistion3);
        //moving enemyShip4 on window
        enemyShipPosistion4.x += enemy4.xVelocity;
        enemyShipPosistion4.y += enemy4.getyVelocity();
        enemyShip4.setPosition(enemyShipPosistion4);
        //moving enemyShip5 on window
        enemyShipPosistion5.x += enemy5.xVelocity;
        enemyShipPosistion5.y += enemy5.getyVelocity();
        enemyShip5.setPosition(enemyShipPosistion5);
        //moving enemyShip6 on window
        enemyShipPosistion6.x += enemy6.xVelocity;
        enemyShipPosistion6.y += enemy6.getyVelocity();
        enemyShip6.setPosition(enemyShipPosistion6);
        //moving enemyShip7 on window
        enemyShipPosistion7.x += enemy7.xVelocity;
        enemyShipPosistion7.y += enemy7.getyVelocity();
        enemyShip7.setPosition(enemyShipPosistion7);
        //moving enemyShip8 on window
        enemyShipPosistion8.x += enemy8.xVelocity;
        enemyShipPosistion8.y += enemy8.getyVelocity();
        enemyShip8.setPosition(enemyShipPosistion8);
        //moving enemyShip9 on window
        enemyShipPosistion9.x += enemy9.xVelocity;
        enemyShipPosistion9.y += enemy9.getyVelocity();
        enemyShip9.setPosition(enemyShipPosistion9);
        //moving enemyShip10 on window
        enemyShipPosistion10.x += enemy10.xVelocity;
        enemyShipPosistion10.y += enemy10.getyVelocity();
        enemyShip10.setPosition(enemyShipPosistion10);
        //moving enemyShip11 on window
        enemyShipPosistion11.x += enemy11.xVelocity;
        enemyShipPosistion11.y += enemy11.getyVelocity();
        enemyShip11.setPosition(enemyShipPosistion11);
        //moving enemyShip10 on window
        enemyShipPosistion12.x += enemy12.xVelocity;
        enemyShipPosistion12.y += enemy12.getyVelocity();
        enemyShip12.setPosition(enemyShipPosistion12);

        //moving player's ship
        playerShipPosition.x += player.xVelocity;
        playerShip.setPosition(playerShipPosition);

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)))
            moveRocket = true;

        //moving rocket on window
        if (moveRocket) {
            rocketBodyPosition.y += rocket.yVelocity;
            rocketBody.setPosition(rocketBodyPosition);
        }
        else {
            rocketBodyPosition.x += player.xVelocity;
            rocketBody.setPosition(rocketBodyPosition);
        }


        if (rocketBody.getGlobalBounds().intersects(enemyShip.getGlobalBounds())) {
            enemyShip.setFillColor(sf::Color::Transparent);
            enemy.setyVelocity(0);
        }
        if (rocketBody.getGlobalBounds().intersects(enemyShip2.getGlobalBounds())) {
            enemyShip2.setFillColor(sf::Color::Transparent);
            enemy2.setyVelocity(0);
        }
        if (rocketBody.getGlobalBounds().intersects(enemyShip3.getGlobalBounds())) {
            enemyShip3.setFillColor(sf::Color::Transparent);
            enemy3.setyVelocity(0);
        }
        if (rocketBody.getGlobalBounds().intersects(enemyShip4.getGlobalBounds())) {
            enemyShip4.setFillColor(sf::Color::Transparent);
            enemy4.setyVelocity(0);
        }
        if (rocketBody.getGlobalBounds().intersects(enemyShip5.getGlobalBounds())) {
            enemyShip5.setFillColor(sf::Color::Transparent);
            enemy5.setyVelocity(0);
        }
        if (rocketBody.getGlobalBounds().intersects(enemyShip6.getGlobalBounds())) {
            enemyShip6.setFillColor(sf::Color::Transparent);
            enemy6.setyVelocity(0);
        }
        if (rocketBody.getGlobalBounds().intersects(enemyShip7.getGlobalBounds())) {
            enemyShip7.setFillColor(sf::Color::Transparent);
            enemy7.setyVelocity(0);
        }
        if (rocketBody.getGlobalBounds().intersects(enemyShip8.getGlobalBounds())) {
            enemyShip8.setFillColor(sf::Color::Transparent);
            enemy8.setyVelocity(0);
        }
        if (rocketBody.getGlobalBounds().intersects(enemyShip9.getGlobalBounds())) {
            enemyShip9.setFillColor(sf::Color::Transparent);
            enemy9.setyVelocity(0);
        }
        if (rocketBody.getGlobalBounds().intersects(enemyShip10.getGlobalBounds())) {
            enemyShip10.setFillColor(sf::Color::Transparent);
            enemy10.setyVelocity(0);
        }
        if (rocketBody.getGlobalBounds().intersects(enemyShip11.getGlobalBounds())) {
            enemyShip11.setFillColor(sf::Color::Transparent);
            enemy11.setyVelocity(0);
        }
        if (rocketBody.getGlobalBounds().intersects(enemyShip12.getGlobalBounds())) {
            enemyShip12.setFillColor(sf::Color::Transparent);
            enemy12.setyVelocity(0);
        }

        //if rocket goes of screen return it to the player
        if (rocketBodyPosition.y < 0) {
            moveRocket = false;
            rocketBodyPosition.x = playerShipPosition.x;
            rocketBodyPosition.y = playerShipPosition.y;
            rocketBody.setPosition(rocketBodyPosition.x, rocketBodyPosition.y);
        }
        
        if (enemy.getyVelocity() != 0.3 && enemy2.getyVelocity() != 0.3 && enemy3.getyVelocity() != 0.3 && enemy4.getyVelocity() != 0.3 
            && enemy5.getyVelocity() != 0.9 && enemy6.getyVelocity() != 0.9 && enemy7.getyVelocity() != 0.9 && enemy8.getyVelocity() != 0
            && enemy9.getyVelocity() != 0.3 && enemy10.getyVelocity() != 0.9 && enemy11.getyVelocity() != 0.6 && enemy12.getyVelocity() != 0.6)
        {
            endWinner = true;
        }
        if (enemyShip.getGlobalBounds().intersects(playerShip.getGlobalBounds()) || enemyShip2.getGlobalBounds().intersects(playerShip.getGlobalBounds())
            || enemyShip3.getGlobalBounds().intersects(playerShip.getGlobalBounds()) || enemyShip4.getGlobalBounds().intersects(playerShip.getGlobalBounds())
            || enemyShip5.getGlobalBounds().intersects(playerShip.getGlobalBounds()) || enemyShip6.getGlobalBounds().intersects(playerShip.getGlobalBounds())
            || enemyShip7.getGlobalBounds().intersects(playerShip.getGlobalBounds()) || enemyShip7.getGlobalBounds().intersects(playerShip.getGlobalBounds())
            || enemyShip8.getGlobalBounds().intersects(playerShip.getGlobalBounds()) || enemyShip9.getGlobalBounds().intersects(playerShip.getGlobalBounds())
            || enemyShip10.getGlobalBounds().intersects(playerShip.getGlobalBounds()) || enemyShip11.getGlobalBounds().intersects(playerShip.getGlobalBounds())
            || enemyShip12.getGlobalBounds().intersects(playerShip.getGlobalBounds()))
        {
            endLoser = true;
        }
        std::cout << enemy.getyVelocity() << std::endl;
        if (endWinner)
        {
            window.draw(winnerText);
        }
        if (endLoser)
        {
            window.draw(loserText);
        }
        //render window and items
        window.clear();
        window.draw(playerShip);
        window.draw(rocketBody);
        //Wave 1 Enemies
        window.draw(enemyShip);
        window.draw(enemyShip2);
        window.draw(enemyShip3);
        window.draw(enemyShip4);
        //Wave 2 Enemies
        window.draw(enemyShip5);
        window.draw(enemyShip6);
        window.draw(enemyShip7);
        //Wave 3 Enemies
        window.draw(enemyShip8);
        window.draw(enemyShip9);
        window.draw(enemyShip10);
        window.draw(enemyShip11);
        window.draw(enemyShip12);

        window.display();

    }//end of main loop

    return 0;
}
#pragma endregion
