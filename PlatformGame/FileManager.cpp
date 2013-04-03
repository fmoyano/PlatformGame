//
//  FileManager.cpp
//  PlatformGame
//
//  Created by fran on 25/03/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#include "FileManager.h"


FileManager::FileManager() {}
FileManager::~FileManager() {}

void FileManager::loadContent(const char* filename, std::vector<std::vector<std::string> > &atributes,
                              std::vector<std::vector<std::string> > &contents) {
    std::ifstream file;
    
    file.open(filename);
    if(file.is_open()) {
        while(!file.eof()) {
            std::string line;
            std::getline(file, line);
            line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
            std::cout << line << std::endl;
            
            
            
        }
    } else {
        std::cout << "Error" << std::endl;
        
    }
}