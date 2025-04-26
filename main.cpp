/*    noamgal46@gmail.com    */


#include <iostream>
#include "algorithms.hpp"

using namespace std;
using namespace graph;

int main() {
    Algorithms algorithms;
    int numVertices;
    cout << "enter number of vertices: ";
    cin >> numVertices;
    Graph g(numVertices);
    cout << "enter number of edges: ";
    int numEdges;
    cin >> numEdges;
    cout << "enter the edge in the format: u v weight" << endl;
    for (int i = 0; i < numEdges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    g.printGraph();
    int start;
    cout << "\nenter the start vertex for algorithm: ";
    cin >> start;
    cout << start;
    int choice = 0;
    while (choice != 6){
        cout << "\nSelect an algorithm:\n1. BFS\n2. DFS\n3. Dijkstra\n4. Prim\n5. Kruskal\n6. end program\n" << endl;
        cin >> choice;
        cout << choice << endl;
        Graph ans(1);
        switch (choice) {
            case 1:
                ans = algorithms.bfs(start, g);
                cout << "BFS Tree:\n";
                ans.printGraph();
                break;
            case 2:
                ans = algorithms.dfs(start, g);
                cout << "DFS Tree:\n";
                ans.printGraph();
                break;
            case 3:
                ans = algorithms.dijkstra(start, g);
                cout << "Dijkstra's Shortest Path Tree:\n";
                ans.printGraph();
                break;
            case 4:
                ans = algorithms.prim(g);
                cout << "Prim's MST:\n";
                ans.printGraph();
                break;
            case 5:
                ans = algorithms.kruskal(g);
                cout << "Kruskal's MST:\n";
                ans.printGraph();
                break;
            case 6:
                break;
            default:
                cout << "Invalid choice.\n";
                break;
        }
    }
    return 0;
}
