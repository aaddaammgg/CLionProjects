//
// Created by Adam G. on 3/26/2022.
//

#ifndef CS008_SFML_TYPING_SNAPSHOT_H
#define CS008_SFML_TYPING_SNAPSHOT_H

#include <string>

class Snapshot {
private:
    std::string data;
public:
    Snapshot();

    std::string getData();
    void setData(std::string str);
};

#endif //CS008_SFML_TYPING_SNAPSHOT_H
