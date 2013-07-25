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
    
    void update(const sf::Event &event);
    bool keyPressed(const sf::Keyboard::Key &key) const;
    bool keyPressed(const std::vector<sf::Keyboard::Key> &keys) const;
    bool keyReleased(const sf::Keyboard::Key &key) const;
    bool keyReleased(const std::vector<sf::Keyboard::Key> &keys) const;
   
private:
    sf::Event event;
    
};
#endif /* defined(__PlatformGame__InputManager__) */
