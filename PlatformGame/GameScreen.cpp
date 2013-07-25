//
//  GameScreen.cpp
//  PlatformGame
//
//  Created by fran on 07/03/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "GameScreen.h"

GameScreen::GameScreen() {
    numLayers = 0;
}

GameScreen::~GameScreen() {
     
}

void GameScreen::unloadContent() {
    keys.clear();
}

void GameScreen::addLayer(ScreenLayer *layer) {
    layers[numLayers] = layer;
    numLayers++;
}

int GameScreen::getNumLayers() const {
    return numLayers;
}


//To be implemented by concrete screens
void GameScreen::loadContent() {
   
}

void GameScreen::inputUpdate(const sf::Event &event, sf::Time elapsedTime) {
   
}

void GameScreen::update(sf::Time elapsedTime) {
    
}

void GameScreen::draw(sf::RenderWindow &window) {
    
}