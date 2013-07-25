//
//  TitleScreen.cpp
//  PlatformGame
//
//  Created by fran on 11/03/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "TitleScreen.h"

TitleScreen::TitleScreen() {}
TitleScreen::~TitleScreen(){}

void TitleScreen::loadContent() {
    if(!font.loadFromFile(resourcePath() + "Font1.ttf")) {
        std::cout << "Could not find font file" << std::endl;
    }
    
    text.setFont(font);
    text.setString("This is the TitleScreen");
    
    keys.push_back(sf::Keyboard::Z);
    keys.push_back(sf::Keyboard::Return);
    
}

void TitleScreen::unloadContent() {
    GameScreen::unloadContent();
    
}

void TitleScreen::inputUpdate(const sf::Event &event, sf::Time elapsedTime) {
    input.update(event);
    
    if(input.keyPressed(keys)) {
        ScreenManager& p_SM = ScreenManager::getInstance();
        p_SM.switchScreen(new SplashScreen());
    }   
}

/*void TitleScreen::liveInputUpdate(sf::Time elapsedTime) {
  
}*/

void TitleScreen::update(sf::Time elapsedTime) {
    
}

void TitleScreen::draw(sf::RenderWindow &window) {
    window.draw(text);
}
