//
//  Player.h
//  PlatformGame
//
//  Created by fran on 02/04/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__Player__
#define __PlatformGame__Player__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vector.h"
#include "InputManager.h"
#include "core.h"
#include "Entity.h"
#include "MovablePlatform.h"

const real PLAYER_VELOCITY_X = 70;
const real MAX_VELOCITY_X = PLAYER_VELOCITY_X + 700;
const real JUMP_IMPULSE = 400;
const real ACCELERATION_X = 400;

/*
#define Player_Velocity_X 70
#define Max_Velocity_X (Player_Velocity_X + 700)
#define Jump_Impulse 400
#define Acceleration_X 400
*/

class Player : public Entity {
  
public:
    Player();
    Player(const Vector &pos, const Vector &size);
    Player(real px, real py, real sx, real sy);
    ~Player();
    
    void initialize();
    void draw(sf::RenderWindow &window);
    
    //Update all the parameters
    void inputUpdate(const InputManager &input, sf::Time elapsedTime);
    void update(sf::Time elapsedTime);
    void onCollision(Entity &e); //Don't want to miss the chance with 'const' of modifying e

    void printDebug() const;
    
private:
    //Vector position, velocity, acceleration from Entity;
    sf::RectangleShape rectangle;
    sf::Sprite sprite;
    sf::Texture texture;
    bool inAir;
    bool isJumping, isWalking, isRunning;
    bool onStair, onFloor, goingDown, goingUp;
    bool isFalling, isAccelerating, onMovingPlatform;
    
    //For example, important if it's riding on a moving platform
    Vector initialVelocity;
    
    //
    MovablePlatform *movPlatform;
    
};

#endif /* defined(__PlatformGame__Player__) */
