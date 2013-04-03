//
//  FadeAnimation.h
//  PlatformGame
//
//  Created by fran on 23/03/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__FadeTransition__
#define __PlatformGame__FadeTransition__

#include "Transition.h"
#include <iostream>
class FadeTransition:public Transition {
public:
    FadeTransition();
    ~FadeTransition();
    

    void loadContent(std::string text, sf::Texture texture, sf::Vector2f position);
    void unloadContent();
    void update(sf::Time elapsedTime);
    void draw(sf::RenderWindow &window);
    void setAlpha(float value);

private:
    bool increase;
    float fadeSpeed;

};

#endif /* defined(__PlatformGame__FadeAnimation__) */
