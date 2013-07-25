//
//  Enemy.h
//  PlatformGame
//
//  Created by fran on 08/07/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__Enemy__
#define __PlatformGame__Enemy__

#include <iostream>
#include "Entity.h"
#include "StateMachine.h"
#include <SFML/Graphics.hpp>
#include "GameScreen.h"
#include "Pickable.h"

class Enemy : public Entity {
    
public:
    Enemy();
    Enemy(real px, real py);
    Enemy(const Vector &pos, const Vector &size);
    Enemy(real px, real py, real sx, real sy);
    Enemy(real px, real py, real radius);
    ~Enemy();
    
    void setDirection(const Vector &dir);
    void setSpeed(real sp);
    
    void setWorld(GameScreen *world);
    void setPickable(Pickable *pick);
    void setPlayer(Player *p);
    void setAngle(real angle);
    
    GameScreen* getWorld() const;
    Pickable* getPickable() const;
    Player* gePlayer() const;
    real getAngle() const;
    
    void initialize();
    void draw(sf::RenderWindow &window);
  
    void update(sf::Time elapsedTime);
    void onCollision(Entity &e); //Don't want to miss the chance with 'const' of modifying e
    
    StateMachine<Enemy>* getStateMachine() const;
    void printDebug() const;
    
private:
    //Vector position, velocity, acceleration from Entity;
    sf::CircleShape circle;
    real radius;
    Vector *direction;
    real speed;
    
    //Angle for circular movement
    real angle;
    
    //The enemy has a pointer to the world and to a pickable that protects
    //And direct access to the player
    GameScreen *world;
    Pickable *pick;
    Player *player;

    //State
    //State<Enemy> *currentState;
    StateMachine<Enemy> *sMachine;
};



#endif /* defined(__PlatformGame__Enemy__) */
