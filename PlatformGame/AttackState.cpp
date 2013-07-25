//
//  AttackState.cpp
//  PlatformGame
//
//  Created by fran on 10/07/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "AttackState.h"

AttackState::AttackState(real xAcceleration) {

}

AttackState::~AttackState() {}

void AttackState::enter(Enemy *e) {
    std::cout << "Just entered in Attack State" << std::endl;
    
}

void AttackState::execute(Enemy *e) {

    //e->setVelocity(e->getVelocity().getX(), -500);
}

void AttackState::exit(Enemy *e) {
    std::cout << "Just exited Attack State" << std::endl;
}