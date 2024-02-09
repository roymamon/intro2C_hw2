#include <stdio.h>
#include <stdlib.h>
#include "my_mat.h"

void getMatrixValues(int** m, int len) { // len = 10
 
    for (int i = 0; i < len; ++i) {

        for (int j = 0; j < len; ++j) {

            scanf("%d", &m[i][j]);

        }
    }
}

//helper method
int dfs(int** m, int src, int dest, int len, int visited[]) {

    //reference - https://www.prepbytes.com/blog/c-programming/dfs-program-in-c/

    visited[src] = TRUE;

    if (src == dest) {
        return TRUE; 
    }

    for (int i = 0; i < len; ++i) {
        if (m[src][i] && !visited[i]) {
            if (dfs(m, i, dest, len, visited)) {
                return TRUE; 
            }
        }
    }

    return FALSE; 
}

int isTherePath(int** m, int src, int dest, int len) {
    if (src < 0 || src >= len || dest < 0 || dest >= len || src==dest) {
        return FALSE; 
    }

    int visited[len];
    for (int i = 0; i < len; ++i) {
        visited[i] = FALSE;
    }

    return dfs(m, src, dest, len, visited);
}

//helper method
int dijkstra(int** m, int start, int end,int len) {

    //reference - https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/

    int count;
    int _vertD[len];
    int _vertScan[len];
    int min;
    int v2;

    for (int i = 0; i < len; i++)
    {
        _vertD[i] = INF;
        _vertScan[i] = FALSE;
    }

    _vertD[start] = 0;

    for (count = 1; count < len; ++count) {    
        min = INF;

        for (int v = 0; v < len; ++v) {
        
            if (_vertD[v] > min || _vertScan[v])
                continue;

            min = _vertD[v];
            v2 = v;
        }

        _vertScan[v2] = TRUE;

        for (int v = 0; v < len; v++) {
        
            if (_vertD[v2] == INF || _vertScan[v] || !m[v2][v] || (_vertD[v2] + m[v2][v] >= _vertD[v]))
                continue;

            _vertD[v] = _vertD[v2] + m[v2][v];
        }
    }

    return _vertD[end];
}

int findShortestPath(int** m, int i, int j, int len) {
    
    int res = dijkstra(m, i, j, len);

    if(res && res != INF){
        return res;
    }

    res = -1;
    return res;
}