#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>

class Ship 
{
    private:
        float yVelocity = .3;
    public:
        int width;
        int height;
        float xVelocity;

        float getyVelocity() {
            return yVelocity;
        }
        void setyVelocity(float yVel) {
            yVelocity = yVel;
        }
        void checkHorizontalBoundaries(sf::Vector2f objectPosition) {
            if (objectPosition.x < 0 + width / 2 || objectPosition.x > 1280 - width / 2)
                xVelocity *= -1;
        }
        void moveVertical() {

        }
};

class Player : public Ship 
{
    public:
        void playerMovement(float &xVel) 
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
};


int main()
{
    enum Window
    {
        windowWidth = 1280,
        windowHeight = 720
    };

    Player player;
    //player's size
    player.width = 100;
    player.height = 25;
    //player's movement speed
    player.xVelocity = 0;

    Ship rocket;
    rocket.setyVelocity(-25);
    rocket.width = 10;
    rocket.height = 20;

    Ship enemy;
    enemy.xVelocity = 3;
    enemy.width = 30;
    enemy.height = 60;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Its Alive!");
    window.setFramerateLimit(60);

    //Setting playerShip on screen and formating
    sf::RectangleShape playerShip;
    sf::Vector2f playerShipPosition(windowWidth / 2, windowHeight - player.height / 2);
    playerShip.setPosition(playerShipPosition);
    playerShip.setSize(sf::Vector2f(player.width, player.height));
    playerShip.setOrigin(player.width/2, player.height / 2);

    sf::RectangleShape rocketBody(sf::Vector2f(rocket.width, rocket.height));
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
        window.display();

    }//end of main loop

    return 0;
}