//
//  BoundingBox.h
//  PlatformGame
//
//  Created by fran on 06/04/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__BoundingBox__
#define __PlatformGame__BoundingBox__

#include <iostream>
#include "core.h"
#include "Vector.h"
#include <SFML/Graphics.hpp>

class BoundingBox {
  
public:
    BoundingBox();
    BoundingBox(real b, real t, real l, real r);
    BoundingBox(const Vector &position, const Vector &size);
    ~BoundingBox();
    
    void update(const Vector &pos);
    void update(const Vector &pos, const Vector &s);
    void update(real x, real y);
    void draw(sf::RenderWindow &window) const;
    void printDebug() const;
    
    real getBottom() const;
    real getTop() const ;
    real getLeft() const;
    real getRight() const;
    Vector getPosition() const;
    Vector getSize() const;
    
    void setPosition(const Vector &pos);
    void setSize(const Vector &size);
    
private:
    real bottom, top, left, right;
    Vector position, size;
};

#endif /* defined(__PlatformGame__BoundingBox__) */
