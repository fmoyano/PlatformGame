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
#include "InputManager.h"
#include "core.h"

#define Player_Velocity_X 300
#define Jump_Acceleration 500

class Player {
  
public:
    Player();
    ~Player();
    
    void initialize();
    void draw(sf::RenderWindow &window);
    
    //Update all the parameters
    void update(InputManager &input, sf::Time elapsedTime);
    void liveUpdate(sf::Time elapsedTime);
    void integrate(sf::Time elapsedTime);
    
    Vector getPosition();
    Vector getVelocity();
    Vector getAcceleration();
    
    void setPosition(Vector &position);
    void setVelocity(Vector &velocity);
    void setAcceleration(Vector &acceleration);
    
    
private:
    Vector position, velocity, acceleration;
    sf::RectangleShape rectangle;
    
    
};

#endif /* defined(__PlatformGame__Player__) */
