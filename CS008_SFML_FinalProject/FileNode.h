//
// Created by Adam G. on 4/21/2022.
//

#ifndef CS008_SFML_FINALPROJECT_FILENODE_H
#define CS008_SFML_FINALPROJECT_FILENODE_H

#include <SFML/Graphics.hpp>
#include "GUIComponent.h"
#include "FileItem.h"

class FileNode : public GUIComponent {
private:
    FileItem data;

    std::vector<FileNode*> children;

    void toggleChildren();

    void reposition();
};


#endif //CS008_SFML_FINALPROJECT_FILENODE_H
