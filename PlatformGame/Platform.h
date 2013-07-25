//
//  Floor.h
//  PlatformGame
//
//  Created by fran on 04/04/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__Platform__
#define __PlatformGame__Platform__

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Entity.h"

class Platform : public Entity {
  
public:
    Platform();
    Platform(real posX, real posY, real sizeX, real sizeY);
    ~Platform();

    void initialize();
    void draw(sf::RenderWindow &window);
    
    
protected:
    sf::RectangleShape floor;
};
#endif /* defined(__PlatformGame__Floor__) */
