#include "Ball.h"

Ball::Ball(float startX, float startY)
{
    m_Pos.x = startX;
    m_Pos.y = startY;

    m_BallShape.setRadius(10.f);
    m_BallShape.setFillColor(sf::Color::White);
    m_BallShape.setPosition(m_Pos);
}

sf::FloatRect Ball::getBallPosition()
{
    return m_BallShape.getGlobalBounds();
}

sf::CircleShape Ball::getBallShape()
{
    return m_BallShape;
}

sf::Vector2f Ball::getCenterShape(float x, float y)
{
    m_Pos.x = x;
    m_Pos.y = y;
    m_BallShape.setPosition(m_Pos);
}

float Ball::getSpeed(float speed)
{
    return m_BallSpeed += speed;
}

void Ball::ballStop()
{
    vel.xVelocity = 0;
    vel.yVelocity = 0;
    m_BallSpeed = 0;
}

void Ball::colBat()
{
    vel.xVelocity = -vel.xVelocity;
    //vel.yVelocity = -vel.yVelocity;
}

void Ball::colLeftWall()
{
    m_BallShape.setPosition(0.f, m_BallShape.getPosition().y);
    vel.xVelocity = -vel.xVelocity;
    srand(time(NULL));
    m_BallShape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
}

void Ball::colRightWall()
{
    m_BallShape.setPosition(sc.WINDOW_WIDTH - m_BallShape.getGlobalBounds().width, m_BallShape.getPosition().y);
    vel.xVelocity = -vel.xVelocity;
    srand(time(NULL));
    m_BallShape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
}

void Ball::colTopWall()
{
    m_BallShape.setPosition(m_BallShape.getPosition().x, 0.f);
    vel.yVelocity = -vel.yVelocity;
    srand(time(NULL));
    m_BallShape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
}

void Ball::colDownWall()
{
    m_BallShape.setPosition(m_BallShape.getPosition().x, sc.WINDOW_HEIGHT - m_BallShape.getGlobalBounds().height);
    vel.yVelocity = -vel.yVelocity;
    srand(time(NULL));
    m_BallShape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
}

void Ball::colObsRight()
{
    if (m_BallShape.getGlobalBounds().left < m_Objects.getGlobalBounds().left
        && m_BallShape.getGlobalBounds().left + m_BallShape.getGlobalBounds().width < m_Objects.getGlobalBounds().left + m_Objects.getGlobalBounds().width
        && m_BallShape.getGlobalBounds().top < m_Objects.getGlobalBounds().top + m_Objects.getGlobalBounds().height
        && m_BallShape.getGlobalBounds().top + m_Objects.getGlobalBounds().height > m_Objects.getGlobalBounds().top)
    {
        m_BallShape.setPosition(m_Objects.getGlobalBounds().left - m_BallShape.getGlobalBounds().width, m_BallShape.getGlobalBounds().top);
        vel.xVelocity = -vel.xVelocity;
    }
}

void Ball::colObsLeft()
{
    if (m_BallShape.getGlobalBounds().left > m_Objects.getGlobalBounds().left
        && m_BallShape.getGlobalBounds().left + m_BallShape.getGlobalBounds().width > m_Objects.getGlobalBounds().left + m_Objects.getGlobalBounds().width
        && m_BallShape.getGlobalBounds().top < m_Objects.getGlobalBounds().top + m_Objects.getGlobalBounds().height
        && m_BallShape.getGlobalBounds().top + m_Objects.getGlobalBounds().height > m_Objects.getGlobalBounds().top)
    {
        m_BallShape.setPosition(m_Objects.getGlobalBounds().left + m_Objects.getGlobalBounds().width, m_BallShape.getGlobalBounds().top);
        vel.xVelocity = -vel.xVelocity;
    }
}

void Ball::update(float elapsedTime)
{
    // Move the ball
    m_Pos.x += vel.xVelocity * m_BallSpeed * elapsedTime;
    m_Pos.y += vel.yVelocity * m_BallSpeed * elapsedTime;
    m_BallShape.setPosition(m_Pos);

    // Update the collide
    if (m_Objects.getGlobalBounds().intersects(m_BallShape.getGlobalBounds()))
    {
        colObsRight();
        colObsLeft();
    }
}
