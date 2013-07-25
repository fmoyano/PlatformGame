//
//  CollisionDetector.h
//  PlatformGame
//
//  Created by fran on 06/04/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__CollisionDetector__
#define __PlatformGame__CollisionDetector__

#include <list>
#include <iostream>
#include "Entity.h"

class CollisionDetector {
  
public:
    CollisionDetector();
    ~CollisionDetector();
    
    void addGameObject(Entity *e);
    void clear();
    void forDebug();
    void checkCollision();
    bool collision(Entity *e1, Entity *e2);
    
private:
    //WATCH OUT: WHEN ENTITIES ARE DESTROYED, WE HAVE DANGLING POINTERS
    std::vector<Entity*> gameObjects;
    
};

#endif /* defined(__PlatformGame__CollisionDetector__) */
