//
//  SplashScreen.h
//  PlatformGame
//
//  Created by fran on 07/03/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__SplashScreen__
#define __PlatformGame__SplashScreen__

#include <iostream>
#include "GameScreen.h"
#include "ResourcePath.hpp"
#include "ScreenManager.h"

class SplashScreen : public GameScreen {
public:
    SplashScreen();
    ~SplashScreen();
    void loadContent();
    void unloadContent();
    void inputUpdate(const sf::Event &event, sf::Time elapsedTime);
    void update(sf::Time elapsedTime);
    void draw(sf::RenderWindow &window);
private:
    sf::Text text;
    sf::Font font;
};

#endif /* defined(__PlatformGame__SplashScreen__) */
