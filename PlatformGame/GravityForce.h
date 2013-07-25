//
//  GravityForce.h
//  PlatformGame
//
//  Created by fran on 24/07/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__GravityForce__
#define __PlatformGame__GravityForce__

#include "ForceGenerator.h"
#include <iostream>

class GravityForce: public ForceGenerator {
    
public:
    GravityForce(const Vector &gravity);
    virtual void updateForce(Entity *e, sf::Time elapsedTime);
    
private:
    Vector gravity;
};
#endif /* defined(__PlatformGame__GravityForce__) */
