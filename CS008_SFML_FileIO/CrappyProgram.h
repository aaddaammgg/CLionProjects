//
// Created by Adam G. on 4/25/22.
//

#ifndef CS008_FILEIO_CRAPPYPROGRAM_H
#define CS008_FILEIO_CRAPPYPROGRAM_H

#include "LoadableText.h"
#include "RandomColorSquare.h"
#include "ResizeableCircle.h"

#include <fstream>

class CrappyProgram {
private:
    LoadableText text;
    ResizeableCircle circle;
    RandomColorSquare square;
public:
    CrappyProgram();
    void run();
    void save();
    void load();
};


#endif //CS008_FILEIO_CRAPPYPROGRAM_H
