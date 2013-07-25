//
//  BungeeForce.cpp
//  PlatformGame
//
//  Created by fran on 24/07/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "BungeeForce.h"

BungeeForce::BungeeForce(Entity *other, real springConstant, real restLength):
                other(other), springConstant(springConstant), restLength(restLength)
{}

BungeeForce::~BungeeForce() {
    if (other) {
        delete other;
    }
}

void BungeeForce::updateForce(Entity *e, sf::Time elapsedTime) {
    
    Vector force = e -> getPosition();
    force -= other -> getPosition();
    
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