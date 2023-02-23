#pragma once
#ifndef AUDIO_H
#define AUDIO_H

#include <SFML/Audio.hpp>

class Audio
{
private:
    sf::SoundBuffer m_Sound;
    sf::Sound m_SoundBoing;

public:
    sf::Sound getSound();
};

#endif // AUDIO_H
