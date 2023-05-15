//
// Created by Adam G. on 11/20/2021.
// https://en.sfml-dev.org/forums/index.php?topic=19928.0

#ifndef KINGS_CORNER_RESOURCEHOLDER_H
#define KINGS_CORNER_RESOURCEHOLDER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <SFML/Audio/SoundBuffer.hpp>

class ResourceHolder {
private:
    static std::map<std::string, sf::Texture> textures;
    static std::map<std::string, sf::Font> fonts;
    static std::map<std::string, sf::SoundBuffer> sounds;
public:
    static sf::Texture& getTexture(const std::string& path);
    static sf::Font& getFont(const std::string& path);
    static sf::SoundBuffer& getSoundBuffer(const std::string& path);
};


#endif //KINGS_CORNER_RESOURCEHOLDER_H
