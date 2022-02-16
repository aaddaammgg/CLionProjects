//
// Created by Adam G. on 2/12/22.
//

#ifndef SFML_SHADOW_BOX_RESOURCEHOLDER_H
#define SFML_SHADOW_BOX_RESOURCEHOLDER_H

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

#endif //SFML_SHADOW_BOX_RESOURCEHOLDER_H
