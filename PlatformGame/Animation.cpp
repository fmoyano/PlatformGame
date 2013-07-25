//
//  Animation.cpp
//  PlatformGame
//
//  Created by fran on 23/07/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "Animation.h"

Animation::Animation() : m_texture(NULL)
{
    
}

void Animation::addFrame(sf::IntRect rect)
{
    m_frames.push_back(rect);
}

void Animation::setSpriteSheet(const sf::Texture& texture)
{
    m_texture = &texture;
}

const sf::Texture* Animation::getSpriteSheet() const
{
    return m_texture;
}

std::size_t Animation::getSize() const
{
    return m_frames.size();
}

const sf::IntRect& Animation::getFrame(std::size_t n) const
{
    return m_frames[n];
}