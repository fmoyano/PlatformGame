//
//  Floor.cpp
//  PlatformGame
//
//  Created by fran on 04/04/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "Floor.h"

Floor::Floor() {}
Floor::~Floor() {}

void Floor::initialize() {
    floor.setOrigin(0, 0);
    floor.setFillColor(sf::Color::Red);
    floor.setPosition(0, 580);
    floor.setSize(sf::Vector2f(800, 20));
}

void Floor::draw(sf::RenderWindow &window) {
    window.draw(floor);
}
