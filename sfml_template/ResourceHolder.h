//
// Created by Adam G. on 11/20/2021.
// https://en.sfml-dev.org/forums/index.php?topic=19928.0

#ifndef CS3A_KINGS_CORNER_RESOURCEHOLDER_H
#define CS3A_KINGS_CORNER_RESOURCEHOLDER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <SFML/Audio/SoundBuffer.hpp>

class ResourceHolder {
private:
    static std::map<std::string, sf::Texture> textures;
    static std::map<std::string, sf::Font> fonts;
    static std::map<std::string, sf::SoundBuffer> sounds;
public:
    static sf::Texture& getTexture(std::string path);
    static sf::Font& getFont(std::string path);
    static sf::SoundBuffer& getSoundBuffer(std::string path);
};


#endif //CS3A_KINGS_CORNER_RESOURCEHOLDER_H
