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
    position.setY(560);
    velocity.setX(0);
    velocity.setY(0);
    acceleration.setX(0);
    acceleration.setY(0);
    rectangle.setPosition(position.getX(), position.getY());
    rectangle.setOrigin(0, 0);
    rectangle.setSize(sf::Vector2f(20, 20));
    rectangle.setFillColor(sf::Color::White);
}

void Player::draw(sf::RenderWindow &window) {
    rectangle.setPosition(position.getX(), position.getY());
    window.draw(rectangle);
}

void Player::update(InputManager &input, sf::Time elapsedTime) {
    if (input.keyPressed(sf::Keyboard::Up)) {
        acceleration.setY(-Jump_Acceleration);
    } else if (input.keyPressed(sf::Keyboard::Space)) {
        acceleration.setY(Gravity);
    }
    
    
    
    integrate(elapsedTime);
}

void Player::liveUpdate(sf::Time elapsedTime) {
    
    Vector temp;
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        velocity.setX(Player_Velocity_X);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        velocity.setX(-Player_Velocity_X);
    } else {
        velocity.setX(0);
    }
    
    integrate(elapsedTime);
 
}

void Player::integrate(sf::Time elapsedTime) {
    if (position.getY() > 560) {
        position.setY(560);
        acceleration.setY(0);
    }
    velocity.addScaledVector(acceleration, elapsedTime.asSeconds());
    position.addScaledVector(velocity, elapsedTime.asSeconds());
}

Vector Player::getPosition() {
    return position;
}

Vector Player::getVelocity() {
    return velocity;
}

Vector Player::getAcceleration() {
    return acceleration;
}

void Player::setPosition(Vector &pos) {
    position.setX(pos.getX());
    position.setY(pos.getY());
}

void Player::setVelocity(Vector &velocity) {
    this->velocity.setX(velocity.getX());
    this->velocity.setY(velocity.getY());
}

void Player::setAcceleration(Vector &acc) {
    acceleration.setX(acc.getX());
    acceleration.setY(acc.getY());
}



