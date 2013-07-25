//
//  Animation.h
//  PlatformGame
//
//  Created by fran on 23/07/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__Animation__
#define __PlatformGame__Animation__

#include <iostream>
#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>

class Animation
{
public:
    Animation();
    
    void addFrame(sf::IntRect rect);
    void setSpriteSheet(const sf::Texture& texture);
    const sf::Texture* getSpriteSheet() const;
    std::size_t getSize() const;
    const sf::IntRect& getFrame(std::size_t n) const;
    
private:
    std::vector<sf::IntRect> m_frames;
    const sf::Texture* m_texture;
};


#endif /* defined(__PlatformGame__Animation__) */
