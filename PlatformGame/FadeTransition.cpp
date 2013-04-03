//
//  FadeAnimation.cpp
//  PlatformGame
//
//  Created by fran on 23/03/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "FadeTransition.h"

FadeTransition::FadeTransition() {}
FadeTransition::~FadeTransition() {}

void FadeTransition::loadContent(std::string text, sf::Texture texture, sf::Vector2f position) {
    
    Transition::loadContent(text, texture, position);
    increase = false;
    fadeSpeed = 1.0f;
}

void FadeTransition::unloadContent() {
    
}

void FadeTransition::update(sf::Time elapsedTime) {
    if (active) {
        if (!increase) {
            alpha -= elapsedTime.asSeconds()*fadeSpeed;
        } else {
            alpha += elapsedTime.asSeconds()*fadeSpeed;
        }
        if (alpha >= 1.0f) {
            alpha = 1.0f;
            increase = false;
        } else if (alpha <= 0.0f) {
            increase = true;
        }
        
    } else {
        alpha = 1.0f;
    }
}

void FadeTransition::draw(sf::RenderWindow &window) {
    Transition::draw(window);
}

void FadeTransition::setAlpha(float value) {
    alpha = value;
    if (alpha == 0.0f) {
        increase = true;
    } else {
        increase = false;
    }
}