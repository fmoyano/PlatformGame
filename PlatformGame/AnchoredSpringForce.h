//
//  AnchoredSpring.h
//  PlatformGame
//
//  Created by fran on 24/07/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__AnchoredSpringForce__
#define __PlatformGame__AnchoredSpringForce__

#include <iostream>
#include "ForceGenerator.h"
class AnchoredSpringForce : public ForceGenerator {
    
public:
    AnchoredSpringForce(Vector *anchor, real springConstant, real restLength);
    ~AnchoredSpringForce();
    virtual void updateForce(Entity *e, sf::Time elapsedTime);
    
    Vector *getAnchor() const;
    void setAnchor(Vector *v);
    
private:
    Vector *anchor;
    real springConstant;
    real restLength;
    
};


#endif /* defined(__PlatformGame__AnchoredSpring__) */
