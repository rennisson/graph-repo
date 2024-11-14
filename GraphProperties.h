#ifndef GRAPHPROP_H
#define GRAPHPROP_H
#include "Graph.h"
#include <vector>
#include <queue>

class GraphProperties {
    private:
        Graph* G;
        int diameter, radius, center, source, count;
        vector<bool> marked;
        vector<int> edgeTo;
        vector<int> distTo;
        queue<int> vertices;
        void bfs(Graph& G, int v);
    public:
        GraphProperties(Graph* G);
        bool hasPathTo(int v);
        vector<int> pathTo(int v);
        int d();
        int r();
        int c();
        int distanceTo(int v);
};

#endif