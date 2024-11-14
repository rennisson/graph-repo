#ifndef GRAPHPROP_H
#define GRAPHPROP_H
#include "Graph.h"
#include <vector>
#include <queue>

class GraphProperties {
    private:
        Graph* G;
        int diameter, radius, center, source;
        vector<bool> marked;
        vector<int> edgeTo;
        vector<int> distTo;
        queue<int> vertices;
        void bfs(Graph& G, int v);
    public:
        GraphProperties(Graph* G);
        int d();
        int r();
        int c();
        int distanceTo(int v);
};

#endif