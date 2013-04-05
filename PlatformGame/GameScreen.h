//
//  GameScreen.h
//  PlatformGame
//
//  Created by fran on 07/03/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__GameScreen__
#define __PlatformGame__GameScreen__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "InputManager.h"

class GameScreen {
public:
    GameScreen();
    ~GameScreen();
    
    virtual void loadContent();
    virtual void unloadContent();
    virtual void inputUpdate(sf::Event event, sf::Time elapsedTime);
    virtual void liveInputUpdate(sf::Time elapsedTime);
    virtual void update(sf::Time elapsedTime);
    virtual void draw(sf::RenderWindow &window);
protected:
    InputManager input;
    std::vector<sf::Keyboard::Key> keys;

};

#endif /* defined(__PlatformGame__GameScreen__) */
