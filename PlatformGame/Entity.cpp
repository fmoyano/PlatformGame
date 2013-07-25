//
//  Entity.cpp
//  PlatformGame
//
//  Created by fran on 05/04/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "Entity.h"
#include <assert.h>

Entity::Entity() {
    forceAccum.setXY(0, 0);
}

Entity::~Entity() {
    delete bb;
}

void Entity::integrate(sf::Time elapsedTime) {
    //Two ways:
    //1) Numerical integration
    //First update velocity with acceleration; then position with velocity
    //velocity.addScaledVector(acceleration, elapsedTime.asSeconds());
    //position.addScaledVector(velocity, elapsedTime.asSeconds());
    //We must update accordingly the object's bounding box
    //...
    //createBoundingBox(object position, object size)
    
    //2) Analytical integration
    //Guess position from velocity and acceleration
    //Update velocity for next iteration
    //1) Work out acceleration
    acceleration += forceAccum * inverseMass;
    position += velocity * elapsedTime.asSeconds() +
            acceleration * elapsedTime.asSeconds() * elapsedTime.asSeconds() * 0.5;
    velocity += acceleration * elapsedTime.asSeconds();

    
    //+ acceleration * elapsedTime.asSeconds() * elapsedTime.asSeconds() * 0,5;
    
    //Vector temp = acceleration.byScalar(0.5 * elapsedTime.asSeconds() * elapsedTime.asSeconds());
    //temp.addScaledVector(velocity, elapsedTime.asSeconds());
    //position.addVector(temp);
    
    //velocity.addScaledVector(acceleration, elapsedTime.asSeconds());
    
    //we have to update the entity's bounding box as well
    bb->update(position);
    clearForceAccumulator();
}

Vector Entity::getPosition() const {
    return position;
}

Vector Entity::getVelocity() const {
    return velocity;
}

Vector Entity::getAcceleration() const {
    return acceleration;
}

bool Entity::hasFiniteMass() const {
    return inverseMass > 0.0f;
}

real Entity::getMass() const {
    
    if (inverseMass == 0) {
        return REAL_MAX;
    } else {
        return ((real)1.0)/inverseMass;
    }
}

real Entity::getInverseMass() const {
    return inverseMass;
}

Vector Entity::getForceAccum() const {
    return forceAccum;
}

void Entity::setPosition(const Vector &pos) {
    position.setXY(pos.getX(), pos.getY());
}

void Entity::setVelocity(const Vector &velocity) {
    this->velocity.setXY(velocity.getX(), velocity.getY());
}

void Entity::setAcceleration(const Vector &acc) {
    acceleration.setXY(acc.getX(), acc.getY());
}

const std::string & Entity::getType() const {
    return type;
}

void Entity::setType(const std::string &t) {
    type = t;
}

const BoundingBox* Entity::getBoundingBox() const {
    return bb;
}

void Entity::setBoundingBox(BoundingBox *b) {
    bb = b;
}

void Entity::setInverseMass(real im) {
    inverseMass = im;
}

void Entity::setMass(real m) {
    assert(mass != 0);
    inverseMass = ((real)1.0)/mass;
}

void Entity::setForceAccum(const Vector &fa)  {
    forceAccum = fa;
}

void Entity::addForce(const Vector &force) {
    forceAccum += force;
}


void Entity::clearForceAccumulator() {
    forceAccum.setXY(0, 0);
}

//Implemented by each specialized entity
void Entity::onCollision(Entity &e) { }
void Entity::initialize() { }
void Entity::draw(sf::RenderWindow &window) {}
void Entity::inputUpdate(InputManager &input, sf::Time elapsedTime) { }
void Entity::update(sf::Time elapsedTime) { }