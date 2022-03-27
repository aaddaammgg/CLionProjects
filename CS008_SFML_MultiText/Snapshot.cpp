//
// Created by Adam G. on 3/26/2022.
//
#ifndef CS008_SFML_TYPING_SNAPSHOT_CPP
#define CS008_SFML_TYPING_SNAPSHOT_CPP

#include "Snapshot.h"

Snapshot::Snapshot() {

}

std::string Snapshot::getData() {
    return data;
}

void Snapshot::setData(std::string str) {
    this->data = str;
}

#endif //CS008_SFML_TYPING_SNAPSHOT_CPP