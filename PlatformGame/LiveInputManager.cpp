//
//  LiveInputManager.cpp
//  PlatformGame
//
//  Created by fran on 25/03/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "LiveInputManager.h"

LiveInputManager::LiveInputManager() {}
LiveInputManager::~LiveInputManager(){}

bool LiveInputManager::keyDown(sf::Keyboard::Key key) {
    if(sf::Keyboard::isKeyPressed(key)) {
        return true;
    }
    return false;
}

bool LiveInputManager::keyDown(std::vector<sf::Keyboard::Key> keys) {
    for (int i = 0; i < keys.size(); i++) {
        if(keyDown(keys[i])) {
            return true;
        }
    }
    return false;
}

