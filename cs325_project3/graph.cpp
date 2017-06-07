//
//  graph.cpp
//  cs325_project3
//
//  Created by bergerMacPro on 6/5/17.
//  Copyright © 2017 bergerMacPro. All rights reserved.
//

#include "graph.hpp"

Graph::Graph(){
    numCities = 0;
}

int Graph::getNumCities(){
    return this->numCities;
}

void Graph::setNumCities(int numCities){
    this->numCities = numCities;
}

int Graph::getDistance(City *City1, City *City2){
    return adjMatrix[City1->getId()][City2->getId()];
}

void Graph::setDistance(City *City1, City *City2){
    
    int xValue = (City1->getXcoord() - City2->getXcoord());
    xValue *= xValue;
    int yValue = (City1->getYcoord() - City2->getYcoord());
    yValue *= yValue;
    
    double distance = round(sqrt(xValue + yValue));

    adjMatrix[City1->getId()][City2->getId()] = (int)distance;
}

City* Graph::getCity(int id) {
    
    if(cities.at(id)->getId() != id){
        std::cout << "Id and idx do not match.\n";
    }
    
    return cities.at(id);
}

void Graph::readFile(std::string fileName){
    
    std::ifstream inputFile(fileName);
    std::string line;
    
    while(std::getline(inputFile, line)) {

        std::istringstream iss(line);
        
        int id, x, y;
        
        if(!(iss >> id >> x >> y)) {
            std::cout << "Error reading from file.\n";
        }
        
        City *currentCity = new City(id, x, y, false);
        cities.push_back(currentCity);
        numCities += 1;
    }
    
    adjMatrix = new int*[numCities];
    for(int i = 0; i < numCities; i++) {
        adjMatrix[i] = new int[numCities];
    }
    
    for(int i = 0; i < numCities; i++){
        for(int j = 0; j < numCities; j++){
            setDistance(cities.at(i), cities.at(j));
        }
    }

}

void Graph::printGraph(){
    
    /*for(int i = 0; i < cities.size(); i++) {
        printf("%d %d %d\n", cities.at(i)->getId(), cities.at(i)->getXcoord(), cities.at(i)->getYcoord());
    }*/
    printf("Total number of cities: %d\n", numCities);
    
    /*for(int i = 0; i < numCities; i++){
        
        for(int j = 0; j < numCities; j++){
            printf("%d ", getDistance(cities.at(i), cities.at(j)));
        }
        printf("\n");
    }*/
    
}

