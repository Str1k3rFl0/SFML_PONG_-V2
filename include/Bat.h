#pragma once
#ifndef BAT_H
#define BAT_H

#include <SFML/Graphics.hpp>

class Bat
{
protected:

    sf::Vector2f m_Pos; // position of the Bat
    sf::RectangleShape m_BatShape; // The Bat Shape
    float m_BatSpeed { 600 }; // The speed of the bat

    // Need variables to move the Bat
    bool m_MoveUp;
    bool m_MoveDown;

public:
    Bat(float startX, float startY); // Constructor with 2 arguments witch represent the start position
    sf::FloatRect getPosition(); // We need to get the position of the bat
    sf::RectangleShape getBatShape(); // We need to get the shape
    void isMovingUp(); // Function to check if bat is moving Up
    void isMovingDown(); // Function to check if bat is moving Down
    void stopMovingUp(); // Function to stop the bat to move Up
    void stopMovingDown(); // Function to stop the bat to move Down
    void update(float elapsedTime, sf::Window& window); // Update the Bat to move Up and Down
};

#endif // BAT_H
