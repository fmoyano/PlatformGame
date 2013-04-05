//
//  Level1Screen.cpp
//  PlatformGame
//
//  Created by fran on 02/04/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "Level1Screen.h"
#include "Vector.h"

Level1Screen::Level1Screen() {
    player = new Player();
    floor = new Floor();
}

Level1Screen::~Level1Screen() {
    delete player;
    delete floor;
}

void Level1Screen::loadContent() {
    player->initialize();
    floor->initialize();
}

void Level1Screen::unloadContent() {
    
}

void Level1Screen::inputUpdate(sf::Event event, sf::Time elapsedTime) {
    input.update(event);
    player->update(input, elapsedTime);
}

void Level1Screen::liveInputUpdate(sf::Time elapsedTime) {
    player->liveUpdate(elapsedTime);
}

void Level1Screen::update(sf::Time elapsedTime) {
    //Enemies and other objects should be updated here
    //because they do not need to depend on the user input
}

void Level1Screen::draw(sf::RenderWindow &window) {
    player->draw(window);
    floor->draw(window);
}