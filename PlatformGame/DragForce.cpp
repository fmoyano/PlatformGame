//
//  DragForce.cpp
//  PlatformGame
//
//  Created by fran on 24/07/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "DragForce.h"

DragForce::DragForce(real k1, real k2) : k1(k1), k2(k2){
}

void DragForce::update(Entity *e, sf::Time elapsedTime) {
    
    Vector force = e -> getVelocity();
    real dragCoeff = force.length();
    
    //Total drag cofficent
    dragCoeff = k1 * dragCoeff + k2 * dragCoeff * dragCoeff;

    //Calculate and apply the final force
    force.normalize();
    force *= -dragCoeff;
    e -> addForce(force);
}