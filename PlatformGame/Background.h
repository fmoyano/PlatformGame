//
//  Background.h
//  PlatformGame
//
//  Created by fran on 12/05/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__Background__
#define __PlatformGame__Background__

#include <iostream>
#include <string>
#include "Entity.h"

class Background:public Entity {
    
public:
    Background(const std::string &fileName);
    ~Background();
    
    void draw(sf::RenderWindow &window);
private:
    sf::Texture backgroundTexture;
    sf::Sprite background;
    
    
    
    
};

#endif /* defined(__PlatformGame__Background__) */
