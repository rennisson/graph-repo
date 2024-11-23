#ifndef CYCLE_H
#define CYCLE_H
#include "Graph.h"
#include <vector>
#include <map>

class Cycle {
    private:
        Graph* G;
        vector<bool> marked;
        map<int, vector<bool>> edgesVisited;
        bool cycle;
        bool eulerianCycle;
        void dfs(Graph& G, int v, int u);
        void dfsEulerian(Graph&, int v, int s);

    public:
        Cycle(Graph* G);
        bool hasCycle();
        bool hasEulerCycle();
};

#endif