/*    noamgal46@gmail.com    */


#include "graph.hpp"

using namespace graph;

Graph::Graph(int numOfVertices){
    if (numOfVertices < 1){
        throw std::invalid_argument("you put invalid number of vertex");
    }
    numVertices = numOfVertices;
    adjacencyList = new DynamicList<Edge>[numVertices];
}
Graph::Graph(const Graph& other){
    numVertices = other.numVertices;
    adjacencyList = new DynamicList<Edge>[numVertices];
    for (int i = 0 ; i < numVertices; i++){
        for (int j = 0; j < other.adjacencyList[i].getNumOfElements(); j++){
            adjacencyList[i].add(other.adjacencyList[i].get(j));
        }
    }
}

Graph::~Graph() {
    delete[] adjacencyList;
}
Graph& Graph:: operator=(const Graph& other){
    if (this != &other){
        delete[] adjacencyList;
        numVertices = other.numVertices;
        adjacencyList = new DynamicList<Edge>[numVertices];
        for (int i = 0 ; i < numVertices; i++){
            for (int j = 0; j < other.adjacencyList[i].getNumOfElements(); j++){
                adjacencyList[i].add(other.adjacencyList[i].get(j));
            }
        }
    }
    return *this;
}
void Graph::addEdge(int u, int v, int weight) {
    if (edgeExist(u, v) || u == v){
        return;
    }
    if (adjacencyList[u].isEmpty()){
        adjacencyList[u].add(Edge(u, v, weight));
    }
    else{
        int i = 0;
        while(v > adjacencyList[u].get(i).getDestination()){
            i++;
            if (i == adjacencyList[u].getNumOfElements()) {
                break;
            }
        }
        adjacencyList[u].addAt(i, Edge(u, v, weight));
    }
    if (!edgeExist(v , u)){
        addEdge(v , u, weight);
    }
}
int Graph::edgeExist(int u, int v){
    for (int i = 0; i < adjacencyList[u].getNumOfElements(); i++) {
        if (adjacencyList[u].get(i).getDestination() == v) {
            return 1;
        }
    }
    return 0;
}

void Graph::removeEdge(int u, int v) {
    if (adjacencyList[u].isEmpty()) {
        throw std::invalid_argument("the edge is not found");
    }
    int indexToRemove = -1;
    for (int i = 0; i < adjacencyList[u].getNumOfElements(); i++){
        if(adjacencyList[u].get(i).getDestination() == v){
            indexToRemove = i;
            break;
        }
    }
    if (indexToRemove == -1){
        throw std::invalid_argument("the edge is not found");
    }
    adjacencyList[u].remove(indexToRemove);
    if(edgeExist(v, u)){
        removeEdge(v, u);
    }
}
void Graph::printGraph() {
    PriorityQueue pq;
    for (int i = 0; i < numVertices; i++) {
        cout << "Vertex " << i << ": ";
        for(int j = 0; j < adjacencyList[i].getNumOfElements(); j++){
            Edge e = adjacencyList[i].get(j);
            cout << "(" << e.getDestination() << ", " << e.getWeight() << ") ";
        }
        cout << endl;
    }
}   
int Graph::getNumVertices(){
    return numVertices;
}
DynamicList<Edge>* Graph::getAdjacencyList(){
    return adjacencyList;
}
Edge Graph::findEdge(int origin, int destination){
    if ((origin < 0 || origin > numVertices) || (destination < 0 || destination > numVertices)){
        throw out_of_range("Index out of range");
    }
    for(int i = 0; i < adjacencyList[origin].getNumOfElements(); i++){
        if (adjacencyList[origin].get(i).getDestination() == destination){
            return adjacencyList[origin].get(i);
        }
    }
    return Edge(-1, -1, -1);
}




