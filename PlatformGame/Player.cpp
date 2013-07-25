//
//  Player.cpp
//  PlatformGame
//
//  Created by fran on 02/04/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "Player.h"

Player::Player() {
    setType("player");
}

Player::Player(const Vector &pos, const Vector &size) {
    setType("player");
    position.setXY(pos.getX(), pos.getY());
    this->size.setXY(size.getX(), size.getY());
}

Player::Player(real px, real py, real sx, real sy) {
    setType("player");
    position.setXY(px, py);
    this->size.setXY(sx, sy);
}

Player::~Player() {
    //BoundingBox is deleted in Entity (because all entities have to)
    if (movPlatform) {
        delete movPlatform;
    }
}

void Player::initialize() {
    velocity.setXY(0, 0);
    acceleration.setXY(0, 0);
    
    BoundingBox *bb = new BoundingBox(position, size);
    setBoundingBox(bb);
    
    movPlatform = NULL;
    
    isJumping = false;
    onStair = false;
    isRunning = false;
    goingDown = false;
    goingUp = false;
    isFalling = false;
    isWalking = false;
    isAccelerating = false;
    onMovingPlatform = false;
    initialVelocity.setXY(0, 0);
    
    //Image of the player
    rectangle.setPosition(position.getX(), position.getY());
    rectangle.setOrigin(0, 0);
    rectangle.setSize(sf::Vector2f(size.getX(), size.getY()));
    rectangle.setFillColor(sf::Color::Cyan);
    
}

void Player::draw(sf::RenderWindow &window) {
    rectangle.setPosition(position.getX(), position.getY());
    window.draw(rectangle);
    if (_DEBUG) {
        //getBoundingBox()->draw(window);
    }
}

void Player::inputUpdate(const InputManager &input, sf::Time elapsedTime) {
    
    if (input.keyPressed(sf::Keyboard::Up) && !isJumping && onFloor) {
        //if we're on a moving platform, we have to jump with a strength relative
        //to the movement of the platform. Otherwise, if we don't do that, we'll see that the
        //player jumps less when the platform is going up, and that jumps more when the platform is going down
        if (movPlatform) {
            velocity.setY(-JUMP_IMPULSE + movPlatform->getVelocity().getY());
        } else {
            velocity.setY(-JUMP_IMPULSE);
        }
        isJumping = true;
        movPlatform = NULL;
    }
    
}

