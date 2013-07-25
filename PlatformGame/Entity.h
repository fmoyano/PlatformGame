//
//  Entity.h
//  PlatformGame
//
//  Created by fran on 05/04/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__Entity__
#define __PlatformGame__Entity__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "InputManager.h"
#include "Vector.h"
#include "BoundingBox.h"

const real REAL_MAX = std::numeric_limits<real>::max();
class Entity {
    
public:
    Entity();
    ~Entity();
    
    virtual void initialize();
    virtual void draw(sf::RenderWindow &window);
    virtual void inputUpdate(InputManager &input, sf::Time elapsedTime);
    virtual void update(sf::Time elapsedTime);
    virtual void onCollision(Entity &e);
    
    //It's better if we create an integrator class. This way, we can use different
    //integrator implementations (e.g. Euler, RK4)
    void integrate(sf::Time elapsedTime);
    
    Vector getPosition() const;
    Vector getVelocity() const;
    Vector getAcceleration() const;
    const std::string & getType() const;
    const BoundingBox* getBoundingBox() const;
    real getInverseMass() const;
    real getMass() const;
    Vector getForceAccum() const;
    bool hasFiniteMass() const;
    
    void setPosition(const Vector &position);
    void setVelocity(const Vector &velocity);
    void setAcceleration(const Vector &acceleration);
    void setType(const std::string & t);
    void setInverseMass(real im); //Inmovable objects: im = 0
    void setMass(real m);
    void setBoundingBox(BoundingBox *b);
    void setForceAccum(const Vector &fa);
    void addForce(const Vector &force);
    void clearForceAccumulator();
    
protected:
    //Maybe we could have also a size attribute
    Vector position, velocity, acceleration;
    Vector size; // I first needed this size to perform more accurate collision detection
    real inverseMass, mass;
    std::string type;
    BoundingBox *bb;
    //Force accummulated by this entity
    Vector forceAccum;
};

#endif /* defined(__PlatformGame__Entity__) */
