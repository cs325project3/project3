//
//  city.hpp
//  cs325_project3
//
//  Created by bergerMacPro on 6/5/17.
//  Copyright © 2017 bergerMacPro. All rights reserved.
//

#ifndef city_hpp
#define city_hpp

#include <stdio.h>


class City {
    
private:
    
    int id;
    int xCoord;
    int yCoord;
    bool visited;
    
public:
    
    City(int, int, int, bool);
    //~City();
    int getId();
    void setId(int);
    int getXcoord();
    void setXcoord(int);
    int getYcoord();
    void setYcoord(int);
    bool isVisited();
    void setVisited(bool);
    
};

#endif /* city_hpp */
