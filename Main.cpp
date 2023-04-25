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
    enemy.width = 40;
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
    player.width = 50;
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
    sf::Vector2f enemyShipPosistion(300, 50);
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
    sf::Vector2f enemyShipPosistion5(400, -120);
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
    sf::Vector2f enemyShipPosistion8(375, -60);
    enemyShip8.setPosition(enemyShipPosistion8);
    enemyShip8.setOrigin(enemy.width / 2, enemy.height / 2);

    sf::RectangleShape enemyShip9(sf::Vector2f(enemy.width, enemy.height));
    enemyShip9.setFillColor(sf::Color::Green);
    sf::Vector2f enemyShipPosistion9(75, -100);
    enemyShip9.setPosition(enemyShipPosistion9);
    enemyShip9.setOrigin(enemy.width / 2, enemy.height / 2);

    sf::RectangleShape enemyShip10(sf::Vector2f(enemy.width, enemy.height));
    enemyShip10.setFillColor(sf::Color::Red);
    sf::Vector2f enemyShipPosistion10(750, -20);
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

#pragma region Creating Sprites

    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("C:/Users/TKraf/sfmlGame/sprites/PlayerSprite.png")) {
        std::cout << "Error loading player ship's texture" << std::endl;
        return 0;
    }
    sf::Sprite playerSprite;
    playerSprite.setTexture(playerTexture);
    sf::Vector2f playerSpritePosition = sf::Vector2f(windowWidth/2, windowHeight-60);
    playerSprite.setPosition(playerSpritePosition);
    playerSprite.scale(sf::Vector2f(1, 1.5));
    playerSprite.setOrigin(player.width/2,player.height/2);

    sf::Texture basicEnemyTexture;
    if (!basicEnemyTexture.loadFromFile("C:/Users/TKraf/sfmlGame/sprites/PurpleSprite.png")) {
        std::cout << "Error loading basic enemy ship's texture" << std::endl;
        return 0;
    }
    sf::Sprite basicEnemySprite;
    basicEnemySprite.setTexture(basicEnemyTexture);
    sf::Vector2f basicEnemySpritePosition = enemyShipPosistion;
    basicEnemySprite.setPosition(enemyShipPosistion);
    basicEnemySprite.scale(sf::Vector2f(1, 1.5));
    basicEnemySprite.setOrigin(enemy.width / 2, enemy.height / 2);

    sf::Sprite basicEnemySprite2;
    basicEnemySprite2.setTexture(basicEnemyTexture);
    sf::Vector2f basicEnemySpritePosition2 = enemyShipPosistion2;
    basicEnemySprite2.setPosition(enemyShipPosistion2);
    basicEnemySprite2.scale(sf::Vector2f(1, 1.5));
    basicEnemySprite2.setOrigin(enemy.width / 2, enemy.height / 2);

    sf::Sprite basicEnemySprite3;
    basicEnemySprite3.setTexture(basicEnemyTexture);
    sf::Vector2f basicEnemySpritePosition3 = enemyShipPosistion3;
    basicEnemySprite3.setPosition(enemyShipPosistion3);
    basicEnemySprite3.scale(sf::Vector2f(1, 1.5));
    basicEnemySprite3.setOrigin(enemy.width / 2, enemy.height / 2);

    sf::Sprite basicEnemySprite4;
    basicEnemySprite4.setTexture(basicEnemyTexture);
    sf::Vector2f basicEnemySpritePosition4 = enemyShipPosistion4;
    basicEnemySprite4.setPosition(enemyShipPosistion4);
    basicEnemySprite4.scale(sf::Vector2f(1, 1.5));
    basicEnemySprite4.setOrigin(enemy.width / 2, enemy.height / 2);

    sf::Sprite basicEnemySprite8;
    basicEnemySprite8.setTexture(basicEnemyTexture);
    sf::Vector2f basicEnemySpritePosition8 = enemyShipPosistion8;
    basicEnemySprite8.setPosition(enemyShipPosistion8);
    basicEnemySprite8.scale(sf::Vector2f(1, 1.5));
    basicEnemySprite8.setOrigin(enemy.width / 2, enemy.height / 2);

    sf::Sprite basicEnemySprite10;
    basicEnemySprite10.setTexture(basicEnemyTexture);
    sf::Vector2f basicEnemySpritePosition10 = enemyShipPosistion10;
    basicEnemySprite10.setPosition(enemyShipPosistion10);
    basicEnemySprite10.scale(sf::Vector2f(1, 1.5));
    basicEnemySprite10.setOrigin(enemy.width / 2, enemy.height / 2);

    sf::Texture fastEnemyTexture;
    if (!fastEnemyTexture.loadFromFile("C:/Users/TKraf/sfmlGame/sprites/BugShipSprite.png")) {
        std::cout << "Error loading fast enemy ship's texture" << std::endl;
        return 0;
    }
    sf::Sprite fastEnemySprite5;
    fastEnemySprite5.setTexture(fastEnemyTexture);
    sf::Vector2f fastEnemySpritePosition5 = enemyShipPosistion5;
    fastEnemySprite5.setPosition(enemyShipPosistion5);
    fastEnemySprite5.scale(sf::Vector2f(1, 1.5));
    fastEnemySprite5.setOrigin(enemy.width / 2, enemy.height / 2);

    sf::Sprite fastEnemySprite6;
    fastEnemySprite6.setTexture(fastEnemyTexture);
    sf::Vector2f fastEnemySpritePosition6 = enemyShipPosistion6;
    fastEnemySprite6.setPosition(enemyShipPosistion6);
    fastEnemySprite6.scale(sf::Vector2f(1, 1.5));
    fastEnemySprite6.setOrigin(enemy.width / 2, enemy.height / 2);

    sf::Sprite fastEnemySprite7;
    fastEnemySprite7.setTexture(fastEnemyTexture);
    sf::Vector2f fastEnemySpritePosition7 = enemyShipPosistion7;
    fastEnemySprite7.setPosition(enemyShipPosistion7);
    fastEnemySprite7.scale(sf::Vector2f(1, 1.5));
    fastEnemySprite7.setOrigin(enemy.width / 2, enemy.height / 2);

    sf::Sprite fastEnemySprite9;
    fastEnemySprite9.setTexture(fastEnemyTexture);
    sf::Vector2f fastEnemySpritePosition9 = enemyShipPosistion9;
    fastEnemySprite9.setPosition(enemyShipPosistion9);
    fastEnemySprite9.scale(sf::Vector2f(1, 1.5));
    fastEnemySprite9.setOrigin(enemy.width / 2, enemy.height / 2);

    sf::Sprite fastEnemySprite11;
    fastEnemySprite11.setTexture(fastEnemyTexture);
    sf::Vector2f fastEnemySpritePosition11 = enemyShipPosistion11;
    fastEnemySprite11.setPosition(enemyShipPosistion11);
    fastEnemySprite11.scale(sf::Vector2f(1, 1.5));
    fastEnemySprite11.setOrigin(enemy.width / 2, enemy.height / 2);

    sf::Sprite fastEnemySprite12;
    fastEnemySprite12.setTexture(fastEnemyTexture);
    sf::Vector2f fastEnemySpritePosition12 = enemyShipPosistion12;
    fastEnemySprite12.setPosition(enemyShipPosistion12);
    fastEnemySprite12.scale(sf::Vector2f(1, 1.5));
    fastEnemySprite12.setOrigin(enemy.width / 2, enemy.height / 2);
