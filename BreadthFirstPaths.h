#ifndef BFPATHS_H
#define BFPATHS_H
#include "Graph.h"
#include <vector>
#include <queue>

class BreadthFirstPaths {
    private:
        Graph* G;
        vector<bool>marked;
        vector<int> edgeTo;
        queue<int> vertices;
        int count;
        int s;
        void bfs(Graph& G, int v);

    public:
        BreadthFirstPaths(Graph* G, int s);
        bool hasPathTo(int v);
        vector<int> pathTo(int v);
};     

#endif