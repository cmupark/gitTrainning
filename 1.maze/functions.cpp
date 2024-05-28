#include "functions.h"

std::string maze[MAXIMUM_SIZE];
int visited[MAXIMUM_SIZE][MAXIMUM_SIZE] = {0,};
int ROW = 0, COL = 0;
const int dr[] = {0,0,1,-1};
const int dc[] = {1,-1,0,0};

void inputMaze(){
    std::cin >> ROW >> COL;
    for(int i = 0; i < ROW; i++){
        std::cin >> maze[i];
    }
}

int findShortestPath(){
    std::queue<std::pair<int,int>> q;
    q.push({0,0});

    visited[0][0] = 1;

    bool is_exit = false;

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        int v = visited[r][c];
        q.pop();

        if(r == ROW-1 && c == COL-1){
            is_exit = true;
            break;
        }

        for(int d=0; d<DIRECTIONS; d++){
            int nr = r+dr[d];
            int nc = c+dc[d];
            if(nr<0||nc<0||nr>=ROW||nc>=COL){
                continue;
            }

            char next = maze[nr][nc];
            if(next == WALL || visited[nr][nc] != 0){
                continue;
            }

            q.push({nr, nc});
            visited[nr][nc] = v + 1;
        }
    }
    
    if(!is_exit){
        return false;
    }
    
    int pathLen = visited[ROW-1][COL-1];
    int sv = pathLen;
    int n = ROW-1, c = COL-1;

    maze[n][c] = DEFINED_PATH;

    while(--sv){
        for(int d=0;d<DIRECTIONS;d++){
            int nr = n+dr[d];
            int nc = c+dc[d];
            if(nr<0||nc<0||nr>=ROW||nc>=COL){
                continue;
            }

            if(visited[nr][nc] == sv){
                maze[nr][nc] = DEFINED_PATH;
                n = nr;
                c = nc;
                break;
            }
        }
    }

    return pathLen - 1;
}

void printMaze(int len){
    std::cout << "\n--printMaze--\n";
    std::cout <<"PATH LENGTH: " << len <<"\n";
    for(int i = 0; i < ROW; i++){
        std::cout << maze[i] <<"\n";
    }
    std::cout << "\n";
}