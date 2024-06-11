#ifndef MY_MAT_H
#define MY_MAT_H

#include <stdbool.h>


bool isPath(int graph[10][10], int i, int j);

int shortestPath(int graph[10][10], int i, int j);
extern int dist[10][10];
#endif /* FUNC_H */
