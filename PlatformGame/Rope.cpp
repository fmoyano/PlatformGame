//
//  Rope.cpp
//  PlatformGame
//
//  Created by fran on 22/07/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "Rope.h"


Rope::Rope(Vector *anchorPoint, Vector *movingPoint) {
    this -> anchorPoint = anchorPoint;
    this -> movingPoint = movingPoint;
    Vector aux(anchorPoint->getX() - movingPoint->getX(),
               anchorPoint->getY() - movingPoint->getY());
    this -> length = aux.length();
}

Rope::~Rope() {
    if (anchorPoint) {
        delete anchorPoint;
    }
}

void Rope::setAnchorPoint(Vector *ap) {
    anchorPoint = ap;
}

void Rope::setLength(real l) {
    length = l;
}

Vector * Rope::getAnchorPoint() const {
    return anchorPoint;
}

real Rope::getLength() const {
    return length;
}

void Rope::initialize() {
    
    bb = new BoundingBox(anchorPoint->getY(), movingPoint->getY(),
                        anchorPoint->getX()+5, anchorPoint->getX());
    
    line[0] = sf::Vertex(sf::Vector2f(anchorPoint->getX(), anchorPoint->getY()));
}

void Rope::update(sf::Time elapsedTime) {
    
    Vector aux(100,0);
    //movingPoint->addScaledVector(aux, elapsedTime.asSeconds());
    
    //vel = vel + acceleration * elapsedTime.asSeconds();
    bb->update(movingPoint->getX(), movingPoint->getY());
}


void Rope::draw(sf::RenderWindow &window) {
    
    line[1] = sf::Vertex(sf::Vector2f(movingPoint->getX(), movingPoint->getY()));
    window.draw(line, 2, sf::Lines);
    bb->draw(window);

}
