//
//  Buoyancy.cpp
//  PlatformGame
//
//  Created by fran on 25/07/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "BuoyancyForce.h"


BuoyancyForce::BuoyancyForce(real maxDepth, real volume, real waterHeight, real liquidDensity) : maxDepth(maxDepth), volume(volume), waterHeight(waterHeight), liquidDensity(liquidDensity)
{}

void BuoyancyForce :: updateForce(Entity *e, sf::Time elapsedTime) {
    
    //Calculate the submersion depth
    real depth = e -> getPosition().getY();
    
    //Check if we're out of the water
    if (depth >= waterHeight + maxDepth) {
        return;
    }
    
    Vector force(0, 0);
    
    //Check if we're at maximum depth
    if (depth <= waterHeight - maxDepth) {
        force.setY(liquidDensity * volume);
        e -> addForce(force);
        return;
    }
    
    //Otherwise we're partially submerged
    force.setY(liquidDensity * volume * (depth - maxDepth - waterHeight) / 2 * maxDepth);
    e -> addForce(force);
}



