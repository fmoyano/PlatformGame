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

void InputManager::update(sf::Event event) {
    this->event = event;
}

bool InputManager::keyPressed(sf::Keyboard::Key key) {
    if ((event.key.code == key) && (event.type == sf::Event::KeyPressed)) {
        return true;
    }
    return false;
}

bool InputManager::keyPressed(std::vector<sf::Keyboard::Key> keys) {
    for (int i = 0; i < keys.size(); i++) {
        if(keyPressed(keys[i])) {
            return true;
        }
    }
    return false;
}

bool InputManager::keyReleased(sf::Keyboard::Key key) {
    if ((event.key.code == key) && (event.type == sf::Event::KeyReleased)) {
        return true;
    }
    return false;
}

bool InputManager::keyReleased(std::vector<sf::Keyboard::Key> keys) {
    for (int i = 0; i < keys.size(); i++) {
        if(keyReleased(keys[i])) {
            return true;
        }
    }
    return false;
}