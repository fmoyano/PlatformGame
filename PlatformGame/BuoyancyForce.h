//
//  Buoyancy.h
//  PlatformGame
//
//  Created by fran on 25/07/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__BuoyancyForce__
#define __PlatformGame__BuoyancyForce__

#include <iostream>
#include "ForceGenerator.h"

class BuoyancyForce : public ForceGenerator {
   
public:
    BuoyancyForce(real maxDepth, real volume, real waterHeight, real liquidDensity);
    virtual void updateForce(Entity *e, sf::Time elapsedTime);
    
    
private:
    
    real maxDepth, volume, waterHeight, liquidDensity;
};
#endif /* defined(__PlatformGame__Buoyancy__) */
