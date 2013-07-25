//
//  DragForce.h
//  PlatformGame
//
//  Created by fran on 24/07/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__DragForce__
#define __PlatformGame__DragForce__

#include <iostream>
#include "ForceGenerator.h"

class DragForce : public ForceGenerator {
    
public:
    DragForce(real k1, real k2);
    virtual void update(Entity *e, sf::Time elapsedTime);
    
private:
    real k1, k2;
};

#endif /* defined(__PlatformGame__DragForce__) */
