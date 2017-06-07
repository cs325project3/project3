//
//  graph.hpp
//  cs325_project3


#ifndef graph_hpp
#define graph_hpp

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include "city.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

class Graph {

private:
    int numCities;
    std::vector<City*>cities;
    int **adjMatrix;
    
    
public:
    Graph();
    void readFile(std::string);
    int getNumCities();
    void setNumCities(int);
    int getDistance(City*, City*);
    void setDistance(City*, City*);
    void printGraph();
    City* getCity(int);
};
#endif /* graph_hpp */
