//
//  tour.hpp
//  cs325_project3
//

#ifndef tour_hpp
#define tour_hpp

#include <stdio.h>
#include <algorithm>
#include <deque>
#include "graph.hpp"

class Tour {
    
private:
    std::vector<City*>visitedCities;
    int tourDistance;
    Graph* tourGraph;
    
public:
    Tour(Graph*);
    void nearest_neighbor(City*);
    void printTour();
    void two_opt();
    void two_opt_swap(int, int);
    void calculateTourDistance();
    
};


#endif /* tour_hpp */
