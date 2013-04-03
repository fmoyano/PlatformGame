//
//  Animation.cpp
//  PlatformGame
//
//  Created by fran on 23/03/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "Transition.h"

Transition::Transition() {}
Transition::~Transition() {}

void Transition::loadContent(std::string text, sf::Texture texture, sf::Vector2f position) {
    this->preText = text;
    this->texture = texture;
    this->position = position;
    alpha = 1.0f;
    textColor = sf::Color(114, 77, 255);
    this->text.setString(text);
    if(texture.getSize().x > 0) { //we loaded it
        sprite.setTexture(texture);
    }
    active = false;
}

void Transition::unloadContent() {
    
}

void Transition::update(sf::Time elapsedTime) {
    
}

void Transition::draw(sf::RenderWindow &window) {
    if(text.getString() != "") {
        window.draw(text);
    }
    if(sprite.getTexture() != NULL) {
        window.draw(sprite);
    }
}

float Transition::getAlpha() {
    return alpha;
}

void Transition::setAlpha(float alpha) {
    this->alpha = alpha;
}

void Transition::setActive(bool value) {
    active = value;
}

