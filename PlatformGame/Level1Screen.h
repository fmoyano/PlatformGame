//
//  Level1Screen.h
//  PlatformGame
//
//  Created by fran on 02/04/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__Level1Screen__
#define __PlatformGame__Level1Screen__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameScreen.h"
#include "Player.h"
#include "Floor.h"

class Level1Screen : public GameScreen {
public:
    Level1Screen();
    ~Level1Screen();
    
    void loadContent();
    void unloadContent();
    void inputUpdate(sf::Event event, sf::Time elapsedTime);
    void liveInputUpdate(sf::Time elapsedTime);
    void update(sf::Time elapsedTime);
    void draw(sf::RenderWindow &window);
    
private:
    Player *player;
    Floor *floor;
};

#endif /* defined(__PlatformGame__Level1Screen__) */
