//
//  Rope.h
//  PlatformGame
//
//  Created by fran on 22/07/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__Rope__
#define __PlatformGame__Rope__

#include <iostream>
#include "Entity.h"
#include <SFML/Graphics.hpp>

class Rope : public Entity {
    
public:
    Rope(Vector *anchorPoint, Vector *movingPoint);
    ~Rope();
    
    void setAnchorPoint(Vector *ap);
    void setLength(real l);
    
    void initialize();
    void draw(sf::RenderWindow &window);
    void update(sf::Time elapsedTime);

    Vector *getAnchorPoint() const;
    real getLength() const;

    
private:
    Vector *anchorPoint, *movingPoint;
    real length;
    sf::Vertex line[2];
};

#endif /* defined(__PlatformGame__Rope__) */
