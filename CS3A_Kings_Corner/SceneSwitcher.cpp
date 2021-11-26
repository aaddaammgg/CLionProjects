//
// Created by Adam Gonzalez on 11/25/21.
//

#include "SceneSwitcher.h"

SceneSwitcher::SceneSwitcher() {

}

bool SceneSwitcher::getSceneChanged() const {
    return sceneChanged;
}

void SceneSwitcher::setSceneChanged() {
    sceneChanged = false;
}

void SceneSwitcher::setCurrentScene(ScenesENUM scene) {
    currentScene = scene;
}

void SceneSwitcher::changeScene(ScenesENUM scene) {
    sceneChanged = true;
    setCurrentScene(scene);
}

ScenesENUM SceneSwitcher::getCurrentScene() const {
    return currentScene;
}