void Player::update(sf::Time elapsedTime) {
    
    //Reset information for the collision system
    isFalling = false;
    isWalking = false;
    isRunning = false;
    isAccelerating = false;
    
    if (movPlatform) {
        initialVelocity.setXY(movPlatform->getVelocity().getX(), movPlatform->getVelocity().getY());
    } else {
        initialVelocity.setXY(0, 0);
    }
    
    //Is it falling?
    if (isJumping && velocity.getY() > 0) {
        isFalling = true;
    }
    
    //Is it accelerating?
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
        isAccelerating = true;
    }
    
    //STAIR MANAGEMENT
    //Climbing up stairs?
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
            onStair && !onFloor) {
        velocity.setY(-100);
        goingUp = true;
        
    //Climbing down stairs?
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && onStair) {
        velocity.setY(100);
        goingDown = true;
    
    //if no keys are pressed but the player was climbing up or down before, just stay quiet
    } else if (goingUp || goingDown) {
        velocity.setY(0);
        acceleration.setY(0);
    }
    
    //If we're not on a stair, reset goingUp and goingDown
    if (!onStair) {
        goingUp = false;
        goingDown = false;
    }
 
    //Is it walking or running?
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        isWalking = true;
        
        //Initial velocity
        if (velocity.getX() < PLAYER_VELOCITY_X + initialVelocity.getX()) {
            velocity.setX(PLAYER_VELOCITY_X + initialVelocity.getX());
        }
        
        //Possible acceleration
        if (isAccelerating) {
            acceleration.setX(ACCELERATION_X);
        } else {
            acceleration.setX(-ACCELERATION_X);
        }
        
        //Final velocity
        if (velocity.getX() >= MAX_VELOCITY_X) {
            isRunning = true;
            velocity.setX(MAX_VELOCITY_X);
            acceleration.setX(0);
        }
        
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        isWalking = true;
        
        //Initial velocity
        if (velocity.getX() >= -PLAYER_VELOCITY_X + initialVelocity.getX()) {
            velocity.setX(-PLAYER_VELOCITY_X + initialVelocity.getX());
        }
        
        //Possible acceleration
        if (isAccelerating) {
            acceleration.setX(-ACCELERATION_X);
        } else {
            acceleration.setX(ACCELERATION_X);
        }

        //Final velocity
        if (abs(velocity.getX()) >= MAX_VELOCITY_X) {
            isRunning = true;
            velocity.setX(-MAX_VELOCITY_X);
            acceleration.setX(0);
        }
    
    } else {
        
        //If no keys are pressed, we don't want to follow an acceleration
        //(not now at least)
        acceleration.setX(0);
        
        //If we are on a moving platform, we have to set by default the initial velocity
        //This initial velocity is set by the collision system if it detects a collision
        //with some moving platform. Otherwise it's zero
        velocity.setX(initialVelocity.getX());
        //velocity.setY(initialVelocity.getY());
    }
 
    //PROBAR ESTO!!
    //¿Funcionaría if movPlatform velocity.sety(movPlatform -> getVelocity().gety()
    if (movPlatform && movPlatform->getVelocity().getY() <= 0) {
        velocity.addVector(0, initialVelocity.getY()*elapsedTime.asSeconds());
    } else if (movPlatform && movPlatform->getVelocity().getY() > 0) {
        velocity.setY(movPlatform->getVelocity().getY());
    }
    
    //Gravity is only applied if the player is not climbing up or down
    if (!onStair && !goingUp && !goingDown) {
        acceleration.setY(GRAVITY);
    }
    
    
    //Integrate the position update from acceleration and velocity information
    integrate(elapsedTime);
    
    //After the end of an update, we have to reset the values (possibly) changed by the
    //collision system (onCollision).
    //NOTE: values that need to be checked if changed by the collision system must not be
    //reset here, but in the beginning of update
    onStair = false;
    onFloor = false;
    movPlatform = NULL;
    //onMovingPlatform = false;
    //initialVelocity.setXY(0, 0);
}

void Player::onCollision(Entity &e) {
        
    if (e.getType() == "Platform") {
        //movPlatform = NULL;
        //If it's colliding with the surface (floor)
        if (velocity.getY() >= 0) {
            isJumping = false;
            onFloor = true;
            if (!goingDown && !goingUp) {
                position.setY(e.getBoundingBox()->getTop() - getBoundingBox()->getSize().getY());
                velocity.setY(0);
                acceleration.setY(0);
            }
        } else {
            //It's colliding with the cieling (but if it's not climbing up or down stairs)
            if (!goingDown && !goingUp) {
                position.setY(e.getBoundingBox()->getBottom());
                velocity.setY(0);
            }
        }
    }
    
    if (e.getType() == "MovablePlatform") {
        //If it's colliding with the surface (floor)
        if (velocity.getY() >= 0) {
            isJumping = false;
            onFloor = true;
            //onMovingPlatform = true;
            
            movPlatform = (MovablePlatform *)&e;
            //initialVelocity.setXY(e.getVelocity().getX(), e.getVelocity().getY());
            position.setY(e.getBoundingBox()->getTop() - getBoundingBox()->getSize().getY());
            velocity.setY(0);
            acceleration.setY(0);
        }
    }
    
    if (e.getType() == "Stair") {
        //movPlatform = NULL;
        onStair = true;
        //Is also on the floor? Because if it's on the floor, the player should be able to jump
        if (position.getY() + size.getY() <= e.getPosition().getY()) {
            onFloor = true;
        }
    }
    
    if (e.getType() == "Enemy") {
        std::cout << "Collision with enemy" << std::endl;
    }
}

void Player::printDebug() const {
    
    std::cout << "Position x " << position.getX() << " Position y " << position.getY();
    std::cout << "Velocity x " << velocity.getX() << " Velocity y " << velocity.getY();
    std::cout << "Accel x " << acceleration.getX() << " Acceleration y " << acceleration.getY();

}
/*void Player::integrate(sf::Time elapsedTime) {
    if (position.getY() > 560) {
        position.setY(560);
        acceleration.setY(0);
    }
    velocity.addScaledVector(acceleration, elapsedTime.asSeconds());
    position.addScaledVector(velocity, elapsedTime.asSeconds());
}*/



