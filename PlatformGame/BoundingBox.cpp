//
//  BoundingBox.cpp
//  PlatformGame
//
//  Created by fran on 06/04/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "BoundingBox.h"

BoundingBox::BoundingBox() {
    bottom = 0;
    top = 0;
    left = 0;
    right = 0;
}

//IMPORTANT: we assume that the origin is in the top-left corner
BoundingBox::BoundingBox(real b, real t, real l, real r) {
    bottom = b;
    top = t;
    left = l;
    right = r;
    Vector pos(top, left);
    position = pos;
    size.setXY(right-left, bottom-top);
}

//IMPORTANT: we assume that the origin is in the top-left corner
BoundingBox::BoundingBox(const Vector &pos, const Vector &size) {
    
    real x = pos.getX();
    real y = pos.getY();
    
    bottom = y + size.getY();
    top = y;
    left = x;
    right = x + size.getX();
    position.setXY(x, y);
    (this->size).setXY(size.getX(), size.getY());
    /*if (_DEBUG) {
        std::cout << "INIT: " << std::endl;
        printDebug();
        std::cout << "POSITION: " << position.getX() << " " << position.getY() << std::endl;
        std::cout << "SIZE: " << size.getX() << " " << size.getY() << std::endl;
    }*/
}

BoundingBox::~BoundingBox() {}

real BoundingBox::getBottom() const {
    return bottom;
}

real BoundingBox::getTop() const {
    return top;
}

real BoundingBox::getLeft() const {
    return left;
}

real BoundingBox::getRight() const {
    return right;
}

Vector BoundingBox::getPosition() const {
    return position;
}

Vector BoundingBox::getSize() const {
    return size;
}

void BoundingBox::setPosition(const Vector &pos) {
    position = pos;
}

void BoundingBox::setSize(const Vector &s) {
    size = s;
}

void BoundingBox::update(const Vector &pos) {
    
    real x = pos.getX();
    real y = pos.getY();
    
    bottom = y + size.getY();
    top = y;
    left = x;
    right = x + size.getX();
    
    position.setXY(x, y);
    /*if (_DEBUG) {
        printDebug();
    }*/
}

void BoundingBox::update(real xVar, real yVar) {
    real x = xVar;
    real y = yVar;
    
    bottom = y + size.getY();
    top = y;
    left = x;
    right = x + size.getX();
    
    position.setXY(x, y);
}


void BoundingBox::update(const Vector &pos, const Vector &s) {
    bottom = pos.getY() + s.getY();
    top = pos.getY();
    left = pos.getX();
    right = pos.getX() + s.getX();
    position = pos;
    size = s;
}

void BoundingBox::draw(sf::RenderWindow &window) const {
    sf::RectangleShape rec;
    rec.setOrigin(0,0);
    rec.setPosition(position.getX(), position.getY());
    sf::Vector2f s(size.getX(), size.getY());
    rec.setSize(s);
    rec.setFillColor(sf::Color::Blue);
    window.draw(rec);
}

void BoundingBox::printDebug() const {
    std::cout << "Bottom: " << bottom << " ";
    std::cout << "Top: " << top << " ";
    std::cout << "Left: " << left << " ";
    std::cout << "Right: " << right << std::endl;
}