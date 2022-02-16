//
// Created by Adam G. on 2/12/22.
//

#include "ResourceHolder.h"

std::map<std::string, sf::Texture> ResourceHolder::textures;
std::map<std::string, sf::Font> ResourceHolder::fonts;

sf::Texture &ResourceHolder::getTexture(std::string path) {
    const auto &pairFound = textures.find(path);
    if (pairFound != textures.end()) {
        return pairFound->second;
    } else {
        auto& texture = textures[path];
        texture.loadFromFile(path);
        return texture;
    }
}

sf::Font &ResourceHolder::getFont(std::string path) {
    const auto &pairFound = fonts.find(path);
    if (pairFound != fonts.end()) {
        return pairFound->second;
    } else {
        auto& font = fonts[path];
        font.loadFromFile(path);
        return font;
    }
}