#pragma endregion

#pragma region Adding Font and Text

    sf::Font font;
    if (!font.loadFromFile("C:/Users/TKraf/sfmlGame/Open-sans/OpenSans-Bold.ttf"))
    {
        std::cout << "Error loading the font file" << std::endl;
    }
    sf::Text loserText;
    loserText.setFont(font); // font is a sf::Font
    loserText.setString("Game Over!");
    loserText.setCharacterSize(48);
    loserText.setFillColor(sf::Color::Red);
    loserText.setPosition(windowWidth/2-150, windowHeight/2);

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
    bool start = false;
    //Main loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        while (!start) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                start = true;
        }

        //changing player direction
        player.playerMovement(player.xVelocity);

        //Making sure player and enemies stay within horizontal bounds of window
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
        //moving enemySprite on window
        basicEnemySpritePosition.x += enemy.xVelocity;
        basicEnemySpritePosition.y += enemy.getyVelocity();
        basicEnemySprite.setPosition(basicEnemySpritePosition);
        //moving enemyShip2 on window
        enemyShipPosistion2.x += enemy2.xVelocity;
        enemyShipPosistion2.y += enemy2.getyVelocity();
        enemyShip2.setPosition(enemyShipPosistion2);
        //moving enemySprite2 on window
        basicEnemySpritePosition2.x += enemy2.xVelocity;
        basicEnemySpritePosition2.y += enemy2.getyVelocity();
        basicEnemySprite2.setPosition(basicEnemySpritePosition2);
        //moving enemyShip3 on window
        enemyShipPosistion3.x += enemy3.xVelocity;
        enemyShipPosistion3.y += enemy3.getyVelocity();
        enemyShip3.setPosition(enemyShipPosistion3);
        //moving enemySprite3 on window
        basicEnemySpritePosition3.x += enemy3.xVelocity;
        basicEnemySpritePosition3.y += enemy3.getyVelocity();
        basicEnemySprite3.setPosition(basicEnemySpritePosition3);
        //moving enemyShip4 on window
        enemyShipPosistion4.x += enemy4.xVelocity;
        enemyShipPosistion4.y += enemy4.getyVelocity();
        enemyShip4.setPosition(enemyShipPosistion4);
        //moving enemySprite4 on window
        basicEnemySpritePosition4.x += enemy4.xVelocity;
        basicEnemySpritePosition4.y += enemy4.getyVelocity();
        basicEnemySprite4.setPosition(basicEnemySpritePosition4);
        //moving enemyShip5 on window
        enemyShipPosistion5.x += enemy5.xVelocity;
        enemyShipPosistion5.y += enemy5.getyVelocity();
        enemyShip5.setPosition(enemyShipPosistion5);
        //moving enemySprite5 on window
        fastEnemySpritePosition5.x += enemy5.xVelocity;
        fastEnemySpritePosition5.y += enemy5.getyVelocity();
        fastEnemySprite5.setPosition(fastEnemySpritePosition5);
        //moving enemyShip6 on window
        enemyShipPosistion6.x += enemy6.xVelocity;
        enemyShipPosistion6.y += enemy6.getyVelocity();
        enemyShip6.setPosition(enemyShipPosistion6);
        //moving enemySprite6 on window
        fastEnemySpritePosition6.x += enemy6.xVelocity;
        fastEnemySpritePosition6.y += enemy6.getyVelocity();
        fastEnemySprite6.setPosition(fastEnemySpritePosition6);
        //moving enemyShip7 on window
        enemyShipPosistion7.x += enemy7.xVelocity;
        enemyShipPosistion7.y += enemy7.getyVelocity();
        enemyShip7.setPosition(enemyShipPosistion7);
        //moving enemySprite7 on window
        fastEnemySpritePosition7.x += enemy7.xVelocity;
        fastEnemySpritePosition7.y += enemy7.getyVelocity();
        fastEnemySprite7.setPosition(fastEnemySpritePosition7);
        //moving enemyShip8 on window
        enemyShipPosistion8.x += enemy8.xVelocity;
        enemyShipPosistion8.y += enemy8.getyVelocity();
        enemyShip8.setPosition(enemyShipPosistion8);
        //moving enemySprite8 on window
        basicEnemySpritePosition8.x += enemy8.xVelocity;
        basicEnemySpritePosition8.y += enemy8.getyVelocity();
        basicEnemySprite8.setPosition(basicEnemySpritePosition8);
        //moving enemyShip9 on window
        enemyShipPosistion9.x += enemy9.xVelocity;
        enemyShipPosistion9.y += enemy9.getyVelocity();
        enemyShip9.setPosition(enemyShipPosistion9);
        //moving enemySprite9 on window
        fastEnemySpritePosition9.x += enemy9.xVelocity;
        fastEnemySpritePosition9.y += enemy9.getyVelocity();
        fastEnemySprite9.setPosition(fastEnemySpritePosition9);
        //moving enemyShip10 on window
        enemyShipPosistion10.x += enemy10.xVelocity;
        enemyShipPosistion10.y += enemy10.getyVelocity();
        enemyShip10.setPosition(enemyShipPosistion10);
        //moving enemySprite10 on window
        basicEnemySpritePosition10.x += enemy10.xVelocity;
        basicEnemySpritePosition10.y += enemy10.getyVelocity();
        basicEnemySprite10.setPosition(basicEnemySpritePosition10);
        //moving enemyShip11 on window
        enemyShipPosistion11.x += enemy11.xVelocity;
        enemyShipPosistion11.y += enemy11.getyVelocity();
        enemyShip11.setPosition(enemyShipPosistion11);
        //moving enemySprite11 on window
        fastEnemySpritePosition11.x += enemy11.xVelocity;
        fastEnemySpritePosition11.y += enemy11.getyVelocity();
        fastEnemySprite11.setPosition(fastEnemySpritePosition11);
        //moving enemyShip10 on window
        enemyShipPosistion12.x += enemy12.xVelocity;
        enemyShipPosistion12.y += enemy12.getyVelocity();
        enemyShip12.setPosition(enemyShipPosistion12);
        //moving enemySprite12 on window
        fastEnemySpritePosition12.x += enemy12.xVelocity;
        fastEnemySpritePosition12.y += enemy12.getyVelocity();
        fastEnemySprite12.setPosition(fastEnemySpritePosition12);

        //moving player's ship
        playerShipPosition.x += player.xVelocity;
        playerShip.setPosition(playerShipPosition);

        //moving player's Sprite
        playerSpritePosition.x += player.xVelocity;
        playerSprite.setPosition(playerSpritePosition);

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

        //Kill enemies if they get hit by the rocket
        if (rocketBody.getGlobalBounds().intersects(enemyShip.getGlobalBounds())) {
            enemyShip.setFillColor(sf::Color::Transparent);
            basicEnemySprite.setColor(sf::Color::Transparent);
            enemy.setyVelocity(0);
        }
        if (rocketBody.getGlobalBounds().intersects(enemyShip2.getGlobalBounds())) {
            enemyShip2.setFillColor(sf::Color::Transparent);
            basicEnemySprite2.setColor(sf::Color::Transparent);
            enemy2.setyVelocity(0);
        }
        if (rocketBody.getGlobalBounds().intersects(enemyShip3.getGlobalBounds())) {
            enemyShip3.setFillColor(sf::Color::Transparent);
            basicEnemySprite3.setColor(sf::Color::Transparent);
            enemy3.setyVelocity(0);
        }
        if (rocketBody.getGlobalBounds().intersects(enemyShip4.getGlobalBounds())) {
            enemyShip4.setFillColor(sf::Color::Transparent);
            basicEnemySprite4.setColor(sf::Color::Transparent);
            enemy4.setyVelocity(0);
        }
        if (rocketBody.getGlobalBounds().intersects(enemyShip5.getGlobalBounds())) {
            enemyShip5.setFillColor(sf::Color::Transparent);
            fastEnemySprite5.setColor(sf::Color::Transparent);
            enemy5.setyVelocity(0);
        }
        if (rocketBody.getGlobalBounds().intersects(enemyShip6.getGlobalBounds())) {
            enemyShip6.setFillColor(sf::Color::Transparent);
            fastEnemySprite6.setColor(sf::Color::Transparent);
            enemy6.setyVelocity(0);
        }
        if (rocketBody.getGlobalBounds().intersects(enemyShip7.getGlobalBounds())) {
            enemyShip7.setFillColor(sf::Color::Transparent);
            fastEnemySprite7.setColor(sf::Color::Transparent);
            enemy7.setyVelocity(0);
        }
        if (rocketBody.getGlobalBounds().intersects(enemyShip8.getGlobalBounds())) {
            enemyShip8.setFillColor(sf::Color::Transparent);
            basicEnemySprite8.setColor(sf::Color::Transparent);
            enemy8.setyVelocity(0);
        }
        if (rocketBody.getGlobalBounds().intersects(enemyShip9.getGlobalBounds())) {
            enemyShip9.setFillColor(sf::Color::Transparent);
            fastEnemySprite9.setColor(sf::Color::Transparent);
            enemy9.setyVelocity(0);
        }
        if (rocketBody.getGlobalBounds().intersects(enemyShip10.getGlobalBounds())) {
            enemyShip10.setFillColor(sf::Color::Transparent);
            basicEnemySprite10.setColor(sf::Color::Transparent);
            enemy10.setyVelocity(0);
        }
        if (rocketBody.getGlobalBounds().intersects(enemyShip11.getGlobalBounds())) {
            enemyShip11.setFillColor(sf::Color::Transparent);
            fastEnemySprite11.setColor(sf::Color::Transparent);
            enemy11.setyVelocity(0);
        }
        if (rocketBody.getGlobalBounds().intersects(enemyShip12.getGlobalBounds())) {
            enemyShip12.setFillColor(sf::Color::Transparent);
            fastEnemySprite12.setColor(sf::Color::Transparent);
            enemy12.setyVelocity(0);
        }

        //if rocket goes of screen return it to the player
        if (rocketBodyPosition.y < 0) {
            moveRocket = false;
            rocketBodyPosition.x = playerShipPosition.x;
            rocketBodyPosition.y = playerShipPosition.y;
            rocketBody.setPosition(rocketBodyPosition.x, rocketBodyPosition.y);
        }
        
        if (enemyShipPosistion.y > 720 || enemyShipPosistion2.y > 720 || enemyShipPosistion3.y > 720 || enemyShipPosistion4.y > 720
            || enemyShipPosistion5.y > 720 || enemyShipPosistion6.y > 720 || enemyShipPosistion7.y > 720 || enemyShipPosistion8.y > 720
            || enemyShipPosistion9.y > 720 || enemyShipPosistion10.y > 720 || enemyShipPosistion11.y > 720 || enemyShipPosistion12.y > 720)
        {
            endLoser = true;
        }

        if (endLoser)
        {
            window.draw(loserText);
        }
        //render window and items
        window.clear();
        if (endLoser)
        {
            window.draw(loserText);
        }
        window.draw(playerSprite);
        window.draw(rocketBody);
        //Wave 1 Enemies
        window.draw(basicEnemySprite);
        window.draw(basicEnemySprite2);
        window.draw(basicEnemySprite3);
        window.draw(basicEnemySprite4);
        //Wave 2 Enemies
        window.draw(fastEnemySprite5);
        window.draw(fastEnemySprite6);
        window.draw(fastEnemySprite7);
        //Wave 3 Enemies
        window.draw(basicEnemySprite8);
        window.draw(fastEnemySprite9);
        window.draw(basicEnemySprite10);
        window.draw(fastEnemySprite11);
        window.draw(fastEnemySprite12);

        window.display();

    }//end of main loop

    return 0;
}
#pragma endregion
