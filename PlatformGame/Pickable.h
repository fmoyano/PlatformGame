//
//  Pickable.h
//  PlatformGame
//
//  Created by fran on 10/07/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__Pickable__
#define __PlatformGame__Pickable__

#include <iostream>
#include "Entity.h"
#include "StateMachine.h"
#include <SFML/Graphics.hpp>

class Pickable : public Entity {
    
public:
    Pickable();
    Pickable(real px, real py, real sx, real sy);
    Pickable(const Vector &pos, const Vector &size);
    ~Pickable();
    
    void initialize();
    void draw(sf::RenderWindow &window);
    
    void update(sf::Time elapsedTime);
    void onCollision(Entity &e); //Don't want to miss the chance with 'const' of modifying e
    
private:
    //Vector position, velocity, acceleration from Entity;
    sf::RectangleShape pickable;
};



#endif /* defined(__PlatformGame__Pickable__) */
