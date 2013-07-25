//
//  Level1Screen.cpp
//  PlatformGame
//
//  Created by fran on 02/04/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "Level1Screen.h"
#include "Vector.h"
#include "ResourcePath.hpp"
#include "ScreenManager.h"

//For random number generator
#include <cstdlib>
#include <ctime>

Level1Screen::Level1Screen() {
 
    
    cd = new CollisionDetector();

    player = new Player(0, 460, 20, 20);
    player->initialize();
    
    enemy = new Enemy(400, 460, 20);
    enemy->initialize();
    enemy->setSpeed(120);
    
    pickable = new Pickable(600, 450, 40, 40);
    pickable -> initialize();
    
    rope = new Rope(new Vector(400, 600), new Vector(400,700));
    rope->initialize();
    
    //We provide the enemy information about the player and the level
    enemy->setPlayer(player);
    enemy->setPickable(pickable);
    enemy->setWorld(this);
    enemy->setAngle(0);
    
    floor = new Platform(0, 580, 1000, 20);
    platform = new Platform(160, 200, 100, 20);
    platform2 = new Platform(150, 800, 100, 20);
    movPlat1 = new MovablePlatform(500, 100, 300, 20, true, true);
    movPlat1->addPathPoint(new Vector(500, 500));
    movPlat1->addPathPoint(new Vector(900, 500));
    movPlat1->addPathPoint(new Vector(900, 100));
    
    movPlat2 = new MovablePlatform(1200, 100, 100, 20, true, true);
    movPlat2 -> addPathPoint(new Vector(1200, 800));
    movPlat2 -> setSpeed(250);
    
    movPlat3 = new MovablePlatform(150, 900, 100, 20, true, true);
    movPlat3 -> addPathPoint(new Vector(1000, 900));
    movPlat3 -> setSpeed(200);
    
    stair = new Stair(150, 200, 20, 500);
    
    //Here we apply the view for scrolling purposes
    //We will draw in the whole screen
    //size of the image: 2576, 1770
    /*view.reset(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
    view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
    view.setCenter(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);*/
    
    //We prepare the main layer: its objects and the view
    ScreenLayer *mainLayer = new ScreenLayer(1);
    mainLayer -> setView(0, 0, SCREEN_WIDTH, SCREEN_WIDTH);
    mainLayer -> setViewPort(0, 0, 1.0f, 1.0f);
    mainLayer -> setCenter(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    mainLayer -> addObject(floor);
    mainLayer -> addObject(platform);
    mainLayer -> addObject(platform2);
    mainLayer -> addObject(movPlat1);
    mainLayer -> addObject(movPlat2);
    mainLayer -> addObject(movPlat3);
    mainLayer -> addObject(stair);
    /*srand((unsigned)time(0));
    for (int i = 0; i < 10; i++) {
        int posX = rand() % 2576;
        int posY = rand() % 1170;
        platformSet[i] = new Platform(posX, posY, 100, 20);
        mainLayer->addObject(platformSet[i]);
        cd->addGameObject(platformSet[i]);
    }*/
    mainLayer -> addObject(rope);
    mainLayer -> addObject(pickable);
    mainLayer -> addObject(enemy);
    mainLayer -> addObject(player);

    
    cd->addGameObject(floor);
    cd->addGameObject(platform);
    cd->addGameObject(platform2);
    cd->addGameObject(movPlat1);
    cd->addGameObject(movPlat2);
    cd->addGameObject(movPlat3);
    cd->addGameObject(stair);
    cd->addGameObject(player);
    cd->addGameObject(enemy);
    cd->addGameObject(pickable);
    cd->addGameObject(rope);
    
    /*gameObjects.push_back(floor);
    gameObjects.push_back(platform);
    gameObjects.push_back(platform2);
    gameObjects.push_back(platform3);
    gameObjects.push_back(platform4);
    gameObjects.push_back(stair);
    gameObjects.push_back(player);*/
    
    background = new Background(resourcePath() + "Amanecer_BG.png");
    ScreenLayer *backgroundLayer = new ScreenLayer(0);
    backgroundLayer -> setView(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    backgroundLayer -> setViewPort(0, 0, 1.0f, 1.0f);
    backgroundLayer -> setCenter(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    backgroundLayer -> addObject(background);
    
    //Finally we add the layers (the order is important)
    //The last thing we add would be drawn onto the previous things
    addLayer(backgroundLayer);
    addLayer(mainLayer);
    
}

Level1Screen::~Level1Screen() {
    //Each layer is in charge of destroying its objects
    delete cd;
    //we have to delete the pointers to layers
    for (int i = 0; i < numLayers; i++) {
        delete layers[i];
    }
}

void Level1Screen::loadContent() {
    
    //Initialize each game object
    /*std::vector<Entity *>::iterator iter;
    
    for(iter = gameObjects.begin(); iter != gameObjects.end(); iter++) {
        Entity *e = *iter;
        e->initialize();
        cd->addGameObject(e);
    }*/
}

void Level1Screen::unloadContent() {
    cd->clear();
}

void Level1Screen::inputUpdate(const sf::Event &event, sf::Time elapsedTime) {
    input.update(event);
    /*std::vector<Entity *>::iterator iter;
    
    for(iter = gameObjects.begin(); iter != gameObjects.end(); iter++) {
        Entity *e = *iter;
        e->inputUpdate(input, elapsedTime);
    }*/
    
    player->inputUpdate(input, elapsedTime);
    //cd->checkCollision(); NOT SURE IF IT IS REQUIRED HERE
}

/*void Level1Screen::liveInputUpdate(sf::Time elapsedTime) {
    player->liveUpdate(elapsedTime);
}*/

void Level1Screen::update(sf::Time elapsedTime) {
    
    real velY = player -> getVelocity().getY();
    real velX = player -> getVelocity().getX();
    real posY = player -> getPosition().getY();
    real posX = player -> getPosition().getX();
    for (int i = 0; i < numLayers; i++) {
        layers[i]->update(posX, posY, velX, velY, elapsedTime);
    }
    
    //We check collision now for every layer
    //we could add to the collision detector only the objects of the playable layer
    cd->checkCollision();
    
    /*
    std::cout << "Pos X: " << posX << " " << "Pos Y: " << posY << std::endl;
    for(int i = 0; i < 5; ++i) {
        printf("\n");
    }*/
    
    /*
    //For parallax scrolling, we update each view with different speeds
    if (player->getPosition().getX() + 10 > 1280/2) {
        //If we're not out of the limits
        if (player->getPosition().getX() < 2576/2 + 1280/2) { //2576
            view.move(player->getVelocity().getX() * elapsedTime.asSeconds(), 0);
            viewBackground.move(player->getVelocity().getX() * elapsedTime.asSeconds() * 0.3, 0);
        }
    } 
    
    if (player->getPosition().getY() + 10 > 800/2) {
        if (player->getPosition().getY() < 1170/2 + 400) { //1170
            view.move(0, player->getVelocity().getY() * elapsedTime.asSeconds());
            viewBackground.move(0, player->getVelocity().getY() * elapsedTime.asSeconds() * 0.3);

        }
    } */
    
}

void Level1Screen::draw(sf::RenderWindow &window) {
    
    
    for (int i = 0; i < numLayers; i++) {
        layers[i] -> draw(window);
        /*sf::View v = layers[i] -> getView();
        sf::Vector2f pos =  v.getCenter();
        std::cout << "POS X: " << pos.x << " POS Y:" << pos.y << std::endl;*/
    }
    
    /*
    std::vector<Entity *>::iterator iter;
    
    
    window.setView(viewBackground);
    window.draw(background);
    
    window.setView(view);
    for(iter = gameObjects.begin(); iter != gameObjects.end(); iter++) {
        Entity *e = *iter;
        e->draw(window);
    }*/
    
    //window.setView(viewForeground);
    //window.draw(foreground);
 
}