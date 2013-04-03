//
//  FileManager.h
//  PlatformGame
//
//  Created by fran on 25/03/13.
//  Copyright (c) 2013 fran. All rights reserved.
//

#ifndef __PlatformGame__FileManager__
#define __PlatformGame__FileManager__

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

//NOT FINISHED: TO BE ADAPTED TO YOUR NEEDS
class FileManager {
  
public:
    FileManager();
    ~FileManager();
    
    void loadContent(const char* filename, std::vector<std::vector<std::string> > &atributes,
                     std::vector<std::vector<std::string> > &contents);
private:
    std::vector<std::string> tempAttributes;
    std::vector<std::string> tempContents;
};

#endif /* defined(__PlatformGame__FileManager__) */
