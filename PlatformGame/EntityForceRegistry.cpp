//
//  EntityForceRegistry.cpp
//  PlatformGame
//
//  Created by fran on 23/07/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "EntityForceRegistry.h"

void EntityForceRegistry::add(Entity *e, ForceGenerator *fg) {
    EntityForceRegistration efr;
    efr.e = e;
    efr.fg = fg;
    registry.push_back(efr);
}

void EntityForceRegistry::remove(Entity *e, ForceGenerator *fg) {
    
    EntityForceRegistration efr;
    efr.e = e;
    efr.fg = fg;
    
    //Find the element
    Registry::iterator index = std::find(registry.begin(), registry.end(), efr);
    
    //Freed memory of the heap! No memory leaks
    delete (*index).fg;
    delete (*index).e;
    
    //Erase the element from the vector
    registry.erase(index);
}

void EntityForceRegistry::clear() {
    Registry::iterator i = registry.begin();
    //No memory leaks
    for(i = registry.begin(); i != registry.end(); i++) {
        delete (*i).fg;
        delete (*i).e;
    }
    registry.clear();
}

void EntityForceRegistry::updateForces(sf::Time elapsedTime) {
    Registry::iterator i = registry.begin();
    for(; i != registry.end(); i++) {
        i -> fg -> updateForce(i->e, elapsedTime);
    }
}