//
//  MovablePlatform.cpp
//  PlatformGame
//
//  Created by fran on 17/04/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "MovablePlatform.h"
#include <math.h>

MovablePlatform::MovablePlatform() {
    
}

MovablePlatform::MovablePlatform(real posX, real posY, real sizeX, real sizeY, bool movEnabled, bool loop):
            Platform::Platform(posX, posY, sizeX, sizeY) {
    
    setType("MovablePlatform");
    this->loop = loop;
    this->movEnabled = movEnabled;
    
    path[0] = new Vector(posX, posY);   
    currentIndex = 1;
    numberPoints = 1;
    numberTimes = 0;

    speed = PLATFORM_SPEED;
    direction = NULL;
}

MovablePlatform::~MovablePlatform() {

    for (int i = 0; i < MAX_LENGTH_PATH; i++) {
        if (path[i] != NULL) {
            delete path[i];
        }
    }
    delete direction;
}

void MovablePlatform::initialize() {

}

void MovablePlatform::setSpeed(real s) {
    speed = s;
}


real MovablePlatform::getSpeed() const {
    return speed;
}

void MovablePlatform::draw(sf::RenderWindow &window){
    floor.setPosition(position.getX(), position.getY());
    Platform::draw(window);
}

void MovablePlatform::update(sf::Time elapsedTime) {
    
    if (movEnabled) {
        
        if (abs(position.getX() - path[currentIndex]->getX()) < EPSILON &&
            abs(position.getY() - path[currentIndex]->getY()) < EPSILON) {
            
            currentIndex = (currentIndex + 1) % numberPoints;
            
            if(currentIndex != 0) {
                
                if (numberTimes == 1 && !loop) {
                    movEnabled = false;
                }
                direction->setX(path[currentIndex]->getX() - path[currentIndex - 1]->getX());
                direction->setY(path[currentIndex]->getY() - path[currentIndex - 1]->getY());
                
            } else {
                numberTimes++;
                direction->setX(path[currentIndex]->getX() - path[numberPoints - 1]->getX());
                direction->setY(path[currentIndex]->getY() - path[numberPoints - 1]->getY());
            }
            direction->normalize();
            velocity.setX(speed * direction->getX());
            velocity.setY(speed * direction->getY());
        }
        
        integrate(elapsedTime);
    }
    
}


void MovablePlatform::addPathPoint(Vector *p) {
    path[numberPoints] = p;
    numberPoints++;
    if (numberPoints == 2) {
        if (direction != NULL) {
            delete direction;
        }
        direction = new Vector(path[1]->getX()-path[0]->getX(), path[1]->getY()-path[0]->getY());
        direction->normalize();
        velocity.setX(speed * direction->getX());
        velocity.setY(speed * direction->getY());
    }
}


void MovablePlatform::setLoopMovement(bool l) {
    loop = l;
}

bool MovablePlatform::isLoopMovement() const {
    return loop;
}

void MovablePlatform::setMoveEnabled(bool m) {
    movEnabled = m;
}

bool MovablePlatform::isMoveEnabled() const {
    return movEnabled;
}

