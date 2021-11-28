//
// Created by Adam Gonzalez on 11/25/21.
//

#ifndef SFML_KINGS_CORNER_SCENESWITCHER_H
#define SFML_KINGS_CORNER_SCENESWITCHER_H

#include "ScenesENUM.h"

class SceneSwitcher {
private:
    ScenesENUM currentScene;
    void setCurrentScene(ScenesENUM scene);
public:
    SceneSwitcher();

    void changeScene(ScenesENUM scene);
    ScenesENUM getCurrentScene() const;
};


#endif //SFML_KINGS_CORNER_SCENESWITCHER_H
