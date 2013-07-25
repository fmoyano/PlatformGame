//
//  InputManager.cpp
//  PlatformGame
//
//  Created by fran on 12/03/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "InputManager.h"

InputManager::InputManager() {}
InputManager::~InputManager() {}

void InputManager::update(const sf::Event &event) {
    this->event = event;
}

bool InputManager::keyPressed(const sf::Keyboard::Key &key) const {
    if ((event.key.code == key) && (event.type == sf::Event::KeyPressed)) {
        return true;
    }
    return false;
}

bool InputManager::keyPressed(const std::vector<sf::Keyboard::Key> &keys) const {
    for (int i = 0; i < keys.size(); i++) {
        if(keyPressed(keys[i])) {
            return true;
        }
    }
    return false;
}

bool InputManager::keyReleased(const sf::Keyboard::Key &key) const {
    if ((event.key.code == key) && (event.type == sf::Event::KeyReleased)) {
        return true;
    }
    return false;
}

bool InputManager::keyReleased(const std::vector<sf::Keyboard::Key> &keys) const {
    for (int i = 0; i < keys.size(); i++) {
        if(keyReleased(keys[i])) {
            return true;
        }
    }
    return false;
}