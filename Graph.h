#ifndef GRAPH_H
#define GRAPH_H
#include <list>
#include <map>
#include <string>
using namespace std;

class Graph {
    private:
        int V, E;  // number of vertices and edges

    public:
        map<int, list<int>> adj;  // adjacency lists
        Graph(int V);
        Graph(string& filename);
        int totalV();  // return number of vertices
        int totalE();  // return number of edges
        void setV(int v);
        void setE(int e);
        void addEdge(int v, int w);  // add edge
        void print();
};

#endif