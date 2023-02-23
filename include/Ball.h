#pragma once
#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include "Objects.h"

class Ball : public Objects
{
private:

    struct Screen
    {
        int WINDOW_WIDTH  { 1920 };
        int WINDOW_HEIGHT { 1080 };
    }; Screen sc;

    sf::CircleShape m_BallShape; // Make a circle Shape
    sf::Vector2f m_Pos; // Need position for shape
    float m_BallSpeed { 300 }; // Need speed for the ball

public:

    struct Velocity
    {
        float xVelocity { 2 };
        float yVelocity { 2 };
    }; Velocity vel;


    Ball(float startX, float startY);
    sf::FloatRect getBallPosition();
    sf::CircleShape getBallShape();
    sf::Vector2f getCenterShape(float x, float y);
    float getSpeed(float speed);
    void colBat();
    void colLeftWall();
    void colRightWall();
    void colTopWall();
    void colDownWall();
    void colObsRight();
    void colObsLeft();
    void ballStop();
    void update(float elapsedTime);
};

#endif // BALL_H
