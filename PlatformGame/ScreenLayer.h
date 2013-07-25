//
//  ScreenLayer.h
//  PlatformGame
//
//  Created by fran on 11/05/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__ScreenLayer__
#define __PlatformGame__ScreenLayer__

#include <iostream>
#include "core.h"
#include "Entity.h"
#include "Player.h"
#include <vector>
class ScreenLayer {
public:
    ScreenLayer(real factor);
    ~ScreenLayer();
    
    //void loadContent();
    //void unloadContent();
    //void inputUpdate(const sf::Event &event, sf::Time elapsedTime);
    void update(const Player &p, sf::Time elapsedTime);
    void update(real posX, real posY, real velX, real velY, sf::Time elapsedTime);
    
    void draw(sf::RenderWindow &window);
    void addObject(Entity *e);
    
    void setView(int iniX, int iniY, int lengthX, int lenghtY);
    void setViewPort(real x, real y, real factorX, real factorY);
    void setCenter(real cx, real cy);
    
    const sf::View & getView() const;
    real getFactor() const;
    
private:
    std::vector<Entity *> gameObjects;
    sf::View view;
    real factor;
};


#endif /* defined(__PlatformGame__ScreenLayer__) */
