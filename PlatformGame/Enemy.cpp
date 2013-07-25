//
//  Enemy.cpp
//  PlatformGame
//
//  Created by fran on 08/07/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "Enemy.h"
#include "FollowingPathState.h"
#include <math.h>


Enemy::Enemy() {}

Enemy::Enemy(real px, real py) {
    position.setXY(px, py);
}

Enemy::Enemy(const Vector &pos, const Vector &s) {
    position.setXY(pos.getX(), pos.getY());
    size.setXY(s.getX(), s.getY());
}

Enemy::Enemy(real px, real py, real sx, real sy) {
    position.setXY(px, py);
    size.setXY(sx, sy);
}

Enemy::Enemy(real px, real py, real radius) {
    position.setXY(px, py);
    size.setXY(2*radius, 2*radius);
    this->radius = radius;
}

Enemy::~Enemy() {
    delete direction;
    delete sMachine;
    delete world;
    delete player;
    delete pick;
}


void Enemy::initialize() {
    
    setType("Enemy");

    BoundingBox *bb = new BoundingBox(position, size);
    setBoundingBox(bb);
    
    direction = new Vector(0,0);
    sMachine = new StateMachine<Enemy>(this);
    sMachine->setCurrentState(new FollowingPathState(position.getX()-250, position.getX()+350));
    
    circle.setPosition(position.getX(), position.getY());
    circle.setOrigin(0, 0);
    circle.setRadius(radius);
    circle.setFillColor(sf::Color::Black);
}

void Enemy::setDirection(const Vector &dir) {
    direction->setXY(dir.getX(), dir.getY());

}

void Enemy::setSpeed(real sp) {
    speed = sp;
}

void Enemy::setWorld(GameScreen *world) {
    this->world = world;
    
}
void Enemy::setPickable(Pickable *pick) {
    this->pick = pick;
}

void Enemy::setPlayer(Player *p) {
    this->player = p;
}

void Enemy::setAngle(real a) {
    angle = a;
}

real Enemy::getAngle() const {
    return angle;
}

GameScreen* Enemy::getWorld() const {
    return world;
}

Pickable* Enemy::getPickable() const {
    return pick;
}

Player* Enemy::gePlayer() const {
    return player;
}

void Enemy::draw(sf::RenderWindow &window) {
    circle.setPosition(position.getX(), position.getY());
    window.draw(circle);
    if (_DEBUG) {
        bb->draw(window);
    }
    
}

StateMachine<Enemy>* Enemy::getStateMachine() const {
    return sMachine;
}

void Enemy::update(sf::Time elapsedTime) {

    //sMachine->update();
    //velocity.setX(speed * direction->getX());
    //acceleration.setY(GRAVITY);
    angle = angle + 3*elapsedTime.asSeconds();
    if (angle >= 2*PI) {
        angle = 0;
    }
    position.setXY(pick->getPosition().getX()+cos(angle)*100, pick->getPosition().getY()+sin(angle)*100);
    bb->update(position);
    //integrate(elapsedTime);
}

void Enemy::onCollision(Entity &e) {
    /*if (e.getType() == "Platform") {
        //If it's colliding with the surface (floor)
        if (velocity.getY() >= 0) {
            position.setY(e.getBoundingBox()->getTop() - getBoundingBox()->getSize().getX());
            velocity.setY(0);
            acceleration.setY(0);
       
        }
    }*/
}

void Enemy::printDebug() const {}