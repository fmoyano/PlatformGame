//
//  FollowingPathState.cpp
//  PlatformGame
//
//  Created by fran on 08/07/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "FollowingPathState.h"

FollowingPathState::FollowingPathState(real leftPos, real rightPos) {
    this->left = leftPos;
    this->right = rightPos;
    direction = new Vector(1, 0);
}
void FollowingPathState::enter(Enemy *e) {
    std::cout << "Just entered Path State" << std::endl;

}

FollowingPathState::~FollowingPathState() {
    delete direction;
}

void FollowingPathState::execute(Enemy *e) {
        
    if (e->getPosition().getX() <= left) {
        direction->setXY(1, 0);
    } else if (e->getPosition().getX() >= right) {
        direction->setXY(-1, 0);
    }
    
    e->setDirection(*direction);
    
}

void FollowingPathState::exit(Enemy *e) {
    std::cout << "Just exited Path State" << std::endl;

}