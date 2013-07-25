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

const real Vector::getX() const {
    return x;
}

const real Vector::getY() const {
    return y;
}

void Vector::setX(real x) {
    this->x = x;
}

void Vector::setY(real y) {
    this->y = y;
}

void Vector::setXY(real x, real y) {
    this-> x = x;
    this-> y = y;
}

real Vector::length() const {
    
    return sqrt(this->x * this->x + this->y * this->y);
}

void Vector::normalize() {
    real l = this->length();
    this->x /= l;
    this->y /= l;
}

Vector Vector::byScalar(real v) const {
    return Vector(x*v, y*v);
    
}

void Vector::addVector(const Vector &v) {
    x += v.getX();
    y += v.getY();
}

void Vector::addVector(real x, real y) {
    this -> x += x;
    this -> y += y;
}

void Vector::addScaledVector(const Vector &v, real z) {
    x += v.getX() * z;
    y += v.getY() * z;
}

real Vector::scalarProduct(const Vector &v) const {
    return (x*v.getX() + y*v.getY());
}

real Vector::angleWithVector(const Vector &v) const {
    return acos(this->scalarProduct(v) / (this->length() * v.length()));
}

real Vector::angleWithVectorDegress(const Vector &v) const {
    return angleWithVector(v)*180/PI;
}

//----------------------------------------------------
// OPERATORS OVERLOADING
//----------------------------------------------------
Vector& Vector::operator+=(const Vector &v) {
    this->x += v.getX();
    this->y += v.getY();
    return *this;
}

Vector& Vector::operator-=(const Vector &v) {
    this -> x -= v.getX();
    this -> y -= v.getY();
    return *this;
}


Vector& Vector::operator*=(real s) {
    this->x *= s;
    this->y *= s;
    return *this;
}

real Vector::operator*=(const Vector &v) {
    return this->x * v.getX() +
        this->y * v.getY();
}


