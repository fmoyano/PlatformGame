//
//  Pickable.cpp
//  PlatformGame
//
//  Created by fran on 10/07/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "Pickable.h"

Pickable::Pickable() {
    position.setXY(0, 0);
    velocity.setXY(0, 0);
    acceleration.setXY(0, 0);
    setType("Pickable");
}

Pickable::Pickable(real px, real py, real sx, real sy) {
    position.setXY(px, py);
    size.setXY(sx, sy);
    setType("Pickable");
}

Pickable::Pickable(const Vector &pos, const Vector &s) {
    //IS THIS OK?
    //position = pos;
    //size = s;
    position.setXY(pos.getX(), pos.getY());
    size.setXY(s.getX(), s.getY());
    setType("Pickable");
    
}

Pickable::~Pickable() {}

void Pickable::initialize() {
    
    BoundingBox *bb = new BoundingBox(position, size);
    setBoundingBox(bb);
    
    pickable.setPosition(position.getX(), position.getY());
    pickable.setOrigin(0, 0);
    pickable.setSize(sf::Vector2f(size.getX(), size.getY()));
    pickable.setFillColor(sf::Color::Magenta);
    
}


void Pickable::draw(sf::RenderWindow &window) {
    pickable.setPosition(position.getX(), position.getY());
    window.draw(pickable);
}

void Pickable::update(sf::Time elapsedTime) {
    
}
void Pickable::onCollision(Entity &e) {
    
}