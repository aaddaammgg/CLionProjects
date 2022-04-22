//
// Created by Adam G. on 4/21/2022.
//

#ifndef CS008_SFML_FINALPROJECT_IMAGE_H
#define CS008_SFML_FINALPROJECT_IMAGE_H

#include "ResourceHolder.h"

class Image {
public:
    typedef enum {
        DIRECTORY,
        FILE,
    } imageType;

    static sf::Texture& getTexture(Image::imageType icon);
};


#endif //CS008_SFML_FINALPROJECT_IMAGE_H
