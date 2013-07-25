//
//  Stair.cpp
//  PlatformGame
//
//  Created by fran on 25/04/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "Stair.h"

Stair::Stair(int posX, int posY, int sizeX, int sizeY) {
    setType("Stair");
    position.setX(posX); position.setY(posY);
    
    stair.setOrigin(0, 0);
    stair.setFillColor(sf::Color::Yellow);
    stair.setPosition(posX, posY);
    stair.setSize(sf::Vector2f(sizeX, sizeY));
    
    Vector size(sizeX, sizeY);
    BoundingBox *bb = new BoundingBox(position, size);
    setBoundingBox(bb);
    
}

Stair::~Stair() {}

void Stair::draw(sf::RenderWindow &window) {
    window.draw(stair);
    /*if (_DEBUG) {
     getBoundingBox()->draw(window);
    }*/
}