#include "my_mat.h"
#include <stdbool.h>
#include <string.h>
#define INF 99999 // Assuming no path will have a weight greater than this

bool visited[10];
int dist[10][10];

void DFS(int graph[10][10], int vertex) {
    // Mark the current vertex as visited
    visited[vertex] = true;

    // Explore all adjacent vertices
    for (int i = 0; i < 10; ++i) {
        // If there's an edge to an unvisited vertex, recursively visit it
        if (graph[vertex][i] && !visited[i]) {
            DFS(graph, i);
        }
    }
}

bool isPath(int graph[10][10], int i, int j) {
    // If i is equal to j, return false
    if (i == j) {
        return false;
    }

    // Reset the visited array
    for (int k = 0; k < 10; ++k) {
        visited[k] = false;
    }

    // Perform DFS from vertex i
    DFS(graph, i);

    // Check if vertex j was visited
    return visited[j];
}


int shortestPath(int graph[10][10], int i, int j) {
    
    
    for (int u = 0; u < 10; ++u) {
        for (int v = 0; v < 10; ++v) {
            dist[u][v] = (graph[u][v] == 0 && u != v) ? INF : graph[u][v];
        }
    }

    for (int k = 0; k < 10; ++k) {
        for (int u = 0; u < 10; ++u) {
            for (int v = 0; v < 10; ++v) {
                if (dist[u][k] < INF && dist[k][v] < INF && dist[u][k] + dist[k][v] < dist[u][v]) {
                    dist[u][v] = dist[u][k] + dist[k][v];
                }
            }
        }
    }
     
    return dist[i][j];
}
