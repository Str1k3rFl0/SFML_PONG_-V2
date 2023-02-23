#include <SFML/Graphics.hpp>

#include <iostream>
#include <sstream>
#include <string>

#include "Bat.h"
#include "Objects.h"
#include "Ball.h"
#include "Audio.h"

#define MAX_SCORE 3

struct Utility
{
    sf::Font font;
    sf::Text messageText[7];
    sf::Texture textureButtons[3];
    sf::Texture textureBackground;
    sf::Sprite spriteButtons[3];
    sf::Sprite spriteBackground;

    std::stringstream ssText[6];

}; Utility ut;

int main()
{
    Audio ad;

    using kb = sf::Keyboard;

    enum class StateGame
    {
        MENU,
        EXIT,
        CONTROLS,
        PLAY
    };
    StateGame state = StateGame::MENU;

    // Create the players
    std::string player[2]{};
    int score[2]{ 0 };

    std::cout << "Max 6 characters!\n\n";

    // Player 1
    std::cout << "Player 1 :: ";
    std::getline(std::cin >> std::ws, player[0]);

    // Player 2
    std::cout << "Player 2 :: ";
    std::getline(std::cin >> std::ws, player[1]);

    // Variables to create the window
    sf::Vector2f resolution;
    sf::VideoMode vm;
    sf::RenderWindow window;

    // Create the window
    resolution.x = vm.getDesktopMode().width;
    resolution.y = vm.getDesktopMode().height;
    window.create(sf::VideoMode(resolution.x, resolution.y),
                  "PONG V2", sf::Style::Fullscreen);
    // Set the FPS to 75
    window.setFramerateLimit(75);

    // Create the bat
    Bat bat1(30, 1080/2);
    Bat bat2(1860, 1080/2);

    // Create the Object
    //Objects obj(resolution.x / 2, 0);
    //Objects obj;
    //obj.createObj(resolution.x / 2, 0);

    // Create the Ball
    Ball ball(resolution.x / 2, resolution.y / 2);

    // Create the object
    ball.createObj(resolution.x / 2, 0);

    // Create the font
    ut.font.loadFromFile("fonts/lightfont.otf");

    // Control State
    ut.messageText[0].setFont(ut.font);
    ut.messageText[0].setPosition(400, 200);
    ut.messageText[0].setFillColor(sf::Color::White);
    ut.ssText[0] << "\tPlayer 1: "
                 << "\n\nPress W to move Up"
                 << "\nPress S to move Down";
    ut.messageText[0].setString(ut.ssText[0].str());

    ut.messageText[1].setFont(ut.font);
    ut.messageText[1].setPosition(1000, 200);
    ut.messageText[1].setFillColor(sf::Color::White);
    ut.ssText[1] << "\tPlayer 2:"
                 << "\n\nPress Up key to move Up"
                 << "\nPress Down key to move Down";
    ut.messageText[1].setString(ut.ssText[1].str());

    ut.messageText[2].setFont(ut.font);
    ut.messageText[2].setPosition(200, 800);
    ut.messageText[2].setFillColor(sf::Color::White);
    ut.messageText[2].setString("Press Esc to continue...");

    // Create the Exit Button
    ut.textureButtons[0].loadFromFile("buttons/exitButton.png");
    ut.spriteButtons[0].setTexture(ut.textureButtons[0]);
    ut.spriteButtons[0].setPosition(850, 600);
    ut.spriteButtons[0].setScale(0.3f, 0.3f);

    // Create the Control Button
    ut.textureButtons[1].loadFromFile("buttons/controlButton.png");
    ut.spriteButtons[1].setTexture(ut.textureButtons[1]);
    ut.spriteButtons[1].setPosition(850, 500);
    ut.spriteButtons[1].setScale(0.3f, 0.3f);

    // Create the Play Button
    ut.textureButtons[2].loadFromFile("buttons/playButton.png");
    ut.spriteButtons[2].setTexture(ut.textureButtons[2]);
    ut.spriteButtons[2].setPosition(850, 400);
    ut.spriteButtons[2].setScale(0.3f, 0.3f);

    // Create the Background
    ut.textureBackground.loadFromFile("graphics/backgroundStory.jpg");
    ut.spriteBackground.setTexture(ut.textureBackground);
    ut.spriteBackground.setPosition(0, 0);

    // Players Text
    ut.messageText[3].setFont(ut.font);
    ut.messageText[3].setString(player[0]);
    ut.messageText[3].setCharacterSize(30);
    ut.messageText[3].setFillColor(sf::Color::Magenta);
    ut.messageText[3].setPosition(20, 20);
    ut.ssText[2] << "Player: " << player[0] << "  Score: " << score[0];
    ut.messageText[3].setString(ut.ssText[2].str());

    ut.messageText[4].setFont(ut.font);
    ut.messageText[4].setString(player[1]);
    ut.messageText[4].setCharacterSize(30);
    ut.messageText[4].setFillColor(sf::Color::Magenta);
    ut.messageText[4].setPosition(1550, 20);
    ut.ssText[3] << "Player: " << player[1] << "  Score: " << score[1];
    ut.messageText[4].setString(ut.ssText[3].str());

    ut.messageText[5].setFont(ut.font);
    ut.messageText[5].setString(" Win the game!");
    ut.messageText[5].setCharacterSize(35);
    ut.messageText[5].setFillColor(sf::Color::Cyan);
    sf::FloatRect textRect = ut.messageText[5].getLocalBounds();
    ut.messageText[5].setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    ut.messageText[5].setPosition(1920 / 2, 1080 / 2);

    ut.messageText[6].setFont(ut.font);
    ut.messageText[6].setString(" Win the game!");
    ut.messageText[6].setCharacterSize(35);
    ut.messageText[6].setFillColor(sf::Color::Cyan);
    sf::FloatRect textRect2 = ut.messageText[6].getLocalBounds();
    ut.messageText[6].setOrigin(textRect2.left +
        textRect2.width / 2.0f,
        textRect2.top +
        textRect2.height / 2.0f);
    ut.messageText[6].setPosition(1920 / 2, 1080 / 2);

    ut.ssText[4] << player[0] << " Win the game!\nPress ESC to exit";
    ut.messageText[5].setString(ut.ssText[4].str());

    ut.ssText[5] << player[1] << " Win the game!\nPress ESC to exit";
    ut.messageText[6].setString(ut.ssText[5].str());


    // We need clock
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // From Control to MENU
            if (event.key.code == kb::Escape &&
                state == StateGame::CONTROLS)
            {
                state = StateGame::MENU;

            }

            else if (event.key.code == kb::Escape &&
                state == StateGame::PLAY)
            {
                window.close();
            }

            if (state == StateGame::MENU)
            {
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    sf::Vector2i mousePos(event.mouseButton.x, event.mouseButton.y);
                    sf::Vector2f clickPos(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));

                    if (ut.spriteButtons[0].getGlobalBounds().contains(clickPos))
                    {
                        window.close();
                    }

                    else if (ut.spriteButtons[1].getGlobalBounds().contains(clickPos))
                    {
                        if (state == StateGame::MENU)
                        {
                            state = StateGame::CONTROLS;
                        }

                        if (event.key.code == kb::Escape &&
                            state == StateGame::CONTROLS)
                        {
                            state = StateGame::MENU;
                        }
                    }

                    else if (ut.spriteButtons[2].getGlobalBounds().contains(clickPos))
                    {
                        if (state == StateGame::MENU)
                        {
                            state = StateGame::PLAY;
                            window.setMouseCursorVisible(false);
                            clock.restart();
                        }

                        if (event.key.code == kb::Escape &&
                            state == StateGame::PLAY)
                        {
                            window.close();
                        }
                    }
                }
            }
        }

        if (state == StateGame::PLAY)
        {
            // Bat 1 moving
            if (kb::isKeyPressed(kb::W))
            {
                bat1.isMovingUp();
            }
            else
            {
                bat1.stopMovingUp();
            }

            if  (kb::isKeyPressed(kb::S))
            {
                bat1.isMovingDown();
            }
            else
            {
                bat1.stopMovingDown();
            }

            // Bat 2 moving
            if (kb::isKeyPressed(kb::Up))
            {
                bat2.isMovingUp();
            }
            else
            {
                bat2.stopMovingUp();
            }

            if (kb::isKeyPressed(kb::Down))
            {
                bat2.isMovingDown();
            }
            else
            {
                bat2.stopMovingDown();
            }
        }

        if (state == StateGame::PLAY)
        {
            // Update the scene
            sf::Time dt = clock.restart();
            float elapsedTime = dt.asSeconds();
            bat1.update(elapsedTime, window);
            bat2.update(elapsedTime, window);
            ball.update(elapsedTime);

            // Collide Ball with walls
            // Left
            if (ball.getBallShape().getPosition().x < 0.f)
            {
                ball.colLeftWall();
                score[1] += 1;
                ad.getSound();
            }

            // Right
            if (ball.getBallShape().getPosition().x + ball.getBallShape().getGlobalBounds().width > resolution.x)
            {
                ball.colRightWall();
                score[0] += 1;
                ad.getSound();
            }

            // Top
            if (ball.getBallShape().getGlobalBounds().top < 0.f)
            {
                ball.colTopWall();
                ad.getSound();
            }

            // Bottom
            if (ball.getBallShape().getPosition().y + ball.getBallShape().getGlobalBounds().height > resolution.y)
            {
                ball.colDownWall();
                ad.getSound();
            }

            // Collision between bats and ball
            // Sides
            if (ball.getBallPosition().intersects(bat1.getPosition()))
            {
                ball.colBat();
            }

            if (ball.getBallPosition().intersects(bat2.getPosition()))
            {
                ball.colBat();
            }
        }
        // Draw the scene
        window.clear();
        if (state == StateGame::MENU)
        {
            window.draw(ut.spriteBackground);
            window.draw(ut.spriteButtons[0]);
            window.draw(ut.spriteButtons[1]);
            window.draw(ut.spriteButtons[2]);
        }

        if (state == StateGame::CONTROLS)
        {
            window.draw(ut.spriteBackground);
            window.draw(ut.messageText[0]);
            window.draw(ut.messageText[1]);
            window.draw(ut.messageText[2]);
        }

        if (state == StateGame::PLAY)
        {
            window.draw(ut.messageText[3]);
            window.draw(ut.messageText[4]);
            window.draw(bat1.getBatShape());
            window.draw(bat2.getBatShape());
            window.draw(ball.getRectShape());
            window.draw(ball.getBallShape());

            if (score[0] == MAX_SCORE)
            {
                window.draw(ut.messageText[5]);
                ball.getCenterShape(700, 400);
                ball.ballStop();
            }

            if (score[1] == MAX_SCORE)
            {
                window.draw(ut.messageText[6]);
                ball.getCenterShape(700, 400);
                ball.ballStop();
            }
        }
        window.display();
    }

    return 0;
}
