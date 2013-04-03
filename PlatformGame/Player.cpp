//
//  Player.cpp
//  PlatformGame
//
//  Created by fran on 02/04/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "Player.h"

Player::Player() {}

Player::~Player() {}

void Player::initialize() {
    position.setX(0);
    position.setY(0);
    speed = 100;
    rectangle.setPosition(position.getX(), position.getY());
    rectangle.setSize(sf::Vector2f(20, 20));
}

void Player::draw(sf::RenderWindow &window) {
    window.draw(rectangle);
}

//Update all the parameters
void Player::update(sf::Event event, sf::Time elapsedTime) {

}

void Player::liveUpdate(sf::Time elapsedTime) {
    float x = position.getX();
    float y = position.getY();
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        x += speed * elapsedTime.asSeconds();
    }
    
    position.setX(x);
    rectangle.setPosition(position.getX(), position.getY());
}

float getSpeed();
Vector Player::getPosition() {
    return position;
}

void Player::setSpeed(float v) {
    speed = v;
}

void Player::setPosition(Vector &pos) {
    position.setX(pos.getX());
    position.setY(pos.getY());
}

