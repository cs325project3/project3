//
//  city.cpp
//  cs325_project3
//
//  Created by bergerMacPro on 6/5/17.
//  Copyright © 2017 bergerMacPro. All rights reserved.
//

#include "city.hpp"

City::City(int id, int xCoord, int yCoord, bool visited){
    
    this->xCoord = xCoord;
    this->yCoord = yCoord;
    this->id = id;
    this->visited = visited;
}

int City::getId(){
    return this->id;
}

void City::setId(int id){
    this->id = id;
}

int City::getXcoord(){
    return this->xCoord;
}

void City::setXcoord(int xCoord){
    this->xCoord = xCoord;
}

int City::getYcoord(){
    return this->yCoord;
}

void City::setYcoord(int yCoord){
    this->yCoord = yCoord;
}

bool City::isVisited(){
    return this->visited;
}

void City::setVisited(bool visited){
    this->visited = visited;
}
