//
//  Floor.cpp
//  PlatformGame
//
//  Created by fran on 04/04/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "Platform.h"

Platform::Platform(real posX, real posY, real sizeX, real sizeY) {

    setType("Platform");
    position.setX(posX); position.setY(posY);
    floor.setOrigin(0, 0);
    floor.setFillColor(sf::Color::Red);
    floor.setPosition(posX, posY);
    floor.setSize(sf::Vector2f(sizeX, sizeY));
    Vector size(sizeX, sizeY);
    BoundingBox *bb = new BoundingBox(position, size);
    setBoundingBox(bb);
}

Platform::Platform() {
    setType("Platform");
}

Platform::~Platform() {
}

void Platform::initialize() {
    /*floor.setOrigin(0, 0);
    floor.setFillColor(sf::Color::Red);
    floor.setPosition(0, 580);
    floor.setSize(sf::Vector2f(300, 20));
    position.setX(0); position.setY(580);
    Vector size(300, 20);
    BoundingBox *bb = new BoundingBox(position, size);
    setBoundingBox(bb);*/
}

void Platform::draw(sf::RenderWindow &window) {
    window.draw(floor);
    /*if (_DEBUG) {
        getBoundingBox()->draw(window);
    }*/
}