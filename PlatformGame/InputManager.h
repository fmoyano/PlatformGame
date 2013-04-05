//
//  InputManager.h
//  PlatformGame
//
//  Created by fran on 12/03/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__InputManager__
#define __PlatformGame__InputManager__

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class InputManager {
public:
    InputManager();
    ~InputManager();
    
    void update(sf::Event event);
    bool keyPressed(sf::Keyboard::Key key);
    bool keyPressed(std::vector<sf::Keyboard::Key> keys);
    bool keyReleased(sf::Keyboard::Key key);
    bool keyReleased(std::vector<sf::Keyboard::Key> keys);
   
private:
    sf::Event event;
    
};
#endif /* defined(__PlatformGame__InputManager__) */
