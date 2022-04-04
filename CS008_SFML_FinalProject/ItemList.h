//
// Created by Adam G. on 4/3/2022.
//

#ifndef CS008_SFML_FINALPROJECT_ITEMLIST_H
#define CS008_SFML_FINALPROJECT_ITEMLIST_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "GUIComponentAdapter.h"
#include "Item.h"

class ItemList : public GUIComponentAdapter {
private:
    std::vector<Item> itemList;
public:
    ItemList();

    void addItem(Item& item);

    std::vector<Item>& getItemList();

    bool isEmpty();

    virtual Snapshot getSnapshot() {};
    virtual void applySnapshot(const Snapshot& snapshot) {};

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
};


#endif //CS008_SFML_FINALPROJECT_ITEMLIST_H
