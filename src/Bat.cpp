#include "Bat.h"

// Constructor for the Bat
Bat::Bat(float startX, float startY)
{
    // Spawn the Bat
    m_Pos.x = startX;
    m_Pos.y = startY;

    // Create the Bat shape
    m_BatShape.setSize(sf::Vector2f(30, 90));
    m_BatShape.setPosition(m_Pos);

}

// Function to get the position
sf::FloatRect Bat::getPosition()
{
    return m_BatShape.getGlobalBounds();
}

// Function to get the bat
sf::RectangleShape Bat::getBatShape()
{
    return m_BatShape;
}

// Functions to check if bat is moving or not
// Move up
void Bat::isMovingUp()
{
    m_MoveUp = true;
}

// Move down
void Bat::isMovingDown()
{
    m_MoveDown = true;
}

// Stop moving Up
void Bat::stopMovingUp()
{
    m_MoveUp = false;
}

// Stop moving Down
void Bat::stopMovingDown()
{
    m_MoveDown = false;
}

// Function to update the Bat
void Bat::update(float elapsedTime, sf::Window& window)
{
    // Update the bat to move
    if (m_MoveUp)
    {
        m_Pos.y -= m_BatSpeed * elapsedTime;
    }

    if (m_MoveDown)
    {
        m_Pos.y += m_BatSpeed * elapsedTime;
    }

    m_BatShape.setPosition(m_Pos);

    // Collide Top and Bottom of the bat
    // with Top and Bottom of window
    int WINDOW_WIDTH  = window.getSize().x;
    int WINDOW_HEIGHT = window.getSize().y;

    // Top
    if (m_BatShape.getPosition().y < 0.f)
    {
        m_BatShape.setPosition(m_BatShape.getPosition().x, 0.f);
    }

    // Bottom
    if (m_BatShape.getPosition().y + m_BatShape.getGlobalBounds().height > WINDOW_HEIGHT)
    {
        m_BatShape.setPosition(m_BatShape.getPosition().x, WINDOW_HEIGHT - m_BatShape.getGlobalBounds().height);
    }
}
