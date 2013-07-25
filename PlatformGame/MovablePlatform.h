//
//  MovablePlatform.h
//  PlatformGame
//
//  Created by fran on 17/04/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__MovablePlatform__
#define __PlatformGame__MovablePlatform__

#include <iostream>
#include "Platform.h"

const int MAX_LENGTH_PATH = 10;
const real PLATFORM_SPEED = 100;

class MovablePlatform : public Platform {
    
public:
    MovablePlatform();
    MovablePlatform(real posX, real posY, real sizeX, real sizeY, bool movEnabled, bool loop);
    ~MovablePlatform();
    
    void initialize();
    void draw(sf::RenderWindow &window);
    void update(sf::Time elapsedTime);
    
    void addPathPoint(Vector *p);
    
    void setLoopMovement(bool l);
    bool isLoopMovement() const;
    
    void setMoveEnabled(bool m);
    bool isMoveEnabled() const;
    
    void setSpeed(real s);
    real getSpeed() const;
    
private:
    Vector *path[MAX_LENGTH_PATH];
    //PathIndex is used to know where to write
    //CurrentIndex is used to now where to read in update
    int currentIndex, numberPoints, numberTimes;
    bool loop, movEnabled;
    Vector *direction;
    real speed;
};

#endif /* defined(__PlatformGame__MovablePlatform__) */
