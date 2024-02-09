#ifndef MY_MAT_H
#define MY_MAT_H
#define TRUE 1
#define FALSE 0
#define INF 999999


void getMatrixValues(int**, int);

int isTherePath(int**, int, int, int);
int dfs(int**, int, int, int, int[]); //helper method


int findShortestPath(int**, int, int, int);
int dijkstra(int** , int, int,int); //helper method


#endif