//
//  main.cpp
//  cs325_project3


#include <iostream>
#include "graph.hpp"
#include "tour.hpp"


int main(int argc, const char* argv[]) {
   
    Graph ourGraph;
    Tour ourTour(&ourGraph);
    std::string filename = "tsp_example_supersimple.txt";
    
    ourGraph.readFile(filename);
    ourGraph.printGraph();
    
    ourTour.nearest_neighbor(ourGraph.getCity(0));
    ourTour.printTour();
    //ourTour.calculateTourDistance();
    
    
    ourTour.two_opt();
    ourTour.printTour();
    
    return 0;
}
