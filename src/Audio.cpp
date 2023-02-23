#include "Audio.h"

sf::Sound Audio::getSound()
{
    m_Sound.loadFromFile("audio/sfx-boing9.wav");
    m_SoundBoing.setBuffer(m_Sound);
    m_SoundBoing.setVolume(50.f);
    m_SoundBoing.play();

    return m_SoundBoing;
}
