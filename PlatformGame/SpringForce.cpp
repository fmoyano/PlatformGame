//
//  SpringForce.cpp
//  PlatformGame
//
//  Created by fran on 24/07/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "SpringForce.h"

SpringForce::SpringForce(Entity *other, real springConstant, real restLength):
            other(other), springConstant(springConstant), restLength(restLength)
{}

SpringForce::~SpringForce() {
    if (other) {
        delete other;
    }
}
void SpringForce::updateForce(Entity *e, sf::Time elapsedTime) {

    Vector force = e -> getPosition();
    force -= other -> getPosition();
    
    //Magnitude of the force
    real magnitude = force.length();
    magnitude = abs(magnitude - restLength);
    magnitude *= springConstant;
    
    //Calculate force and apply
    force.normalize();
    force *= -magnitude;
    e -> addForce(force);
}