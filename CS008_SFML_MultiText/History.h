//
// Created by Adam G. on 3/26/2022.
//

#ifndef CS008_SFML_TYPING_HISTORY_H
#define CS008_SFML_TYPING_HISTORY_H

#include <stack>
#include "GUIComponent.h"
#include "Snapshot.h"
#include "HistoryNode.h"

class History {
private:
    static std::stack<HistoryNode> undoStack;
    static std::stack<HistoryNode> redoStack;
public:
    static void undoPush(const HistoryNode& snapshot);
    static HistoryNode& getUndoTop();
    static int getUndoSize();
    static void undoPop();

    static void redoPush(const HistoryNode& snapshot);
    static HistoryNode& getRedoTop();
    static int getRedoSize();
    static void redoPop();

    static void addEventHandler(sf::RenderWindow& window, sf::Event event);
};


#endif //CS008_SFML_TYPING_HISTORY_H
