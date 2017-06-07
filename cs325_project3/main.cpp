//
//  main.cpp
//  cs325_project3


#include <iostream>
#include "graph.hpp"
#include "tour.hpp"


int main(int argc, const char* argv[]) {
   
    Graph ourGraph;
    Tour ourTour(&ourGraph);
    std::string filename = "tsp_example_3.txt";
    
    ourGraph.readFile(filename);
    //ourGraph.printGraph();
    
    ourTour.nearest_neighbor(ourGraph.getCity(8));
    //ourTour.printTour();
    //ourTour.calculateTourDistance();
    
    
    printf("Now calculating...\n");
    ourTour.two_opt();
    //ourTour.printTour();
    printf("Final distance found: %d\n", ourTour.getTourDistance());
    
    return 0;
}
