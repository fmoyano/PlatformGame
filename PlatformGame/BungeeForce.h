//
//  BungeeForce.h
//  PlatformGame
//
//  Created by fran on 24/07/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__BungeeForce__
#define __PlatformGame__BungeeForce__

#include <iostream>
#include "ForceGenerator.h"
class BungeeForce : public ForceGenerator {
    

public:
    BungeeForce(Entity *other, real springConstant, real restLength);
    ~BungeeForce();
    virtual void updateForce(Entity *e, sf::Time elapsedTime);

private:
    Entity *other;
    real springConstant, restLength;
};
#endif /* defined(__PlatformGame__BungeeForce__) */
