#include <string>
#include <iostream>
#include <queue>

#define MAXIMUM_SIZE    100
#define DIRECTIONS  4
#define WALL    '#'
#define DEFINED_PATH    '@'

extern int ROW, COL;
extern int visited[MAXIMUM_SIZE][MAXIMUM_SIZE];
extern std::string maze[MAXIMUM_SIZE];
extern const int dr[DIRECTIONS], dc[DIRECTIONS];

extern void inputMaze();
extern int findShortestPath();
extern void printMaze(int);