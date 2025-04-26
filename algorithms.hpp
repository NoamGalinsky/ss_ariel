/*    noamgal46@gmail.com    */



#pragma once


#include <iostream>
#include "graph.hpp"
using namespace std;

namespace graph {
    class Algorithms{
    public:
        Graph bfs(int start, Graph& graph);
        Graph dfs(int start, Graph& graph);
        Graph dijkstra(int start, Graph& graph);
        Graph prim(Graph& graph);
        Graph kruskal(Graph& graph);
    }; 


}