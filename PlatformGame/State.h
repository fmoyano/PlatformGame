//
//  State.h
//  PlatformGame
//
//  Created by fran on 08/07/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__State__
#define __PlatformGame__State__

#include <iostream>
template <class entityType>
class State {
    
public:
    virtual void enter(entityType*) = 0;
    virtual void execute(entityType*) = 0;
    virtual void exit(entityType*) = 0;
    virtual ~State(){}
};
#endif /* defined(__PlatformGame__State__) */
