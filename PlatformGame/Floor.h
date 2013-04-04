//
//  Floor.h
//  PlatformGame
//
//  Created by fran on 04/04/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__Floor__
#define __PlatformGame__Floor__

#include <iostream>
#include <SFML/Graphics.hpp>

class Floor {
  
public:
    Floor();
    ~Floor();

    void initialize();
    void draw(sf::RenderWindow &window);
    
private:
    sf::RectangleShape floor;
};
#endif /* defined(__PlatformGame__Floor__) */
