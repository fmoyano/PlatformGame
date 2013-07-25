//
//  AnchoredBungeeForce.cpp
//  PlatformGame
//
//  Created by fran on 24/07/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "AnchoredBungeeForce.h"

AnchoredBungeeForce::AnchoredBungeeForce(Vector *anchor, real springConstant, real restLength):
                anchor(anchor), springConstant(springConstant), restLength(restLength)
{}

AnchoredBungeeForce::~AnchoredBungeeForce() {
    if (anchor) {
        delete anchor;
    }
}

void AnchoredBungeeForce::updateForce(Entity *e, sf::Time elapsedTime) {
    
    Vector force = e -> getPosition();
    force -= *anchor;
    
    //Magnitude of the force
    real magnitude = force.length();
    //Bungee spring only affects if separation is bigger than restLength
    if (magnitude <= restLength) {
        return;
    }
    
    magnitude = springConstant * (restLength - magnitude);
    
    //Calculate force and apply
    force.normalize();
    force *= -magnitude;
    e -> addForce(force);
}