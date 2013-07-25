//
//  SpringForce.h
//  PlatformGame
//
//  Created by fran on 24/07/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__SpringForce__
#define __PlatformGame__SpringForce__

#include <iostream>
#include "ForceGenerator.h"
class SpringForce : public ForceGenerator {
    
public:
    SpringForce(Entity *other, real springConstant, real restLength);
    ~SpringForce();
    virtual void updateForce(Entity *e, sf::Time elapsedTime);
    
private:
    Entity *other;
    real springConstant;
    real restLength;
    
};
#endif /* defined(__PlatformGame__SpringForce__) */
