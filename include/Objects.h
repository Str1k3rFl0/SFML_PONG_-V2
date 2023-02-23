#pragma once
#ifndef OBJECTS_H
#define OBJECTS_H

#include <SFML/Graphics.hpp>

class Objects
{
protected:
    sf::RectangleShape m_Objects; // Rectangle Shape
    sf::Vector2f m_Pos; // The position of the Shape

public:
    //Objects(float startX, float startY); // Constructor with 2 arguments witch represent the start position
    void createObj(float startX, float startY);
    sf::FloatRect getRectPosition(); // Return the position of the shape
    sf::RectangleShape getRectShape(); // Return the rectangle shape
};

#endif // OBJECTS_H
