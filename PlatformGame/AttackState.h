//
//  AttackState.h
//  PlatformGame
//
//  Created by fran on 10/07/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__AttackState__
#define __PlatformGame__AttackState__

#include <iostream>
#include "State.h"
#include "Enemy.h"
#include "Vector.h"
class AttackState:public State<Enemy> {
public:
    AttackState(real xAcceleration);
    ~AttackState();
    void enter(Enemy *e);
    void execute(Enemy *e);
    void exit(Enemy *e);
        
};


#endif /* defined(__PlatformGame__AttackState__) */
