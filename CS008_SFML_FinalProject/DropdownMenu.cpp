//
// Created by Adam G. on 4/3/2022.
//

#include "DropdownMenu.h"

DropdownMenu::DropdownMenu() {
    itemList.enableState(HIDDEN);
    disableState(OPEN);
}

Snapshot DropdownMenu::getSnapshot() {
    Snapshot s;
    s.setData(inputBox.getMultiText());
    
    return s;
}

void DropdownMenu::applySnapshot(const Snapshot &snapshot) {
    inputBox.getMultiText() = snapshot.getData();
}

void DropdownMenu::setSize(sf::Vector2f size) {
    GUIComponent::setSize(size);
    inputBox.setSize(size);
    
    for (auto& item : itemList.getItemList()) {
        item.setSize(size);
    }
    
    itemList.setPosition(0, size.y + 1);
}

void DropdownMenu::addItem(std::string str) {
    Item item;
    item.setString(str);
    item.setSize(getSize());

    if (itemList.isEmpty()) {
        inputBox.setSelectedItem(item);
    }

    itemList.addItem(item);
}

void DropdownMenu::onKeyPressed(const sf::Event::KeyEvent &key) {
    if (!isEnabled(SELECTED)) return;

    if (KBShortcuts::isUndo()) {
        std::cout << "Control + Z" << std::endl;

        if (getUndoSize() == 0 || inputBox.getMultiText().getCharCount() == 0) {
            return;
        }

        if (getUndoTop().snapshot.getData().getString() == inputBox.getMultiText().getString()) {
            undoPop();
        }

        if (getUndoSize() != 0) {
            applySnapshot(getUndoTop().snapshot);
            undoPop();
        }
    }

    if (KBShortcuts::isRedo()) {
        std::cout << "Control + Y" << std::endl;

        if (getRedoSize() == 0) {
            return;
        }

        if (getRedoTop().snapshot.getData().getString() == inputBox.getMultiText().getString()) {
            redoPop();
        }

        if (getRedoSize() != 0) {
            applySnapshot(getRedoTop().snapshot);
            redoPop();
        }
    }
}

void DropdownMenu::onMouseMoved(sf::Vector2f pos) {
    for (auto& item : itemList.getItemList()) {
        sf::FloatRect itemBounds = item.getBox().getGlobalBounds();
        sf::Vector2f itemPos = item.getPosition();

        itemBounds.top = itemPos.y;
        itemBounds.top += item.getSize().y;

        itemBounds.height -= (item.getBox().getOutlineThickness() * 2);

        sf::FloatRect itemPosTransform = getTransform().transformRect(itemBounds);

        if (itemPosTransform.contains(pos)) {
            item.getBox().setFillColor(sf::Color::Red);
        } else {
            item.getBox().setFillColor(sf::Color::White);
        }
    }
}

void DropdownMenu::onMouseReleased(sf::Mouse::Button button, sf::Vector2f pos) {
    if (button != sf::Mouse::Left) return;

    sf::FloatRect boxPos = getTransform().transformRect(inputBox.getGlobalBounds());

    if (boxPos.contains(pos)) {
        enableState(SELECTED);
        if (isEnabled(OPEN)) {
            disableState(OPEN);
            itemList.enableState(HIDDEN);
        } else {
            enableState(OPEN);
            itemList.disableState(HIDDEN);
        }
    } else {
        disableState(SELECTED);
        if (isEnabled(OPEN)) {
            for (auto& item : itemList.getItemList()) {
                sf::FloatRect itemBounds = item.getBox().getGlobalBounds();
                sf::Vector2f itemPos = item.getPosition();

                itemBounds.top += itemPos.y;
                itemBounds.top += item.getSize().y;

                sf::FloatRect itemPosTransform = getTransform().transformRect(itemBounds);

                if (itemPosTransform.contains(pos)) {
                    if (!getInit()) {
                        HistoryNode hn;
                        hn.snapshot = getSnapshot();
                        hn.component = this;
                        undoPush(hn);
                        setInit(true);
                    }

                    inputBox.setSelectedItem(item);

                    HistoryNode hn;
                    hn.snapshot = getSnapshot();
                    hn.component = this;
                    undoPush(hn);

                    enableState(SELECTED);
                    std::cout << item.getString() << std::endl;
                }
            }
        }

        disableState(OPEN);
        itemList.enableState(HIDDEN);
    }
}

void DropdownMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform *= getTransform();
    window.draw(itemList, states);
    window.draw(inputBox, states);
}

void DropdownMenu::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    GUIComponent::addEventHandler(window, event);
}

void DropdownMenu::update() {
    GUIComponentAdapter::update();
    itemList.update();
    inputBox.update();
}
