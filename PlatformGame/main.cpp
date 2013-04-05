
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

#include "ResourcePath.hpp"
#include "ScreenManager.h"
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Vector.h"

int main(int, char const**)
{

    sf::RenderWindow window(sf::VideoMode(ScreenWidth, ScreenHeight, 32), "Platformer");
    window.setKeyRepeatEnabled(false);
    
    
    /*FOR TESTING TRANSITIONS
     sf::RectangleShape fade = sf::RectangleShape();
    fade.setOrigin(0, 0);
    fade.setSize(sf::Vector2f(ScreenWidth, ScreenHeight));*/
    
    //p_SM is a reference to the same memory address as instance (look getInstance())
    //It's actually a pointer to the same address, but an implicit pointer that
    //is automatically de-referenced (that is, no need to use -> or *)
    ScreenManager::ScreenManager& p_SM = ScreenManager::getInstance();

    p_SM.initialize();
    p_SM.loadContent();
    sf::Event event;
    sf::Clock clock;
    
    while(window.isOpen()) {
        
        sf::Time elapsedTime = clock.restart();

        while(window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                    /*case::sf::Event::KeyPressed:
                    if(event.key.code == sf::Keyboard::S) {
                        p_SM.switchScreen(new SplashScreen());
                    } else if (event.key.code == sf::Keyboard::T) {
                        p_SM.switchScreen(new TitleScreen());
                    }*/
                default:
                    break;
            }
            p_SM.inputUpdate(event, elapsedTime);
        }
        
        //We need two updates: one for events update, another for live keyboard update
        p_SM.liveInputUpdate(elapsedTime);
        
        //Now we need to update the rest of the screen
        p_SM.update(elapsedTime);
        
        /*FADE TESTING: due to the font, no black fade is detected, therefore is white
         fade.setFillColor(sf::Color(255, 255, 255, 255 * p_SM.getAlpha()));
        std::cout << p_SM.getAlpha() << std::endl;
        window.draw(fade);*/
        
        p_SM.draw(window);
        window.display();
        window.clear();
    }
    
    return 0;
}
