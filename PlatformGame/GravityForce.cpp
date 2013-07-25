//
//  GravityForce.cpp
//  PlatformGame
//
//  Created by fran on 24/07/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "GravityForce.h"

GravityForce::GravityForce(const Vector &gravity):gravity(gravity)
{}

void GravityForce::updateForce(Entity *e, sf::Time elapsedTime) {
    
    if (!(e -> hasFiniteMass())) {
        return;
    }
    e->addForce(gravity * e -> getMass());
}