//
// Created by Adam Gonzalez on 11/25/21.
//

#include "SceneSwitcher.h"

SceneSwitcher::SceneSwitcher() {

}

void SceneSwitcher::setCurrentScene(ScenesENUM scene) {
    currentScene = scene;
}

void SceneSwitcher::changeScene(ScenesENUM scene) {
    setCurrentScene(scene);
}

ScenesENUM SceneSwitcher::getCurrentScene() const {
    return currentScene;
}