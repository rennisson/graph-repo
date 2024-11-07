#ifndef PATHS_H
#define PATHS_H
#include "Graph.h"
#include <vector>
#include <stack>


class Paths {
    private:
        Graph* G;
        vector<bool>marked;
        vector<int> edgeTo;
        int count;
        int s;
        void dfs(Graph& G, int v);

    public:
        Paths(Graph* G, int s);
        bool hasPathTo(int v);
        vector<int> pathTo(int v);
};     

#endif