//
//  AnimatedSprite.cpp
//  PlatformGame
//
//  Created by fran on 23/07/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(sf::Time frameTime, bool paused, bool looped) :
m_animation(NULL), m_frameTime(frameTime), m_currentFrame(0), m_isPaused(paused), m_isLooped(looped), m_texture(NULL)
{
    
}

void AnimatedSprite::setAnimation(const Animation& animation)
{
    m_animation = &animation;
    m_texture = m_animation->getSpriteSheet();
    m_currentFrame = 0;
    setFrame(m_currentFrame);
}

void AnimatedSprite::play()
{
    if(m_isPaused)
    {
        m_currentTime = sf::Time::Zero;
        m_isPaused = false;
    }
}

void AnimatedSprite::pause()
{
    m_isPaused = true;
}

void AnimatedSprite::stop()
{
    m_isPaused = true;
    m_currentFrame = 0;
}

void AnimatedSprite::setLooped(bool looped)
{
    m_isLooped = looped;
}

void AnimatedSprite::setColor(const sf::Color& color)
{
    // Update the vertices' color
    m_vertices[0].color = color;
    m_vertices[1].color = color;
    m_vertices[2].color = color;
    m_vertices[3].color = color;
}

sf::FloatRect AnimatedSprite::getLocalBounds() const
{
    sf::IntRect rect = m_animation->getFrame(m_currentFrame);
    
    float width = static_cast<float>(std::abs(rect.width));
    float height = static_cast<float>(std::abs(rect.height));
    
    return sf::FloatRect(0.f, 0.f, width, height);
}

sf::FloatRect AnimatedSprite::getGlobalBounds() const
{
    return getTransform().transformRect(getLocalBounds());
}

bool AnimatedSprite::isLooped() const
{
    return m_isLooped;
}

bool AnimatedSprite::isPlaying() const
{
    return !m_isPaused;
}

sf::Time AnimatedSprite::getFrameTime() const
{
    return m_frameTime;
}

void AnimatedSprite::setFrame(std::size_t newFrame, bool resetTime)
{
    if(m_animation)
    {
        //calculate new vertex positions and texture coordiantes
        sf::IntRect rect = m_animation->getFrame(m_currentFrame);
        
        m_vertices[0].position = sf::Vector2f(0, 0);
        m_vertices[1].position = sf::Vector2f(0, rect.height);
        m_vertices[2].position = sf::Vector2f(rect.width, rect.height);
        m_vertices[3].position = sf::Vector2f(rect.width, 0);
        
        float left = static_cast<float>(rect.left) + 0.0001;
        float right = left + rect.width;
        float top = static_cast<float>(rect.top);
        float bottom = top + rect.height;
        
        m_vertices[0].texCoords = sf::Vector2f(left, top);
        m_vertices[1].texCoords = sf::Vector2f(left, bottom);
        m_vertices[2].texCoords = sf::Vector2f(right, bottom);
        m_vertices[3].texCoords = sf::Vector2f(right, top);
    }
    
    if(resetTime)
        m_currentTime = sf::Time::Zero;
}

void AnimatedSprite::update(sf::Time deltaTime)
{
    // if not paused and we have a valid animation
    if(!m_isPaused && m_animation)
    {
        // add delta time
        m_currentTime += deltaTime;
        
        // if current time is bigger then the frame time advance one frame
        if(m_currentTime >= m_frameTime)
        {
            // reset time
            m_currentTime = sf::Time::Zero;
            
            // get next Frame index
            if(m_currentFrame + 1 < m_animation->getSize())
                m_currentFrame++;
            else
            {
                // animation has ended
                m_currentFrame = 0; // reset to start
                
                if(!m_isLooped)
                {
                    m_isPaused = true;
                }
                
            }
            
            // set the current frame, not reseting the time
            setFrame(m_currentFrame, false);
        }
    }
}

void AnimatedSprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (m_animation && m_texture)
    {
        states.transform *= getTransform();
        states.texture = m_texture;
        target.draw(m_vertices, 4, sf::Quads, states);
    }
}