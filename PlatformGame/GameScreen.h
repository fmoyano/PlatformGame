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
#include "CollisionDetector.h"
#include "ScreenLayer.h"

const int MAX_LAYERS = 3;
class GameScreen {
public:
    GameScreen();
    ~GameScreen();
    
    virtual void loadContent();
    virtual void unloadContent();
    virtual void inputUpdate(const sf::Event &event, sf::Time elapsedTime);
    virtual void update(sf::Time elapsedTime);
    virtual void draw(sf::RenderWindow &window);
    
    void addLayer(ScreenLayer *layer);
    int getNumLayers() const;
  
    
protected:
    InputManager input;
    std::vector<sf::Keyboard::Key> keys;
    CollisionDetector *cd;
    //sf::View view;
    //std::vector<Entity *> gameObjects;
    ScreenLayer *layers[MAX_LAYERS];
    int numLayers;
};

#endif /* defined(__PlatformGame__GameScreen__) */
