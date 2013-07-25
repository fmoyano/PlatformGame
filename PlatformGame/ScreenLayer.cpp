//
//  ScreenLayer.cpp
//  PlatformGame
//
//  Created by fran on 11/05/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "ScreenLayer.h"

ScreenLayer::ScreenLayer(real factor) {
    this->factor = factor;
}

ScreenLayer::~ScreenLayer() {

    std::vector<Entity *>::iterator iter;
    for(iter = gameObjects.begin(); iter != gameObjects.end(); iter++) {
        delete *iter;
    }
    gameObjects.clear(); //Not sure if needed
}

void ScreenLayer::setView(int iniX, int iniY, int lengthX, int lenghtY) {
    this->view.reset(sf::FloatRect(iniX, iniY, lengthX, lenghtY));
}

void ScreenLayer::setViewPort(real x, real y, real factorX, real factorY) {
    this->view.setViewport(sf::FloatRect(x, y, factorX, factorY));
}

void ScreenLayer::setCenter(float cx, float cy) {
    this->view.setCenter(cx, cy);
}

void ScreenLayer::addObject(Entity *e) {
    gameObjects.push_back(e);
}

real ScreenLayer::getFactor() const {
    return factor;
}

const sf::View & ScreenLayer::getView() const {
    return this->view;
}

//void loadContent();
//void unloadContent();
//void inputUpdate(const sf::Event &event, sf::Time elapsedTime);
void ScreenLayer::update(const Player &player, sf::Time elapsedTime) {
    std::vector<Entity *>::iterator iter;
    
    for(iter = gameObjects.begin(); iter != gameObjects.end(); iter++) {
        Entity *e = *iter;
        e->update(elapsedTime);
    }
        
    //For parallax scrolling, we update each view with different speeds
    //+10 because of the size
    if (player.getPosition().getX() + 10 > 1280/2) {
        //If we're not out of the limits
        //if (player.getPosition().getX() < 2576/2 + 1280/2) { //2576
            view.move(player.getVelocity().getX() * elapsedTime.asSeconds() * factor, 0);
        //}
    }
    
    if (player.getPosition().getY() + 10 > 800/2) {
        //if (player.getPosition().getY() < 1170/2 + 400) { //1170
            view.move(0, player.getVelocity().getY() * elapsedTime.asSeconds() * factor);            
        //}
    }
    
}

void ScreenLayer::update(real posX, real posY, real velX, real velY, sf::Time elapsedTime) {
    std::vector<Entity *>::iterator iter;
    
    for(iter = gameObjects.begin(); iter != gameObjects.end(); iter++) {
        Entity *e = *iter;
        e->update(elapsedTime);
    }
    
    //For parallax scrolling, we update each view with different speeds
    //+10 because of the size
    //SIZE OF THE IMAGE IS HARDCODED (2576 x 1170)
    if (posX + 10 > 1280/2) {
        //If we're not out of the limits
        //if (player.getPosition().getX() < 2576/2 + 1280/2) { //2576
        view.move(velX * elapsedTime.asSeconds() * factor, 0);
        //}
    }
    if (posY + 10 > 1000/2) {
        //if (player.getPosition().getY() < 1170/2 + 400) { //1170
        view.move(0, velY * elapsedTime.asSeconds() * factor);
        //}
    }
  
}

void ScreenLayer::draw(sf::RenderWindow &window) {
    
    window.setView(view);
    std::vector<Entity *>::iterator iter;
    for(iter = gameObjects.begin(); iter != gameObjects.end(); iter++) {
        Entity *e = *iter;
        e->draw(window);
    }
    
}