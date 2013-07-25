//
//  AnchoredSpring.cpp
//  PlatformGame
//
//  Created by fran on 24/07/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "AnchoredSpringForce.h"

AnchoredSpringForce::AnchoredSpringForce(Vector *anchor, real springConstant, real restLength):
                    anchor(anchor), springConstant(springConstant), restLength(restLength)
{}

AnchoredSpringForce::~AnchoredSpringForce() {
    if (anchor) {
        delete anchor;
    }
}

void AnchoredSpringForce::updateForce(Entity *e, sf::Time elapsedTime) {
    Vector force = e -> getPosition();
    force -= *anchor;
    
    //Magnitude of the force
    real magnitude = force.length();
    magnitude = abs(magnitude - restLength);
    magnitude *= springConstant;
    
    //Calculate force and apply
    force.normalize();
    force *= -magnitude;
    e -> addForce(force);
}

Vector * AnchoredSpringForce::getAnchor() const {
    return anchor;
}
void AnchoredSpringForce::setAnchor(Vector *v) {
    anchor = v;
}