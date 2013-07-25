//
//  ForceGenerator.h
//  PlatformGame
//
//  Created by fran on 23/07/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__ForceGenerator__
#define __PlatformGame__ForceGenerator__

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <iostream>

class ForceGenerator {
public:
    virtual void updateForce(Entity *e, sf::Time elapsedTime) = 0;
    
    //Important that all base classes to have virtual destructors
    //Otherwise, memory leaks are possible
    
    //EXAMPLE:
    //Base *p = new Derived();
    //delete p
    
    //If we don't define a virtual destructor for Base, the compiler will call
    //the default constructor for Base, and any memory allocated by Derived
    //will be lost because the destructor of Derived will never be called
    //If you define the virtual destructor for Base, the compiler knows that
    //he must follow the hierarchy and call Derived destructor
    virtual ~ForceGenerator();
};

#endif /* defined(__PlatformGame__ForceGenerator__) */
