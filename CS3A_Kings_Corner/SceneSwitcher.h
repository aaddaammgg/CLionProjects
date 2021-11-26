//
// Created by Adam Gonzalez on 11/25/21.
//

#ifndef SFML_KINGS_CORNER_SCENESWITCHER_H
#define SFML_KINGS_CORNER_SCENESWITCHER_H

#include "ScenesENUM.h"

class SceneSwitcher {
private:
    ScenesENUM currentScene;
    bool sceneChanged = false;
    void setCurrentScene(ScenesENUM scene);
public:
    SceneSwitcher();

    void setSceneChanged();
    bool getSceneChanged() const;

    void changeScene(ScenesENUM scene);
    ScenesENUM getCurrentScene() const;
};


#endif //SFML_KINGS_CORNER_SCENESWITCHER_H
