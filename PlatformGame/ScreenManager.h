//
//  ScreenManager.h
//  PlatformGame
//
//  Created by fran on 06/03/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __ScreenManager__
#define __ScreenManager__

#include <vector>
#include <string>
#include "GameScreen.h"
#include "SplashScreen.h"
#include "TitleScreen.h"
#include "FileManager.h"
//#include "FadeTransition.h"

#define ScreenWidth 800
#define ScreenHeight 600

//ScreenManager manages the different screens in the game
//ScreenManager is a singleton class. This is why the constructor(s) is private
//We only can access the instance by calling getInstance
//Note that in ScreenManager.cpp we have to declare at a global scope the instance variable
//Otherwise, the linker won't find it (no memory would be reserved for it)
class ScreenManager {
public:
    ~ScreenManager();
    
    //For performance issues, return a reference to ScreenManager
    static ScreenManager& getInstance();
    
    void initialize();
    void loadContent();
    void unloadContent();
    void inputUpdate(sf::Event event, sf::Time elapsedTime);
    void liveInputUpdate(sf::Time elapsedTime);
    void update(sf::Time elapsedTime);
    void draw(sf::RenderWindow &window);
    void switchScreen(GameScreen *gameScreen);
    
    //For transition effects between screens
    //float getAlpha();
    //void setTransitionEnabled(bool val);
    
private:
    static ScreenManager* instance;
    static void destroyScreenManager();
    ScreenManager();
    ScreenManager(ScreenManager const&);
    //void operator=(ScreenManager const&);
    //To manage different screens
    GameScreen *currentScreen, *newScreen, *temporalScreen;
    
    //For transition effects between screens
    //void transition(sf::Time elapsedTime);
    //bool transi;
    //FadeTransition fade;
    //FileManager file;
    //std::vector<std::vector<std::string> > attributes;
    //std::vector<std::vector<std::string> > contents;
    
};

#endif /* defined(__ScreenManager__) */
