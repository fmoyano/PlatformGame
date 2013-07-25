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
    //Constructor and destructor
    Vector();
    Vector(real x, real y);
    ~Vector();
    
    //Getters and setters
    const real getX() const;
    const real getY() const;
    void setX(real x);
    void setY(real y);
    void setXY(real x,real y);
    
    //Operators overloading
    Vector& operator+=(const Vector &v);
    Vector& operator-=(const Vector &v);
    Vector& operator*=(real s);
    real operator*=(const Vector &v);    
    
    //Other methods
    real length() const;
    void normalize();
    Vector byScalar(real x) const;
    void addVector(const Vector &v);
    void addVector(real x, real y);
    real scalarProduct(const Vector &v) const;
    void addScaledVector(const Vector &v, real x);
    real angleWithVector(const Vector &v) const;
    real angleWithVectorDegress(const Vector &v) const;
    
    
private:
    real x, y;
};

inline Vector operator+(Vector v, const Vector& vaux) {
    v += vaux;
    return v;
}

inline Vector operator-(Vector v, const Vector& vaux) {
    v -= vaux;
    return v;
}

inline Vector operator*(Vector v, real s) {
    v *= s;
    return v;
}

inline real operator*(const Vector& v1, const Vector& v2) {
    return v1.getX() * v2.getX() +
            v1.getY() * v2.getY();
}

#endif /* defined(__PlatformGame__Vector__) */
