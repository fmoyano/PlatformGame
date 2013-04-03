//
//  Animation.h
//  PlatformGame
//
//  Created by fran on 23/03/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__Transition__
#define __PlatformGame__Transition__

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

class Transition {
public:
    Transition();
    ~Transition();
    
    virtual void loadContent(std::string text, sf::Texture texture, sf::Vector2f position);
    virtual void unloadContent();
    virtual void update(sf::Time elapsedTime);
    virtual void draw(sf::RenderWindow &window);
    
    virtual void setAlpha(float alpha);
    float getAlpha();
    
    void setActive(bool value);
    
protected:
    float alpha;
    std::string preText;
    sf::Text text;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f position;
    sf::Color textColor;
    sf::IntRect sourceRect;
    bool active;
};

#endif /* defined(__PlatformGame__Animation__) */
