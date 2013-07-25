//
//  AnchoredBungeeForce.h
//  PlatformGame
//
//  Created by fran on 24/07/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__AnchoredBungeeForce__
#define __PlatformGame__AnchoredBungeeForce__

#include <iostream>
#include "ForceGenerator.h"
class AnchoredBungeeForce : public ForceGenerator {
    
public:
    AnchoredBungeeForce(Vector *anchor, real springConstant, real restLength);
    ~AnchoredBungeeForce();
    virtual void updateForce(Entity *e, sf::Time elapsedTime);
    
private:
    Vector *anchor;
    real springConstant, restLength;
};

#endif /* defined(__PlatformGame__AnchoredBungeeForce__) */
