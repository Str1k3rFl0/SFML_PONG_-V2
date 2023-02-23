#include "Objects.h"

// Constructor for the Object
//Objects::Objects(float startX, float startY)
//{
//    m_Pos.x = startX;
//    m_Pos.y = startY;
//
//    m_Objects.setSize(sf::Vector2f(30, 600));
//    m_Objects.setFillColor(sf::Color::Green);
//    m_Objects.setPosition(m_Pos);
//}

void Objects::createObj(float startX, float startY)
{
    m_Pos.x = startX;
    m_Pos.y = startY;

    m_Objects.setSize(sf::Vector2f(30, 400));
    m_Objects.setFillColor(sf::Color::Green);
    m_Objects.setPosition(m_Pos);
}

sf::FloatRect Objects::getRectPosition()
{
    return m_Objects.getGlobalBounds();
}

sf::RectangleShape Objects::getRectShape()
{
    return m_Objects;
}
