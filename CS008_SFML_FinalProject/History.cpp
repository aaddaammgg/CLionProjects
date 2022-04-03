//
// Created by Adam G. on 3/26/2022.
//

#include "History.h"

bool History::getInit() {
    return init;
}

void History::setInit(bool b) {
    init = b;
}

void History::undoPush(const HistoryNode &snapshot) {
    undoStack.push(snapshot);
}

HistoryNode &History::getUndoTop() {
    return undoStack.top();
}

int History::getUndoSize() {
    return undoStack.size();
}

void History::undoPop() {
    redoPush(getUndoTop());
    undoStack.pop();
}

void History::redoPush(const HistoryNode &snapshot) {
    redoStack.push(snapshot);
}

HistoryNode &History::getRedoTop() {
    return redoStack.top();
}

int History::getRedoSize() {
    return redoStack.size();
}

void History::redoPop() {
    undoPush(getRedoTop());
    redoStack.pop();
}

void History::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}
