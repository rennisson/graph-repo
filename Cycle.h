#ifndef CYCLE_H
#define CYCLE_H
#include "Graph.h"
#include <vector>

class Cycle {
    private:
        vector<bool> marked;
        bool cycle;
        void dfs(Graph& G, int v, int u);

    public:
        Cycle(Graph* G);
        bool hasCycle();
};

#endif