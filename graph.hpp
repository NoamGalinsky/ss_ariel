/*    noamgal46@gmail.com    */


#pragma once


#include "data_structure.hpp" 
#include <iostream>
using namespace std;
namespace graph {

    class Graph {
    private:
        DynamicList<Edge>* adjacencyList;
        int numVertices;

    public:
        Graph(int numOfVertices);
        Graph(const Graph& other);
        ~Graph();

        Graph& operator=(const Graph& other);


        void addEdge(int u, int v, int weight = 1);
        void removeEdge(int u, int v);
        void printGraph();
        int edgeExist(int u, int v);
        int getNumVertices();
        DynamicList<Edge>* getAdjacencyList();
        Edge findEdge(int origin, int destination);
    };

}

