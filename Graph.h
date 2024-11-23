#ifndef GRAPH_H
#define GRAPH_H
#include <list>
#include<vector>
#include <map>
#include <string>
using namespace std;

class Graph {
    private:
        int V, E;  // number of vertices and edges

    public:
        Graph(int V);
        Graph(string& filename);
        map<int, list<int>> adj;  // adjacency lists
        vector<int> degrees;
        bool hasEdge(int v, int u);
        int vertices();  // return number of vertices
        int edges();  // return number of edges
        void setV(int v);
        void setE(int e);
        void addEdge(int v, int w);  // add edge
        void print();
        void showDegrees();
};

#endif