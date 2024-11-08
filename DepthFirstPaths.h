#ifndef DFPATHS_H
#define DFPATHS_H
#include "Graph.h"
#include <vector>

class DepthFirstPaths {
    private:
        Graph* G;
        vector<bool>marked;
        vector<int> edgeTo;
        int count;
        int s;
        void dfs(Graph& G, int v);

    public:
        DepthFirstPaths(Graph* G, int s);
        bool hasPathTo(int v);
        vector<int> pathTo(int v);
};     

#endif