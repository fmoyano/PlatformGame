//
//  Vector.h
//  PlatformGame
//
//  Created by fran on 25/03/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__Vector__
#define __PlatformGame__Vector__

#include <iostream>
#include "core.h"

class Vector {
  
public:
    Vector();
    Vector(real x, real y);
    ~Vector();
    real getX();
    real getY();
    void setX(real x);
    void setY(real y);
    real length();
    void normalize();
    void byScalar(real x);
    void operator*(real x);
    real scalarProduct(Vector &v);
    real operator*(Vector &v);
    real angleWithVector(Vector &v);
    real angleWithVectorDegress(Vector &v);
    
    
private:
    real x;
    real y;
};

#endif /* defined(__PlatformGame__Vector__) */
