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
#include "Platform.h"
#include "MovablePlatform.h"
#include "Stair.h"
#include "Background.h"
#include "Enemy.h"
#include "Pickable.h"
#include "Rope.h"
class Level1Screen : public GameScreen {
public:
    Level1Screen();
    ~Level1Screen();
    
    void loadContent();
    void unloadContent();
    void inputUpdate(const sf::Event &event, sf::Time elapsedTime);
    void update(sf::Time elapsedTime);
    void draw(sf::RenderWindow &window);
    
private:
    Player *player;
    Enemy *enemy;
    Pickable *pickable;
    Stair *stair;
    Rope *rope;
    
    
    Platform *floor;
    Platform *platform;
    Platform *platform2;
    Platform *platform3;
    MovablePlatform *movPlat1, *movPlat2, *movPlat3;
    Platform *platformSet[200];
    Background *background;
    
    sf::View view;
};

#endif /* defined(__PlatformGame__Level1Screen__) */
