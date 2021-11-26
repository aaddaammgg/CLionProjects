//
// Created by Adam G. on 11/1/2021.
// https://en.sfml-dev.org/forums/index.php?topic=19928.0

#ifndef CS3A_POKER_ANALYSIS_RESOURCEHOLDER_H
#define CS3A_POKER_ANALYSIS_RESOURCEHOLDER_H

#include <SFML/Graphics.hpp>
#include <map>

class ResourceHolder {
private:
    static std::map<std::string, sf::Texture> textures;
    static std::map<std::string, sf::Font> fonts;
public:
    static sf::Texture& getTexture(std::string path);
    static sf::Font& getFont(std::string path);
};


#endif //CS3A_POKER_ANALYSIS_RESOURCEHOLDER_H
