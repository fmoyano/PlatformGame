//
//  SplashScreen.cpp
//  PlatformGame
//
//  Created by fran on 07/03/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "SplashScreen.h"

SplashScreen::SplashScreen() {}
SplashScreen::~SplashScreen(){}

void SplashScreen::loadContent() {
    if(!font.loadFromFile(resourcePath() + "Font1.ttf")) {
        std::cout << "Could not find font file" << std::endl;
    }
    
    text.setFont(font);
    text.setString("This is the SplashScreen");
    keys.push_back(sf::Keyboard::Z);
    keys.push_back(sf::Keyboard::Return);

}

void SplashScreen::unloadContent() {
    GameScreen::unloadContent();
}

void SplashScreen::inputUpdate(sf::Event event, sf::Time elapsedTime) {
    input.update(event);
    if(input.keyPressed(keys)) {
        ScreenManager& p_SM = ScreenManager::getInstance();
        p_SM.switchScreen(new TitleScreen());
    }
}

void SplashScreen::liveInputUpdate(sf::Time elapsedTime) {
    
}

void SplashScreen::update(sf::Time elapsedTime) {
    
}

void SplashScreen::draw(sf::RenderWindow &window) {
    window.draw(text);
}

