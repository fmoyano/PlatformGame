//
//  EntityForceRegistry.h
//  PlatformGame
//
//  Created by fran on 23/07/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__EntityForceRegistry__
#define __PlatformGame__EntityForceRegistry__

#include <iostream>
#include "Entity.h"
#include "ForceGenerator.h"
#include <SFML/Graphics.hpp>

class EntityForceRegistry {
    
public:
    void add(Entity *e, ForceGenerator *fg);
    void remove(Entity *e, ForceGenerator *fg);
    void clear();
    void updateForces(sf::Time elapsedTime);

private:
    struct EntityForceRegistration {
        Entity *e;
        ForceGenerator *fg;
        bool operator==(const EntityForceRegistration& efr) {
            //str.compare(str2) = 0 if str is the same string as str2
            return !(efr.e->getType().compare(e->getType()));
                    //&& (efr.fg->getType() == efr.fg->getType() == fg->getType))
        }
    };
    typedef std::vector<EntityForceRegistration> Registry;
    Registry registry;
};

#endif /* defined(__PlatformGame__EntityForceRegistry__) */
