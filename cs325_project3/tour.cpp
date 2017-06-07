//
//  tour.cpp
//  cs325_project3
//
//  Created by bergerMacPro on 6/5/17.
//  Copyright © 2017 bergerMacPro. All rights reserved.
//

#include "tour.hpp"

Tour::Tour(Graph* inputGraph){
    
    tourGraph = inputGraph;
    this->tourDistance = 0;
    
}

void Tour::two_opt() {
    
    bool outerloopBreak = false;
    bool improvementFound = true;
    int count = 0;
    while(count < 6) {
        count++;
        std::cout << "Back to while loop with tour dist: \n" << this->tourDistance;
        improvementFound = false;
        outerloopBreak = false;
        //printf("Another while loop itr..\n");
        for(int i = 1; i < tourGraph->getNumCities() - 2; i++) {
            
            int currentEdgeLength = tourGraph->getDistance(tourGraph->getCity(i), tourGraph->getCity(i + 1));
            int bestSavedDistance = 0;
            int savedDistance;
            int savedEdge;
            
            for(int j = 1; j < tourGraph->getNumCities() - 2; j++) {
                
                if (j != i-1 && j != i && j != i+1) {
                    
                    //printf("Another inner loop...\n");
                    int comparisonEdge = tourGraph->getDistance(tourGraph->getCity(j), tourGraph->getCity(j + 1));
                    
                    int currentEdgeDistances = currentEdgeLength + comparisonEdge;
                    
                    int swapped_edge_one_dist = tourGraph->getDistance(tourGraph->getCity(i), tourGraph->getCity(j));
                    int swapped_edge_two_dist = tourGraph->getDistance(tourGraph->getCity(i + 1), tourGraph->getCity(j + 1));
                    
                    int swappedEdgeDistances = swapped_edge_one_dist + swapped_edge_two_dist;
                    
                    if (swappedEdgeDistances < currentEdgeDistances) {
                        printf("currentEdgeDist: %d, swappedEdgeDistance: %d\n", currentEdgeDistances, swappedEdgeDistances);
                    }
                    
                    savedDistance = currentEdgeDistances - swappedEdgeDistances;

                    
                    if (savedDistance > 0) {
                        
                        //if (savedDistance > bestSavedDistance){
                            //printf("in innner if\n");
                            //bestSavedDistance = savedDistance;
                            //savedEdge = j;
                            std::cout << "Saved Distance of swap: " << savedDistance << " by swapping city: " << i+1 << " with: " << j <<"\n";
                            two_opt_swap(i + 1, j);
                            calculateTourDistance();
                            improvementFound = true;
                            outerloopBreak = true;
                            break;
                        //}
                    }
                }
            }
            
            if(outerloopBreak == true){
                break;
            }
            
//            if (bestSavedDistance > 0) {
//                printf("Best savedDist: %d\n", bestSavedDistance);
//                two_opt_swap(i + 1, savedEdge);
//                tourDistance -= bestSavedDistance;
//                improvementFound = true;
//            }
        }
    }
}

void Tour::two_opt_swap(int firstEdge, int LastEdge) {
    
    std::deque<City*>temp;
            //push into temp deque in reverse order
    for(int i = firstEdge; i <= LastEdge; i++) {
        

        temp.push_front(visitedCities.at(i));
        //printf("pushing: %d\n", visitedCities.at(i)->getId());
    }
    
    int count = 0;
    for(int j = firstEdge; j <= LastEdge; j++) {
        this->visitedCities.at(j) = temp.at(count);
        count++;
    }
    
}

void Tour::nearest_neighbor(City *startCity) {
    
    tourDistance = 0;
    int numCitiesTour = 0;
    City *mostRecent = startCity;
    int mostRecendIdx = mostRecent->getId();
    City *nextCity;
    City *closestCity;
    
    visitedCities.push_back(mostRecent);
    mostRecent->setVisited(true);
    numCitiesTour++;

    
    while(numCitiesTour < tourGraph->getNumCities()) {
     
        int closestDistance = INT_MAX;
        int nextCityDistance;
        
        for(int x = 0; x < tourGraph->getNumCities(); x++) {
            
            nextCity = tourGraph->getCity(x);
            
            if(nextCity->isVisited() == false) {
                
                nextCityDistance = tourGraph->getDistance(mostRecent, nextCity);
                
                if(nextCityDistance < closestDistance){
                    closestDistance = nextCityDistance;
                    closestCity = nextCity;
                }
                
            }
        }
        
        mostRecent = closestCity;
        visitedCities.push_back(mostRecent);
        mostRecent->setVisited(true);
        tourDistance += closestDistance;
        numCitiesTour++;
  
    }

    int finalDistance = tourGraph->getDistance(mostRecent, startCity);
    tourDistance += finalDistance;
}

void Tour::calculateTourDistance(){
    
    if (this->visitedCities.size() > 0) {
        City *currentCity;
        City *nextCity;
        int distance, totalDistance = 0;
        
        for(int x = 0; x < tourGraph->getNumCities() - 1; x++) {
            
            currentCity = this->visitedCities.at(x);
            nextCity = this->visitedCities.at(x + 1);
            
            distance = tourGraph->getDistance(currentCity, nextCity);
            totalDistance += distance;
        }
        
        int finalDistance = tourGraph->getDistance(nextCity, this->visitedCities.at(0));
        totalDistance += finalDistance;
        this->tourDistance = totalDistance;
    }
}

void Tour::printTour(){
    printf("%d\n", tourDistance);
    for(int i = 0; i < visitedCities.size(); i++){
        printf("%d ", visitedCities.at(i)->getId());
    }
}
