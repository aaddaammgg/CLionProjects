//
// Created by Adam G. on 3/26/2022.
//

#ifndef CS008_SFML_TYPING_HISTORYNODE_H
#define CS008_SFML_TYPING_HISTORYNODE_H

#include "GUIComponent.h"
#include "Snapshot.h"

struct HistoryNode {
    Snapshot snapshot;
    GUIComponent* component;
};

#endif //CS008_SFML_TYPING_HISTORYNODE_H
