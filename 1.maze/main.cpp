#include "functions.h"

int main(){
    std::cout << "FIND YOUR PATH\n" << std::endl;

    /*
        TODO
        
        inputMaze() :           input initial maze. the maximum size of the maze is 100x100
                                O is the available section to go. # is the wall that you can't go.
        
        findShortestPath() :    find the shortest path by bfs algorithm.

        printMaze():            print the shortest path. you must categorize the shotest path from others.
    */

	inputMaze();
    int ret = findShortestPath();
    if(!ret){
        std::cout << "CANT FIND YOUR PATH!\n";
        exit(0);
    }
    
    printMaze(ret);

    std::cout << "\nThis is the shortest path of your maze.\n";
    return 0;
}
