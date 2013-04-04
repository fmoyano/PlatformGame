//
//  Player.h
//  PlatformGame
//
//  Created by fran on 02/04/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__Player__
#define __PlatformGame__Player__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vector.h"

class Player {
  
public:
    Player();
    ~Player();
    
    void initialize();
    void draw(sf::RenderWindow &window);
    
    //Update all the parameters
    void update(sf::Event event, sf::Time elapsedTime);
    void liveUpdate(sf::Time elapsedTime);
    
    real getSpeed();
    Vector getPosition();
    
    void setSpeed(float v);
    void setPosition(Vector &position);
    
private:
    Vector position;
    real speed;
    sf::RectangleShape rectangle;
    
    
};

#endif /* defined(__PlatformGame__Player__) */
