//
//  CollisionDetector.cpp
//  PlatformGame
//
//  Created by fran on 06/04/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "CollisionDetector.h"

CollisionDetector::CollisionDetector() { }
CollisionDetector::~CollisionDetector() { }

void CollisionDetector::addGameObject(Entity *e) {
    gameObjects.push_back(e);
    if (_DEBUG) {
        //std::cout << "Entity " << e->getType() << " added" << std::endl;
        //e->getBoundingBox()->printDebug();
    }
}

void CollisionDetector::clear() {
    
    std::vector<Entity*>::iterator li;
    //No memory leaks!
    for (li = gameObjects.begin(); li != gameObjects.end(); li++) {
        delete *li;
    }
    gameObjects.clear();
}

void CollisionDetector::forDebug() {
    
    std::vector<Entity*>::iterator li;
    
    for (li = gameObjects.begin(); li != gameObjects.end(); li++) {
        Entity *e = *li;
        std::cout << e->getType() << " " << "Positions: x " << e->getPosition().getX() << " y " << e->getPosition().getY() << std::endl;
    }
}

void CollisionDetector::checkCollision() {
    
    std::vector<Entity*>::iterator li, li2;
   
     for (li = gameObjects.begin(); li != gameObjects.end(); li++) {
         Entity *e1 = *li;
         for (li2 = li; li2 != gameObjects.end(); li2++) {
             Entity *e2 = *li2;
             if (collision(e1, e2) && e1 != e2) {
                 /*if (_DEBUG) {
                     std::cout << "COLLISION DETECTED" << std::endl;
                 }*/
                 e1->onCollision(*e2);
                 e2->onCollision(*e1);
             }
         }
     }
}

bool CollisionDetector::collision(Entity *e1, Entity *e2) {

    return !(
             (e1->getBoundingBox()->getBottom() < e2->getBoundingBox()->getTop()) ||
             (e1->getBoundingBox()->getTop() > e2->getBoundingBox()->getBottom()) ||
             (e1->getBoundingBox()->getLeft() > e2->getBoundingBox()->getRight()) ||
             (e1->getBoundingBox()->getRight() < e2->getBoundingBox()->getLeft()) 
             );
}