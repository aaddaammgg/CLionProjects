//
// Created by Adam G. on 3/21/22.
//

#include "TextInput.h"

TextInput::TextInput() {
    box.setSize(getSize());
    box.setOutlineColor(sf::Color::Red);
    box.setOutlineThickness(5);

    cursorBlink.setPosition(1, 1);
    label.setPosition(1, -2);
    typing.setPosition(0, -2);
}

void TextInput::setSize(sf::Vector2f size) {
    GUIComponent::setSize(size);
    box.setSize(size);
    cursorBlink.setSize({2, size.y - 2});
    typing.getMultiText().setCharacterSize(static_cast<unsigned int>(size.y));
}

void TextInput::updatePos() {
    sf::FloatRect labelGB = label.getGlobalBounds();

    float padding = 10;

    cursorBlink.setPosition(1 + labelGB.width + labelGB.left + padding, 1);
    typing.setPosition(0 + labelGB.width + labelGB.left + padding, -2);
    box.setPosition(labelGB.width + labelGB.left + padding, 0);
}

void TextInput::setLabel(const std::string &str) {
    label.setLabel(str);
    updatePos();
}

void TextInput::setLabelSize(const int &size) {
    label.setLabelSize(size);
    updatePos();
}

Snapshot TextInput::getSnapshot() {
    Snapshot s;
    s.setData(typing.getMultiText());
    return s;
}

void TextInput::applySnapshot(const Snapshot &snapshot) {
    typing.getMultiText() = snapshot.getData();
}

void TextInput::onMouseReleased(sf::Mouse::Button button, sf::Vector2f pos) {
    if (button != sf::Mouse::Left) return;

    sf::FloatRect boxPos = getTransform().transformRect(box.getGlobalBounds());

    if (boxPos.contains(pos)) {
        box.setOutlineColor(sf::Color::Green);
        enableState(SELECTED);
        cursorBlink.enableState(SELECTED);
    } else {
        box.setOutlineColor(sf::Color::Red);
        disableState(SELECTED);
        cursorBlink.disableState(SELECTED);
    }
}

void TextInput::onKeyPressed(const sf::Event::KeyEvent &key) {
    if (!isEnabled(SELECTED)) return;

    if (KBShortcuts::isUndo()) {
        std::cout << "Control + Z" << std::endl;

        if (getUndoSize() == 0) {
            return;
        }

        if (getUndoTop().snapshot.getData().getString() == typing.getMultiText().getString()) {
            undoPop();
        }

        applySnapshot(getUndoTop().snapshot);
        undoPop();
    }

    if (KBShortcuts::isRedo()) {
        std::cout << "Control + Y" << std::endl;

        if (getRedoSize() == 0) {
            return;
        }

        if (getRedoTop().snapshot.getData().getString() == typing.getMultiText().getString()) {
            redoPop();
        }

        applySnapshot(getRedoTop().snapshot);
        redoPop();
    }
}

void TextInput::updateCursor() {
    sf::FloatRect labelGB = label.getGlobalBounds();

    float padding = (label.getLabelString().empty()) ? 0 : 10;

    cursorBlink.setPosition(1 + labelGB.width + labelGB.left + padding, 1);
}

void TextInput::onTextEntered(sf::Uint32 unicode) {
    if (!isEnabled(SELECTED)) return;

    if (typing.getMultiText().isEmpty()) {
        updateCursor();
    } else {
        sf::FloatRect labelGB = label.getGlobalBounds();
        float padding = (label.getLabelString().empty()) ? 0 : 10;

        sf::Vector2f curPos = typing.getMultiText().back().getPosition();
        sf::FloatRect backBounds = typing.getMultiText().back().getLocalBounds();

        curPos += {1, 1};
        curPos += {backBounds.width + backBounds.left + 1, 0};
        curPos += {labelGB.width + labelGB.left + padding, 0};

        cursorBlink.setPosition(curPos);
    }
}

void TextInput::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (isEnabled(SELECTED)) {
        if (!getInit()) {
            HistoryNode hn;
            hn.snapshot = getSnapshot();
            hn.component = this;
            undoPush(hn);
            setInit(true);
        }

        typing.addEventHandler(window, event);

        if (event.type == sf::Event::TextEntered && !KBShortcuts::isControl()) {
            HistoryNode hn;
            hn.snapshot = getSnapshot();
            hn.component = this;
            undoPush(hn);
        }
    }

    // Moved after typing's event handler due to typing class needing the highest priority
    GUIComponent::addEventHandler(window, event);
}

void TextInput::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform = getTransform();
    window.draw(box, states);
    window.draw(typing, states);
    window.draw(cursorBlink, states);
    window.draw(label, states);
}

void TextInput::update() {
    typing.update();
    cursorBlink.update();
}
