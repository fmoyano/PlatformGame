//
//  ScreenManager.cpp
//  PlatformGame
//
//  Created by fran on 06/03/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "ScreenManager.h"
#include <iostream>
#include <cstdlib>
#include "Level1Screen.h"

//This static variable must be defined here (global scope)
//Don't use static modifier here (yes in the declaration in .h)
ScreenManager* ScreenManager::instance = NULL;

ScreenManager::ScreenManager() {}

ScreenManager::ScreenManager(const ScreenManager&) {}

ScreenManager::~ScreenManager() {}

ScreenManager& ScreenManager::getInstance() {
    if(instance == NULL) {
        instance = new ScreenManager();
        atexit(&destroyScreenManager);
    }
    return *instance;
}

void ScreenManager::destroyScreenManager() {
    if(instance != NULL) {
        delete instance;
    }
}

void ScreenManager::switchScreen(GameScreen *gameScreen) {
    /*temporalScreen = gameScreen;
    if (transi) {
        fade.setActive(true);
        fade.setAlpha(0.0f);
    } */
    
    currentScreen -> unloadContent();
    delete currentScreen;
    currentScreen = gameScreen;
    currentScreen -> loadContent();
    
}

void ScreenManager::initialize() {
    currentScreen = new Level1Screen();
    //transi = false;
    //char *cad = "fileTest.txt"
    //You can load what you want here
    /*file.loadContent("/Users/franciscomoyanolara/Library/Developer/Xcode/DerivedData/PlatformGame-gykrvfihyhgiaxgvlambblqtmrdg/Build/Products/Debug/PlatformGame.app/Contents/Resources/fileTest.txt", attributes, contents);
    std::cout<<resourcePath();*/
}

void ScreenManager::loadContent() {
    currentScreen->loadContent();
    /*sf::Texture texture;
    sf::Vector2f position;
    fade.loadContent("", texture, position);
    fade.setAlpha(0.0f);*/
}


void ScreenManager::inputUpdate(sf::Event event, sf::Time elapsedTime) {
    /*if (!transi) {
        currentScreen->update(event);
    }
    transition(elapsedTime);*/
    currentScreen -> inputUpdate(event, elapsedTime);
}

void ScreenManager::liveInputUpdate(sf::Time elapsedTime) {
    currentScreen -> liveInputUpdate(elapsedTime);
}

void ScreenManager::draw(sf::RenderWindow &window) {
    currentScreen->draw(window);
}

/*void ScreenManager::transition(sf::Time elapsedTime) {
    if (transi) {
        fade.update(elapsedTime);
        if(fade.getAlpha() >= 1.0f) {
            currentScreen -> unloadContent();
            delete currentScreen;
            currentScreen = temporalScreen;
            currentScreen -> loadContent();
            temporalScreen = NULL;
        } else if (fade.getAlpha() <= 0.0f) {
            transi = false;
            fade.setActive(false);
        }
    }
}

float ScreenManager::getAlpha() {
    return fade.getAlpha();
}

void ScreenManager::setTransitionEnabled(bool val) {
    transi = val;
}*/
