/*    noamgal46@gmail.com    */




#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <sstream>
#include <string>
#include "graph.hpp"
#include "algorithms.hpp"
#include "data_structure.hpp"

using namespace graph;
using namespace std;

string strPrint(Graph& a){
    streambuf* buffer = cout.rdbuf();
    ostringstream output;
    cout.rdbuf(output.rdbuf());
    a.printGraph();
    cout.rdbuf(buffer);
    return output.str();
}
TEST_CASE("tests for DynamicList"){
    SUBCASE("empty list that removed all elements"){
        DynamicList<int> dl;
        dl.add(1);
        dl.remove();
        CHECK(dl.getNumOfElements() == 0);
        CHECK(dl.isEmpty() == true);
    }
    SUBCASE("get form empty list"){
        DynamicList<int> dl;

    }


    SUBCASE("remove: index dont exist, remove(i), check get"){
        DynamicList<int> dl;
        dl.add(5);
        dl.add(2);
        CHECK(dl.getNumOfElements() == 2);
        CHECK_THROWS_AS(dl.remove(4), std::out_of_range);
        CHECK_THROWS_AS(dl.get(-4), std::out_of_range);
        dl.remove(0);
        int i = dl.get(0);
        CHECK(i == 2);
    }
    SUBCASE("add more then size (10) elements"){
        DynamicList<int> dl;
        for (int i = 0; i < 56; i++){
            dl.add(i);
        }
        CHECK(dl.getNumOfElements() == 56);
        for (int i = 0; i < 10 ; i++){
            dl.remove();
            dl.remove(0);
        }
        CHECK(dl.getNumOfElements() == 36);

    }
}
TEST_CASE("tests for MyQueue"){
    SUBCASE("check empty queue get put and isEmpty"){
        MyQueue mq;
        CHECK(mq.empty() == true);
        mq.put(2);
        mq.put(3);
        int ans = mq.get();
        CHECK(ans == 2);
        CHECK(mq.get() == 3);
        CHECK_THROWS_AS(mq.get(), std::underflow_error);
    }
}
TEST_CASE("tests for MyStack"){
    SUBCASE("check: push, peek, empty and remove"){
        MyStack ms;
        CHECK(ms.empty() == true);
        CHECK_THROWS_AS(ms.remove(), std::underflow_error);
        ms.push(5);
        CHECK(ms.empty() == false);
        ms.peek();
        CHECK(ms.empty() == false);
        for(int i = 0; i < 40; i++){
            ms.push(i);
        }
        CHECK(ms.peek() == 39);
    }
}
TEST_CASE("tests for PriorityQueue"){
    SUBCASE("add difference number and check the extractMin() number"){
        PriorityQueue pq;
        pq.add(Edge(1,3,74));
        pq.add(Edge(5,7,3));
        pq.add(Edge(5,5,34));
        pq.add(Edge(3,8,11));
        pq.add(Edge(4,3,4));
        pq.add(Edge(4,2,1));
        pq.add(Edge(6,6,6));
        pq.add(Edge(4,1,32));
        pq.add(Edge(4,4,7));
        pq.add(Edge(3,3,4));
        pq.add(Edge(7,5,44));
        pq.add(Edge(5,4,15));
        pq.add(Edge(3,4,55));
        CHECK(pq.getSize() == 13);
        CHECK(pq.extractMin().getWeight() == 1);
        CHECK(pq.extractMin().getWeight() == 3);
        CHECK(pq.extractMin().getWeight() == 4);
        CHECK(pq.extractMin().getWeight() == 4);
        CHECK(pq.extractMin().getWeight() == 6);
        CHECK(pq.extractMin().getWeight() == 7);
        CHECK(pq.getSize() == 7);
        pq.add(Edge(4,7,-3));
        CHECK(pq.extractMin().getWeight() == -3);
    }
    SUBCASE("check exeption getSize()"){
        PriorityQueue pq;
        CHECK(pq.empty() == true);
        CHECK_THROWS_AS(pq.extractMin(), std::underflow_error);
        CHECK_THROWS_AS(pq.get(0), std::out_of_range);
        pq.add(Edge(3,3,3));
        CHECK(pq.get(0).getWeight() == 3);
    }
}
TEST_CASE("tests for unionFind"){
    UnionFind uf;
    uf.add(Pair(1,1));
    uf.add(Pair(2,2));
    uf.add(Pair(3,3));
    uf.add(Pair(4,4));
    uf.add(Pair(5,5));
    uf.add(Pair(6,6));
    uf.add(Pair(7,7));
    uf.add(Pair(8,8));
    uf.add(Pair(9,9));
    uf.makeUnion(1,3);
    uf.makeUnion(3,5);
    CHECK(uf.find(3) == 1);
    CHECK(uf.find(5) == 1);
}
TEST_CASE("tests for graph"){
    SUBCASE("check constructor and operator ="){
        CHECK_THROWS_AS(Graph g(0), std::invalid_argument);
        Graph original(3);
        original.addEdge(1,2,3);
        original.addEdge(2,0,7);
        Graph copy(3);
        copy = original;
        CHECK(strPrint(original) == strPrint(copy));
        copy.addEdge(0,1,4);
        CHECK(strPrint(original) != strPrint(copy));
    }
    SUBCASE("chech edgeExist and remove"){
        Graph g1(3);
        g1.addEdge(1,2,3);
        g1.addEdge(2,0,7);
        g1.addEdge(0,1,4);
        Graph g2(3);
        g2.addEdge(1,2,3);
        g2.addEdge(2,0,7);
        CHECK(g1.edgeExist(0, 1) == true);
        g1.removeEdge(1,0);
        CHECK(strPrint(g1) == strPrint(g2));
    }
    SUBCASE("check findEdge()"){
        Graph g1(3);
        g1.addEdge(1,2,3);
        g1.addEdge(2,0,7);
        Edge e1 = g1.findEdge(1, 2);
        Edge e2(1, 2 , 3);
        Edge e3 = g1.findEdge(0, 1);
        Edge e4(-1, -1, -1);
        CHECK_THROWS_AS(g1.findEdge(-1,2), std::out_of_range);
        CHECK(e1 == e2);
        CHECK(e3 == e4);

    }
}
TEST_CASE("tests for bfs"){
    SUBCASE("bfs with 1 vertex graph"){
        Algorithms a;
        Graph g(1);
        Graph ans(1);
        g = a.bfs(0, g);
        CHECK(strPrint(g) == strPrint(ans));
    }
    SUBCASE("bfs to some graph"){
        Algorithms a;
        Graph g(8);
        g.addEdge(1,2);
        g.addEdge(3,5);
        g.addEdge(6,4);
        g.addEdge(1,5);
        g.addEdge(3,4);
        g.addEdge(7,3);
        g.addEdge(7,2);
        g.addEdge(1,4);
        g.addEdge(0,2);
        g.addEdge(0,4);
        g = a.bfs(7, g);
        Graph ans(8);
        ans.addEdge(7, 3);
        ans.addEdge(7, 2);
        ans.addEdge(3, 5);
        ans.addEdge(3, 4);
        ans.addEdge(2, 1);
        ans.addEdge(2, 0);
        ans.addEdge(4, 6);
        CHECK(strPrint(ans) == strPrint(g));
    }
}
TEST_CASE("tests for dfs"){
    SUBCASE("dfs with 1 vertex graph"){
        Algorithms a;
        Graph g(1);
        Graph ans(1);
        g = a.dfs(0, g);
        CHECK(strPrint(g) == strPrint(ans));
    }
    SUBCASE("dfs to some graph"){
        Algorithms a;
        Graph g(8);
        g.addEdge(1,2);
        g.addEdge(3,5);
        g.addEdge(6,4);
        g.addEdge(1,5);
        g.addEdge(3,4);
        g.addEdge(7,3);
        g.addEdge(7,2);
        g.addEdge(1,4);
        g.addEdge(0,2);
        g.addEdge(0,4);
        g = a.dfs(7, g);
        Graph ans(8);
        ans.addEdge(4, 1);
        ans.addEdge(4, 0);
        ans.addEdge(1, 5);
        ans.addEdge(2, 0);
        ans.addEdge(7, 2);
        ans.addEdge(4, 6);
        ans.addEdge(3, 5);
        CHECK(strPrint(ans) == strPrint(g));
    }
}
TEST_CASE("tests for dijkstra"){
    SUBCASE("graph with negative edge"){
        Algorithms a;
        Graph g(5);
        g.addEdge(3,4,7);
        g.addEdge(0,2,23);
        g.addEdge(1,2,-2);
        g.addEdge(2,4,2);
        CHECK_THROWS_AS(a.dijkstra(2,g), std::invalid_argument);
    }
    SUBCASE("graph with one node"){
        Algorithms a;
        Graph g(1);
        Graph ans(1);
        g = a.dijkstra(0, g);
        CHECK(strPrint(g) == strPrint(ans));
    }
    SUBCASE("regular graph"){
        Graph g(6);
        Algorithms a;
        g.addEdge(0,1,4);
        g.addEdge(0,3,2);
        g.addEdge(4,1,4);
        g.addEdge(2,1,3);
        g.addEdge(2,4,1);
        g.addEdge(2,5,3);
        g.addEdge(3,4,3);
        g.addEdge(4,5,5);
        g = a.dijkstra(5, g);
        Graph ans(6);
        ans.addEdge(5,2,3);
        ans.addEdge(4,2,4);
        ans.addEdge(2,1,6);
        ans.addEdge(4,3,7);
        ans.addEdge(3,0,9);
        CHECK(strPrint(g) == strPrint(ans));
    }
    SUBCASE("disconnected graph"){
        Graph g(6);
        Algorithms a;
        g.addEdge(0,2,7);
        g.addEdge(2,3,2);
        g.addEdge(1,2,1);
        g.addEdge(4,5,3);
        g.addEdge(3,1,3);
        g = a.dijkstra(0, g);
        Graph ans(6);
        ans.addEdge(0,2,7);
        ans.addEdge(1,2,8);
        ans.addEdge(2,3,9);
        CHECK(strPrint(ans) == strPrint(g));
    }
    
}
TEST_CASE("tests for prim"){
    SUBCASE("graph with one node"){
        Algorithms a;
        Graph g(1);
        Graph ans(1);
        g = a.prim(g);
        CHECK(strPrint(g) == strPrint(ans));
    }
    SUBCASE("regular graph"){
        Graph g(6);
        Algorithms a;
        g.addEdge(0,2,7);
        g.addEdge(0,4,5);
        g.addEdge(4,1,-2);
        g.addEdge(2,3,2);
        g.addEdge(1,2,1);
        g.addEdge(5,4,2);
        g.addEdge(3,5,3);
        g.addEdge(3,4,4);
        g.addEdge(3,1,3);
        g = a.prim(g);
        Graph ans(6);
        ans.addEdge(5,4,2);
        ans.addEdge(4,0,5);
        ans.addEdge(4,1,-2);
        ans.addEdge(1,2,1);
        ans.addEdge(3,2,2);
        CHECK(strPrint(g) == strPrint(ans));
    }
    SUBCASE("disconnected graph"){
        Graph g(6);
        Algorithms a;
        g.addEdge(0,2,7);
        g.addEdge(2,3,2);
        g.addEdge(1,2,1);
        g.addEdge(3,5,3);
        g.addEdge(3,1,3);
        CHECK_THROWS_AS(a.prim(g), std::invalid_argument);
    }
}
TEST_CASE("tests for kruskal"){
    SUBCASE("graph with one node"){
        Algorithms a;
        Graph g(1);
        Graph ans(1);
        g = a.kruskal(g);
        CHECK(strPrint(g) == strPrint(ans));
    }
    SUBCASE("regular graph"){
        Graph g(6);
        Algorithms a;
        g.addEdge(0,2,7);
        g.addEdge(0,4,5);
        g.addEdge(4,1,-2);
        g.addEdge(2,3,2);
        g.addEdge(1,2,1);
        g.addEdge(5,4,2);
        g.addEdge(3,5,3);
        g.addEdge(3,4,4);
        g.addEdge(3,1,3);
        g = a.kruskal(g);
        Graph ans(6);
        ans.addEdge(5,4,2);
        ans.addEdge(4,0,5);
        ans.addEdge(4,1,-2);
        ans.addEdge(1,2,1);
        ans.addEdge(3,2,2);
        CHECK(strPrint(g) == strPrint(ans));
    }
    SUBCASE("disconnected graph"){
        Graph g(6);
        Algorithms a;
        g.addEdge(0,2,7);
        g.addEdge(2,3,2);
        g.addEdge(1,2,1);
        g.addEdge(3,5,3);
        g.addEdge(3,1,3);
        CHECK_THROWS_AS(a.kruskal(g), std::invalid_argument);
    }
}