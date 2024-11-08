#ifndef PATHS_H
#define PATHS_H
#include "Graph.h"
#include <vector>
#include <queue>

class Paths {
    private:
        Graph* G;
        vector<bool>marked;
        vector<int> edgeTo;
        queue<int> vertices;
        int count;
        int s;
        void dfs(Graph& G, int v);
        void bfs(Graph& G, int v);

    public:
        Paths(Graph* G, int s);
        bool hasPathTo(int v);
        vector<int> pathTo(int v);
};     

#endif