//
//  LiveInputManager.h
//  PlatformGame
//
//  Created by fran on 25/03/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__LiveInputManager__
#define __PlatformGame__LiveInputManager__

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class LiveInputManager {
public:
    LiveInputManager();
    ~LiveInputManager();

    bool keyDown(sf::Keyboard::Key key);
    bool keyDown(std::vector<sf::Keyboard::Key> keys);
    
};

#endif /* defined(__PlatformGame__LiveInputManager__) */
