//
// Created by Adam G. on 3/26/2022.
//

#include "History.h"

std::stack<HistoryNode> History::undoStack;
std::stack<HistoryNode> History::redoStack;

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
    redoStack.push(getUndoTop());
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
    undoStack.push(redoStack.top());
    redoStack.pop();
}

void History::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}
