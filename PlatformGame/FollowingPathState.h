//
//  FollowingPathState.h
//  PlatformGame
//
//  Created by fran on 08/07/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__FollowingPathState__
#define __PlatformGame__FollowingPathState__

#include <iostream>
#include "State.h"
#include "Enemy.h"
#include "Vector.h"
class FollowingPathState:public State<Enemy> {
public:
    FollowingPathState(real leftPos, real rightPos);
    ~FollowingPathState();
    void enter(Enemy *e);
    void execute(Enemy *e);
    void exit(Enemy *e);
    
private:
    real left, right;
    Vector *direction;
    
};

#endif /* defined(__PlatformGame__FollowingPathState__) */
