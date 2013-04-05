//
//  Vector.cpp
//  PlatformGame
//
//  Created by fran on 25/03/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "Vector.h"
#include <math.h>

Vector::Vector() {
    x = 0;
    y = 0;
}

Vector::Vector(real u, real v) {
    x = u;
    y = v;
}

Vector::~Vector() {}

real Vector::getX() {
    return x;
}

real Vector::getY() {
    return y;
}

void Vector::setX(real x) {
    this->x = x;
}

void Vector::setY(real y) {
    this->y = y;
}

real Vector::length() {
    
    return sqrt(this->x * this->x + this->y * this->y);
}

void Vector::normalize() {
    real l = this->length();
    this->x /= l;
    this->y /= l;
}

Vector Vector::byScalar(real v) {
    return Vector(x*v, y*v);
    
}

/*void Vector::operator*(real v) {
    this->byScalar(v);
}*/

Vector Vector::operator*(real v) {
    return Vector(x*v, y*v);
}

Vector Vector::operator+(Vector &v) {
    return Vector(x+v.getX(), y+v.getY());
}

void Vector::addVector(Vector &v) {
    x += v.getX();
    y += v.getY();
}

void Vector::addScaledVector(Vector &v, real z) {
    x += v.getX() * z;
    y += v.getY() * z;
}


real Vector::scalarProduct(Vector &v) {
    return (x*v.getX() + y*v.getY());
}

real Vector::operator*(Vector &v) {
    return scalarProduct(v);
}

real Vector::angleWithVector(Vector &v) {
    return acos(this->scalarProduct(v) / (this->length() * v.length()));
}

real Vector::angleWithVectorDegress(Vector &v) {
    return angleWithVector(v)*180/PI;
}
