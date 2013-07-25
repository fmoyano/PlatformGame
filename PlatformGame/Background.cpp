//
//  Background.cpp
//  PlatformGame
//
//  Created by fran on 12/05/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "Background.h"
Background::Background(const std::string &fileName) {
    backgroundTexture.loadFromFile(fileName);
    background.setTexture(backgroundTexture);
}
Background::~Background() {}

void Background::draw(sf::RenderWindow &window) {
    window.draw(background);
}