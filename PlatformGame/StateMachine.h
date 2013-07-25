//
//  StateMachine.h
//  PlatformGame
//
//  Created by fran on 10/07/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__StateMachine__
#define __PlatformGame__StateMachine__

#include <iostream>
#include "State.h"

template <class entityType>
class StateMachine {
private:
    entityType *owner;
    State<entityType> *currentState;
    State<entityType> *previousState;
    State<entityType> *globalState; //called every update
    
public:
    StateMachine(entityType *own):owner(own),
                            currentState(NULL),
                            previousState(NULL),
                            globalState(NULL) {}
    
    ~StateMachine() {
        delete owner;
        delete currentState;
        delete previousState;
        delete globalState;
    }
    
    void setCurrentState(State<entityType> *s) {
        currentState = s;
    }
    
    void setPreviousState(State<entityType> *s) {
        previousState = s;
    }
    
    void setGlobalState(State<entityType> *s) {
        globalState = s;
    }
    
    void update() const {
        if (globalState) {
            globalState->execute(owner);
        }
        
        if (currentState) {
            currentState->execute(owner);
        }
    }
    
    void changeState(State<entityType> *newState) {
        previousState = currentState;
        currentState->exit(owner);
        currentState = newState;
        currentState->enter(owner);
    }
    
    void revertToPreviousState() {
        changeState(previousState);
    }
    
    State<entityType>* getCurrentState() const {
        return currentState;
    }
    
    State<entityType>* getGlobalState() const {
        return globalState;
    }
    
    State<entityType>* getPreviousState() const {
        return previousState;
    }
    
    
};

#endif /* defined(__PlatformGame__StateMachine__) */
