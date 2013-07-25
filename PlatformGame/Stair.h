//
//  Stair.h
//  PlatformGame
//
//  Created by fran on 25/04/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__Stair__
#define __PlatformGame__Stair__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Stair:public Entity {

public:
    Stair(int posX, int posY, int sizeX, int sizeY);
    ~Stair();

    void draw(sf::RenderWindow &window);
private:
    sf::RectangleShape stair;

    
    
    
};
#endif /* defined(__PlatformGame__Stair__) */
