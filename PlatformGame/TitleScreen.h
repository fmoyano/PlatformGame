//
//  TitleScreen.h
//  PlatformGame
//
//  Created by fran on 11/03/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__TitleScreen__
#define __PlatformGame__TitleScreen__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameScreen.h"
#include "ResourcePath.hpp"
#include "ScreenManager.h"

class TitleScreen : public GameScreen {
public:
    TitleScreen();
    ~TitleScreen();
    
    void loadContent();
    void unloadContent();
    void inputUpdate(const sf::Event &event, sf::Time elapsedTime);
    void update(sf::Time elapsedTime);
    void draw(sf::RenderWindow &window);
    
private:
    sf::Font font;
    sf::Text text;
};

#endif
